#include "Workersexception.h"

workersexception::workersexception(std::string name, std::string msg) : exception(msg) {
	this->name = name;
}

const std::string& workersexception::get_name() const{
	return name;
}
