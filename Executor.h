#pragma once
#include <map>
#include <vector>
#include <memory>
#include "Worker.h"

class executor {
public:
	executor(const std::map <int, std::shared_ptr<worker>>& commands, const std::vector<int>& quene);
	void execute();
private:
	std::map <int, std::shared_ptr<worker>> commands;
	std::vector<int> quene;
};

