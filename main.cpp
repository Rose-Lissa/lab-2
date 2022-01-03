#include <iostream>
#include "Executor.h"
#include "Reader.h"
#include "Readerexception.h"
#include "Executorexception.h"

int main() {
	try {
		std::string file_name = "Workflow.txt";
		reader workflow_reader(file_name);
		workflow_reader.read();
		executor workflow_executor(workflow_reader.get_commands(), workflow_reader.get_quene());
		workflow_executor.execute();
	}
	catch (const readerexception& ex) {
		std::cout << "Parse error: in line " << ex.get_number_line() << ". " << ex.what() << std::endl;
	}
	catch (const executorexception& ex) {
		std::cout << "Execute error: " << ex.what() << std::endl;
	}
	catch (const exception& ex) {
		std::cout << "Error: " << ex.what() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << "Unknown exception: " << ex.what() << std::endl;
	}
	return 0;
}
