#pragma once
#include <string>
#include <vector>
#include "Worker.h"
class grep : public worker {
public:
	grep(const std::vector<std::string>& args);
	virtual void make(std::vector<std::string>& text) override;
private:
	std::string word;
};

