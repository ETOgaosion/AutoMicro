#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <utility>
#include <cassert>
#include <sysexits.h>

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>

#include "utils.h"
#include "SequentialFileWriter.h"
#include "FileReaderIntoStream.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;

using File::FileId;
using File::FileContent;
using File::FileTransfer;


class FileTransferClient {
public:
    FileTransferClient(std::shared_ptr<Channel> channel)
        : m_stub(FileTransfer::NewStub(channel))
    {
        
    }

    bool Upload(std::int32_t id, const std::string& filename)
    {
        FileId returnedId;
        ClientContext context;

        std::unique_ptr<ClientWriter<FileContent>> writer(m_stub->Upload(&context, &returnedId));
        try {
            FileReaderIntoStream< ClientWriter<FileContent> > reader(filename, id, *writer);

            // TODO: Make the chunk size configurable
            const size_t chunk_size = 1UL << 20;    // Hardcoded to 1MB, which seems to be recommended from experience.
            reader.Read(chunk_size);
        }
        catch (const std::exception& ex) {
            std::cerr << "Failed to send the file " << filename << ": " << ex.what() << std::endl;
            // FIXME: Indicate to the server that something went wrong and that the trasfer should be aborted.
        }
    
        writer->WritesDone();
        Status status = writer->Finish();
        if (!status.ok()) {
            std::cerr << "File Exchange rpc failed: " << status.error_message() << std::endl;
            return false;
        }
        else {
            std::cout << "Finished sending file with id " << returnedId.id() << std::endl;
        }

        return true;
    }

    bool DownloadContent(std::int32_t id)
    {
        FileId requestedId;
        FileContent contentPart;
        ClientContext context;
        SequentialFileWriter writer;
        std::string filename;

        requestedId.set_id(id);
        std::unique_ptr<ClientReader<FileContent> > reader(m_stub->Download(&context, requestedId));
        try {
            while (reader->Read(&contentPart)) {
                assert(contentPart.id() == id);
                filename = contentPart.name();
                writer.OpenIfNecessary(contentPart.name());
                auto* const data = contentPart.mutable_content();
                writer.Write(*data);
            };
            const auto status = reader->Finish();
            if (! status.ok()) {
                std::cerr << "Failed to get the file ";
                if (! filename.empty()) {
                    std::cerr << filename << ' ';
                }
                std::cerr << "with id " << id << ": " << status.error_message() << std::endl;
                return false;
            }
            std::cout << "Finished receiving the file "  << filename << " id: " << id << std::endl;
        }
        catch (const std::system_error& ex) {
            std::cerr << "Failed to receive " << filename << ": " << ex.what();
            return false;
        }

        return true;
    }
private:
    std::unique_ptr<FileTransfer::Stub> m_stub;
};

void usage [[ noreturn ]] (const char* prog_name)
{
    std::cerr << "USAGE: " << prog_name << " [put|get] num_id [filename]" << std::endl;
    std::exit(EX_USAGE);
}
