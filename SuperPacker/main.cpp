#include <iostream>

#include "modules\Controller\ProgramController.h"

int main(int __argc, char *__argv[])
{
	std::string command;
	std::string projectName;
	if (__argc > 1)
	{
		command = std::string(__argv[1]);
	}
	if (__argc > 2)
	{
		projectName = std::string(__argv[2]);
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
			ProgramController::CreateProject(projectName);
		}
		else if (command.compare("list") == 0)
		{
			ProgramController::ListProject(projectName);
		}
		else if (command.compare("remove") == 0)
		{
			ProgramController::RemoveProject(projectName);
		}
		break;
	case 4:
		if (command.compare("add-file") == 0)
		{
			ProgramController::AddFileToProject(projectName, std::string(__argv[3]));
		}
		else if (command.compare("remove-file") == 0)
		{
			ProgramController::RemoveFileFromProject(projectName, std::string(__argv[3]));
		}
		else if (command.compare("rename") == 0)
		{
			ProgramController::ChangeProjectName(projectName, std::string(__argv[3]));
		}
		break;
	default:
		break;
	}
	return 0;
}