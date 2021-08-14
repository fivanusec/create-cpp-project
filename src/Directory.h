#pragma once

#include <bits/stdc++.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>

enum class ExecuteResult
{
    EXECUTE_SUCCESS,
    EXECUTE_FAILURE
};

class Directory
{
private:
    std::string name;

public:
    Directory(std::string name);
    ExecuteResult create_project(std::string path);
    ExecuteResult create_src(std::string path);
};