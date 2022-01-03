#include "Workersfactory.h"
#include "Dump.h"
#include "Grep.h"
#include "Readfile.h"
#include "Replace.h"
#include "Writefile.h"
#include "Sort.h"
#include "Workersexception.h"
#include "Factoryexception.h"

worker* workersfactory::create(const std::string& name, const std::vector<std::string>& args) {
	try {
		if (name == "dump") {
			return new dump(args);
		}
		else if (name == "grep") {
			return new grep(args);
		}
		else if (name == "readfile") {
			return new readfile(args);
		}
		else if (name == "replace") {
			return new replace(args);
		}
		else if (name == "writefile") {
			return new writefile(args);
		}
		else if (name == "sort") {
			return new sort(args);
		}
		else {
			throw factoryexception("Name: " + name + " does not exist.");
		}
	}
	catch (const workersexception& ex) {
		throw factoryexception("Worker creation error. " + ex.get_name() + ". " + std::string(ex.what()));
	}
	return nullptr;
}
