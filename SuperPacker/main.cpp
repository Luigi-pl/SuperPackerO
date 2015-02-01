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
		if (command.compare("create")==0)
		{
			ProgramController::CreateProject(std::string(__argv[2]));
		}
	}
	return 0;
}