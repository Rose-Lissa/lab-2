#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Worker.h"

class dump : public worker {
public:
	dump(const std::vector<std::string>& args);
    void make(std::vector<std::string>& text) override;
private:
	std::string file_name;
	std::ofstream file;
};

