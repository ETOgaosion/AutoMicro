#pragma once

#include <cstdint>
#include <string>

#include "FileTransfer.grpc.pb.h"

File::FileId MakeFileId(std::int32_t id);
File::FileContent MakeFileContent(std::int32_t id, std::string name, const void* data, size_t data_len);
