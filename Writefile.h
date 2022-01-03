#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Worker.h"

class writefile : public worker {
public:
	writefile(const std::vector<std::string>& args);
	void make(std::vector<std::string>& text) override;
private:
	std::string file_name;
	std::ofstream file;
};

