#pragma once
#include "Worker.h"
#include <string>
#include <vector>
#include <algorithm>

class sort : public worker {
public:
	sort(const std::vector<std::string>& args);
    void make(std::vector<std::string>& text) override;
};

