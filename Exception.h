#pragma once
#include <exception>
#include <string>

class exception : std::exception {
public:
	exception(std::string msg);
	const char* what() const noexcept override;
private:
	std::string msg;
};

