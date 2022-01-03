#pragma once
#include "Exception.h"
class readerexception : public exception {
public:
	readerexception(std::string msg, int number_line);
	int get_number_line() const;
private:
	int number_line;
};

