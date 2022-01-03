#include "Grep.h"
#include "Workersexception.h"

grep::grep(const std::vector<std::string>& args) {
	if (args.size() != 1) {
		throw workersexception("Grep", "Wrong number of arguments.");
	}
	this->word = args[0];
}

void grep::make(std::vector<std::string>& text) {
	if (text.empty()) {
		throw workersexception("Grep", "The text is empty.");
	}
	auto it = text.begin();
	while (it != text.end()) {
		if (it->find(word) == std::string::npos) {
			it = text.erase(it);
		}
		else {
			it++;
		}
	}
}
