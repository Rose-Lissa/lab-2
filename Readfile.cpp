#include "Readfile.h"
#include "Workersexception.h"

readfile::readfile(const std::vector<std::string>& args) {
	if (args.size() != 1) {
		throw workersexception("Readfile", "Wrong number of arguments.");
	}
	this->file_name = args[0];
}

void readfile::make(std::vector<std::string>& text) {
	if (!text.empty()) {
		throw workersexception("Readfile", "The text is not empty.");
	}
	file.open(file_name);
	if (!file.is_open()) {
		throw workersexception("Readfile", "File didn't open.");
	}
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		text.push_back(line);
	}
	file.close();
}
