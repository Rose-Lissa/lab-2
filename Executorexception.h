#pragma once
#include "Exception.h"
class executorexception : public exception {
public:
	executorexception(std::string msg);
};

