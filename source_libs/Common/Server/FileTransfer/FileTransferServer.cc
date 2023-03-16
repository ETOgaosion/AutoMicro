#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <map>
#include <cstdint>
#include <stdexcept>

#include <grpc/grpc.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>

#include "SequentialFileWriter.h"
#include "FileReaderIntoStream.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using grpc::StatusCode;

using File::FileId;
using File::FileContent;
using File::FileTransfer;

class FileTransferImpl final : public FileTransfer::Service {
private:
    typedef google::protobuf::int32 FileIdKey;

public:
    FileTransferImpl() = default;

    Status Upload(
      ServerContext* context, ServerReader<FileContent>* reader,
      FileId* summary) override
    {
        FileContent contentPart;
        SequentialFileWriter writer;
        while (reader->Read(&contentPart)) {
            try {
                // FIXME: Do something reasonable if a file with a different name but the same ID already exists
                writer.OpenIfNecessary(contentPart.name());
                auto* const data = contentPart.mutable_content();
                writer.Write(*data);

                summary->set_id(contentPart.id());
                // FIXME: Protect from concurrent access by multiple threads
                m_FileIdToName[contentPart.id()] = contentPart.name();
            }
            catch (const std::system_error& ex) {
                const auto status_code = writer.NoSpaceLeft() ? StatusCode::RESOURCE_EXHAUSTED : StatusCode::ABORTED;
                return Status(status_code, ex.what());
            }
        }

        return Status::OK;
    }

    Status Download(
        ServerContext* context,
        const FileId* request,
        ServerWriter<FileContent>* writer) override
    {
        const auto id = request->id();
        const auto it = m_FileIdToName.find(id);
        if (m_FileIdToName.end() == it) {
            return Status(grpc::StatusCode::NOT_FOUND, "No file with the id " + std::to_string(id));
        }
        const std::string filename = it->second;

        try {
            FileReaderIntoStream< ServerWriter<FileContent> > reader(filename, id, *writer);

            // TODO: Make the chunk size configurable
            const size_t chunk_size = 1UL << 20;    // Hardcoded to 1MB, which seems to be recommended from experience.
            reader.Read(chunk_size);
        }
        catch (const std::exception& ex) {
            std::ostringstream sts;
            sts << "Error sending the file " << filename << ": " << ex.what();
            std::cerr << sts.str() << std::endl;
            return Status(StatusCode::ABORTED, sts.str());
        }

        return Status::OK;
    }

private:
    std::map<FileIdKey, std::string> m_FileIdToName;
};