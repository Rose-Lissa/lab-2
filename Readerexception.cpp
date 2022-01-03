#include "Readerexception.h"

readerexception::readerexception(std::string msg, int number_line) : exception(msg) {
	this->number_line = number_line;
}

int readerexception::get_number_line() const {
	return number_line;
}
