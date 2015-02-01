#include <iostream>

#include "modules\Controller\ProgramController.h"

int main(int __argc, char *__argv[])
{
	if (__argc == 1)
	{
		ProgramController::listAvailableCommand();
	}
	else if (__argc > 1)
	{
		std::string command(__argv[1]);
		if (command.compare("help"))
		{
			ProgramController::listAvailableCommand();
		}
	}
	return 0;
}