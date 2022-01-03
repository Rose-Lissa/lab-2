#pragma once
#include "Exception.h"
class workersexception : public exception {
public:
	workersexception(std::string name, std::string msg);
	const std::string& get_name() const;
private:
	std::string name;
};

