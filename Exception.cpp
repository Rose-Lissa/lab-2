#include "Exception.h"

exception::exception(std::string msg) {
	this->msg = msg;
}

const char* exception::what() const noexcept {
	return msg.c_str();
}