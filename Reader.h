#pragma once
#include <string>
#include <fstream>
#include <map>
#include "Worker.h"
#include "Workersfactory.h"
#include <memory>

class reader {
public:
	reader(std::string file_name);
	void read();
	const std::map <int, std::shared_ptr<worker>>& get_commands();
	const std::vector<int>& get_quene();
private:
	std::string file_name;
	std::ifstream file;
	std::map <int, std::shared_ptr<worker>> commands;
	std::vector<int> quene;
	void open();
	void push_word(std::string& word, int& number_word, int& number, int& number_line, std::string& name, std::vector<std::string>& args);
	void push_last_line(int& number_word, int& number_line, std::string& word);
	void parse(std::string line, int number_line, int& flag_csed);
	void parse_last_line(std::string line, int number_line);
	void parse_body(std::string line, int& flag_csed, int number_line);
};

