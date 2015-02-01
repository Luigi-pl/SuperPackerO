#pragma once
#include <iostream>
#include <string>
/*Class responsible for controlling console's command*/
class ProgramController
{
public:
	/*Implementation of console command:
	help, which shows list of available commands
	*/
	static void ListAvailableCommand();
	/*Implementation of console command:
	create %p - create project (%p) settings file
	*/
	static void CreateProject(std::string);
};

