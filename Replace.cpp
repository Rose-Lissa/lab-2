#include "Replace.h"
#include "Workersexception.h"

replace::replace(const std::vector<std::string>& args) {
	if (args.size() != 2) {
		throw workersexception("Replace", "Wrong number of arguments.");
	}
	this->word_1 = args[0];
	this->word_2 = args[1];
}

void replace::make(std::vector<std::string>& text) {
	if (text.empty()) {
		throw workersexception("Replace", "The text is empty.");
	}
	if (word_1 == word_2) {
		return;
	}
	auto it = text.begin();
	while (it != text.end()) {
		while (it->find(word_1) != std::string::npos) {
			int pos = it->find(word_1);
			it->replace(pos, word_2.size(), word_2);
		}
		it++;
	}
}
