#include "Files.h"

bool is_file_exist(std::string &str)
{
    namespace fs = std::experimental::filesystem;
    fs::path p(str);
    return fs::exists(p);
}

Files::Files(std::string name)
{
    this->name = name;
}

FileCreationResult Files::create_cmake_files(std::string path)
{
    std::string cmake_main = path + "/" + name + "/CMakeLists.txt";
    std::string cmake_src = path + "/" + name + "/src" + "/CMakeLists.txt";

    if (!is_file_exist(cmake_main) && !is_file_exist(cmake_src))
    {

        std::ofstream ost{cmake_main, std::ios::app};
        if (!ost)
        {
            std::cerr << "Error: " << strerror(errno) << std::endl;
            return FileCreationResult::CREATION_FAILURE;
        }

        ost << "\
cmake_minimum_required(VERSION 3.16) \n\
project("
            << name << ") \n\
\
add_subdirectory(src)\n\
set(CMAKE_CXX_STANDARD 14)\n\
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})\n\
set(CMAKE_BUILD_TYPE Debug) \n";

        ost.close();

        std::ofstream ost_src{cmake_src, std::ios::app};
        if (!ost_src)
        {
            std::cerr << "Error: " << strerror(errno) << std::endl;
            return FileCreationResult::CREATION_FAILURE;
        }

        ost_src << "\
cmake_minimum_required(VERSION 3.16)\n\
\
project(src VERSION 1) \n\
set(CMAKE_CXX_STANDARD 14)\n\
add_executable("
                << name << " )\n\
include_directories(${CMAKE_SOURCE_DIR})\n\
set(CMAKE_BUILD_TYPE Debug)\n\
    ";

        ost_src.close();

        return FileCreationResult::CREATION_SUCCESS;
    }
    return FileCreationResult::FILE_EXIST;
}

void Files::create_main() {}

FileCreationResult Files::create_files(std::string path)
{
    std::string build = path + "/" + name + "/build.sh";
    std::string start = path + "/" + name + "/start.sh";
    if (!is_file_exist(build) && !is_file_exist(start))
    {
        std::ofstream build_stream{build, std::ios::app};
        std::ofstream start_stream{start, std::ios::app};

        if (!build_stream)
        {
            std::cerr << "Error: " << strerror(errno) << std::endl;
            return FileCreationResult::CREATION_FAILURE;
        }

        build_stream << "RED=\"\e[31m\" \n\
GREEN=\"\\e[32m\" \n \
ENDCOLOR=\"\\e[0m\" \n";

        build_stream << "\n";
        build_stream << "cmake -B build \n\
cd build \n\
make \n";
        build_stream << "\n";
        build_stream << "if [ $? -eq 0 ]; then \n \
echo -e \"${GREEN} "
                     << name << " build successfully${ENDCOLOR}\" \n \
else \n \
echo -e \"${RED}There was a problem while building "
                     << name << " ${ENDCOLOR}\" \n \
fi";

        if (!start_stream)
        {
            std::cerr << "Error: " << strerror(errno) << std::endl;
            return FileCreationResult::CREATION_FAILURE;
        }

        start_stream << "./build/src/" << name << " $1";

        start_stream.close();
        build_stream.close();
        return FileCreationResult::CREATION_SUCCESS;
    }
    return FileCreationResult::FILE_EXIST;
}