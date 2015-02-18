#include <iostream>

#include "modules\Controller\ProgramController.h"

int main(int __argc, char *__argv[])
{
	std::string command;
	std::string firstParameter;
	std::string secondParameter;
	if (__argc > 1)
	{
		command = std::string(__argv[1]);
	}
	if (__argc > 2)
	{
		firstParameter = std::string(__argv[2]);
	}
	if (__argc > 3)
	{
		secondParameter = std::string(__argv[3]);
	}

	switch (__argc)
	{
	case 1:
		ProgramController::ListAvailableCommand();
		break;
	case 2:
		if (command.compare("help") == 0)
		{
			ProgramController::ListAvailableCommand();
		}
		break;
	case 3:
		if (command.compare("create") == 0)
		{
			ProgramController::CreateProject(firstParameter);
		}
		else if (command.compare("list") == 0)
		{
			ProgramController::ListProject(firstParameter);
		}
		else if (command.compare("remove") == 0)
		{
			ProgramController::RemoveProject(firstParameter);
		}
		else if (command.compare("remove-archiver") == 0)
		{
			ProgramController::RemoveArchiver(firstParameter);
		}
		else if (command.compare("execute") == 0)
		{
			ProgramController::ExecuteProject(firstParameter);
		}
		break;
	case 4:
		if (command.compare("add-file") == 0)
		{
			ProgramController::AddFileToProject(firstParameter, secondParameter);
		}
		else if (command.compare("remove-file") == 0)
		{
			ProgramController::RemoveFileFromProject(firstParameter, secondParameter);
		}
		else if (command.compare("rename") == 0)
		{
			ProgramController::ChangeProjectName(firstParameter, secondParameter);
		}
		else if (command.compare("add-archiver") == 0)
		{
			ProgramController::AddArchiver(firstParameter, secondParameter);
		}
		else if (command.compare("change-archiver") == 0)
		{
			ProgramController::ChangeArchiver(firstParameter, secondParameter);
		}
		break;
	default:
		break;
	}
	return 0;
}