#include "Reader.h"
#include "Readerexception.h"

reader::reader(std::string file_name) {
	this->file_name = file_name;
	open();
}

void reader::open() {
	file.open(file_name);
	if (!file.is_open()) {
		throw readerexception("File didn't open.", 0);
	}
}

void reader::push_word(std::string& word, int& number_word, int& number, int& number_line, std::string& name, std::vector<std::string>& args){
	number_word++;
	if (number_word == 1) {
		try {
			number = stoi(word);
		}
		catch (std::invalid_argument e) {
			throw readerexception("There should be a number.", number_line);
		}
	}
	else if (number_word == 2) {
		if (word != "=") {
			throw readerexception("There should be '='.", number_line);
		}
	}
	else if (number_word == 3) {
		name = word;
	}
	else {
		args.push_back(word);
	}
	word.clear();
}

void reader::push_last_line(int& number_word, int& number_line, std::string& word) {
	number_word++;
	if ((number_word % 2) == 1) {
		try {
			quene.push_back(stoi(word));
		}
		catch (std::invalid_argument e) {
			throw readerexception("There should be a number.", number_line);
		}
	}
	else {
		if (word != "->") {
			throw readerexception("There should be '->'.", number_line);
		}
	}
	word.clear();
}

void reader::read() {
	int number_line = 0;
	int flag_csed = 0;
	while (!file.eof()) {
		std::string line;
		std::getline(file, line);
		number_line++;
		parse(line, number_line, flag_csed);
	}
}

const std::map<int, std::shared_ptr<worker>>& reader::get_commands() {
	return commands;
}

const std::vector<int>& reader::get_quene() {
	return quene;
}

void reader::parse(std::string line, int number_line, int& flag_csed) {
	if (flag_csed == 1) {
		parse_last_line(line, number_line);
	}
	else if (number_line == 1) {
		if (line != "desc") {
			throw readerexception("The line should only contain 'desc'.", number_line);
		}
	}
	else {
		parse_body(line, flag_csed, number_line);
	}
}

void reader::parse_last_line(std::string line, int number_line) {
	int number_word = 0;
	std::string word;
	for (int i = 0; i < line.size(); i++) {
		if (line[i] != ' ') {
			word.push_back(line[i]);
		}
		else {
			push_last_line(number_word, number_line, word);
		}
	}
	if (!word.empty()) {
		push_last_line(number_word, number_line, word);
	}
}

void reader::parse_body(std::string line, int& flag_csed, int number_line) {
	if (line == "csed") {
		flag_csed = 1;
	}
	else {
		int number_word = 0;
		std::string word;
		int number;
		std::string name;
		std::vector<std::string> args;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] != ' ') {
				word.push_back(line[i]);
			}
			else {
				push_word(word, number_word, number, number_line, name, args);
			}
		}
		if (!word.empty()) {
			push_word(word, number_word, number, number_line, name, args);
		}
		if (commands.find(number) == commands.end()) {
			commands[number] = std::shared_ptr<worker>(workersfactory::create(name, args));
		}
		else {
			throw readerexception("This number has already been used.", number_line);
		}
	}
}

