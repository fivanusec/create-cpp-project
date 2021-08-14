#include "Directory.h"

const char *convert_c_path_src(std::string path, std::string name)
{
    std::string full_path = path + "/" + name + "/src";
    char *cstr = new char[full_path.length() + 1];
    std::strcpy(cstr, full_path.c_str());
    return cstr;
}

const char *convert_c_path(std::string path, std::string name)
{
    std::string full_path = path + "/" + name;
    char *cstr = new char[full_path.length() + 1];
    std::strcpy(cstr, full_path.c_str());
    return cstr;
}

Directory::Directory(std::string name)
{
    this->name = name;
}

ExecuteResult Directory::create_src(std::string path)
{
    const char *c_path = convert_c_path_src(path, name);
    if (mkdir(c_path, 0777) == -1)
    {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return ExecuteResult::EXECUTE_FAILURE;
    }
    return ExecuteResult::EXECUTE_SUCCESS;
}

ExecuteResult Directory::create_project(std::string path)
{
    const char *c_path = convert_c_path(path, name);
    if (mkdir(c_path, 0777) == -1)
    {
        std::cerr << "Error: " << strerror(errno) << std::endl;
        return ExecuteResult::EXECUTE_FAILURE;
    }
    return ExecuteResult::EXECUTE_SUCCESS;
}