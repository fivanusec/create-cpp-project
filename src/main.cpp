#include <iostream>
#include <string>
#include <filesystem>
#include <unistd.h>

#include "Directory.h"
#include "Files.h"

int main(int argc, char *argv[])
{
    const char *location = get_current_dir_name();
    Directory dir = Directory(std::string(argv[1]));
    Files files = Files(std::string(argv[1]));

    if (dir.create_project(std::string(location)) == ExecuteResult::EXECUTE_SUCCESS)
    {
        std::cout << "Project " << argv[1] << " created" << std::endl;
    }

    if (dir.create_src(std::string(location)) == ExecuteResult::EXECUTE_SUCCESS)
    {
        std::cout << "Project " << argv[1] << " src/ created" << std::endl;
    }

    if (files.create_files(std::string(location)) == FileCreationResult::CREATION_SUCCESS)
    {
        std::cout << "File build.sh and start.sh created" << std::endl;
    }
    else if (files.create_files(std::string(location)) == FileCreationResult::FILE_EXIST)
    {
        std::cout << "File build.sh and start.sh already exists!" << std::endl;
    }

    if (files.create_cmake_files(std::string(location)) == FileCreationResult::CREATION_SUCCESS)
    {
        std::cout << "CMake files created" << std::endl;
    }
    else if (files.create_cmake_files(std::string(location)) == FileCreationResult::FILE_EXIST)
    {
        std::cout << "CMake files already exists" << std::endl;
    }

    if (system("git init") == -1)
    {
        std::cout << "Problem with git" << std::endl;
    }

    std::cout
        << "Project " << argv[1] << " created successfully!" << std::endl;
}