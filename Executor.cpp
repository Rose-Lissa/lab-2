#include "Executor.h"
#include "Workersexception.h"
#include "Executorexception.h"

executor::executor(const std::map<int, std::shared_ptr<worker>>& commands, const std::vector<int>& quene) {
	this->commands = commands;
	this->quene = quene;
}

void executor::execute() {
	try {
		std::vector<std::string> text;
		for (int i : quene) {
			commands[i]->make(text);
		}
	}
	catch (const workersexception& ex) {
		throw executorexception("Worker execute error. " + ex.get_name()+ ". " + std::string(ex.what()));
	}
}
