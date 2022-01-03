#pragma once
#include <string>
#include <vector>
#include "Worker.h"
class replace : public worker {
public:
    replace(const std::vector<std::string>& args);
    void make(std::vector<std::string>& text) override;
private:
    std::string word_1;
    std::string word_2;
};

