#include <iostream>

#include "modules\Controller\ProgramController.h"

int main(int __argc, char *__argv[])
{
	std::string command;
	if (__argc > 1)
	{
		command = std::string(__argv[1]);
	}
	if (__argc == 1)
	{
		ProgramController::ListAvailableCommand();
	}
	else if (__argc == 2)
	{
		if (command.compare("help")==0)
		{
			ProgramController::ListAvailableCommand();
		} 
	}
	else if (__argc == 3)
	{
		std::string projectName = std::string(__argv[2]);
		if (command.compare("create")==0)
		{
			ProgramController::CreateProject(projectName);
		}
		else if (command.compare("list")==0)
		{
			ProgramController::ListProject(projectName);
		}
	}
	return 0;
}