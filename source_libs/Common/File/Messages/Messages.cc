#include "Messages.h"

File::FileId MakeFileId(std::int32_t id)
{
    File::FileId fid;
    fid.set_id(id);
    return fid;
}

File::FileContent MakeFileContent(std::int32_t id, std::string name, const void* data, size_t data_len)
{
    File::FileContent fc;
    fc.set_id(id);
    fc.set_name(std::move(name));
    fc.set_content(data, data_len);
    return fc;
}