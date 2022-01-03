#include "Sort.h"
#include "Workersexception.h"

sort::sort(const std::vector<std::string>& args) {
	if (args.size() != 0) {
		throw workersexception("Sort", "Wrong number of arguments.");
	}
}

void sort::make(std::vector<std::string>& text) {
	if (text.empty()) {
		throw workersexception("Sort", "The text is empty.");
	}
	std::sort(text.begin(), text.end());
}
