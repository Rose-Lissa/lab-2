#pragma once
#include <string>
#include <vector>
#include "Worker.h"

class workersfactory {
public:
	static worker* create(const std::string& name, const std::vector<std::string>& args);
};

