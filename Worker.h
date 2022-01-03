#pragma once
#include <string>
#include <vector>

class worker {
public:
	virtual void make(std::vector<std::string>& text) = 0;
};

