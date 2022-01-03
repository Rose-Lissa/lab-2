#pragma once
#include "Exception.h"
class factoryexception : public exception {
public:
	factoryexception(std::string msg);
};

