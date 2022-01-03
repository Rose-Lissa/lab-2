#include "Writefile.h"
#include "Workersexception.h"

writefile::writefile(const std::vector<std::string>& args) {
	if (args.size() != 1) {
		throw workersexception("Writefile", "Wrong number of arguments.");
	}
	this->file_name = args[0];
}

void writefile::make(std::vector<std::string>& text) {
	if (text.empty()) {
		throw workersexception("Writefile", "The text is empty.");
	}
	file.open(file_name);
	if (!file.is_open()) {
		throw workersexception("Writefile", "File didn't open.");
	}
	for (std::string str : text) {
		file << str << std::endl;
	}
	text.clear();
	file.close();
}
