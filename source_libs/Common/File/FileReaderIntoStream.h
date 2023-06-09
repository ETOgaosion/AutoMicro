#pragma once

#include <cstdint>
#include <string>
#include "sys/errno.h"

#include "SequentialFileReader.h"
#include "Messages.h"
#include "utils.h"

template <class StreamWriter>
class FileReaderIntoStream : public SequentialFileReader {
public:
    FileReaderIntoStream(const std::string& filename, std::int32_t id, StreamWriter& writer)
        : SequentialFileReader(filename)
        , m_writer(writer)
        , m_id(id)
    {
    }

    using SequentialFileReader::SequentialFileReader;
    using SequentialFileReader::operator=;

protected:
    virtual void OnChunkAvailable(const void* data, size_t size) override
    {
        const std::string remote_filename = extract_basename(DownloadPath());
        auto fc = MakeFileContent(m_id, remote_filename, data, size);
        if (! m_writer.Write(fc)) {
            raise_from_system_error_code("The server aborted the connection.", ECONNRESET);
        }
    }

private:
    StreamWriter& m_writer;
    std::uint32_t m_id;
};
