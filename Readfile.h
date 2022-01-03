#pragma once
#include "Worker.h"
#include <string>
#include <vector>
#include <fstream>

class readfile : public worker {
public:
    readfile(const std::vector<std::string>& args);
    void make(std::vector<std::string>& text) override;
private:
    std::string file_name;
    std::ifstream file;
};

