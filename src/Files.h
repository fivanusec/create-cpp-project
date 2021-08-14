#pragma once
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <experimental/filesystem>

enum class FileCreationResult
{
    CREATION_SUCCESS,
    CREATION_FAILURE,
    FILE_EXIST
};

class Files
{
private:
    std::string name;

public:
    Files(std::string name);
    FileCreationResult create_files(std::string path);
    FileCreationResult create_cmake_files(std::string path);
    void create_main();
};