#include "Dump.h"
#include "Workersexception.h"

dump::dump(const std::vector<std::string>& args) {
	if (args.size() != 1) {
		throw workersexception("Dump", "Wrong number of arguments.");
	}
	this->file_name = args[0];
}

void dump::make(std::vector<std::string>& text) {
	if (text.empty()) {
		throw workersexception("Dump", "The text is empty.");
	}
	file.open(file_name);
	if (!file.is_open()) {
		throw workersexception("Dump", "File didn't open.");
	}
	for (std::string str : text) {
		file << str << std::endl;
	}
	file.close();
}
