#include "ProgramController.h"
#include "FileSystemController.h"
void ProgramController::ListAvailableCommand()
{
	std::cout << "SuperPacker command line syntax" << std::endl;
	std::cout << "SuperPacker cmd par" << std::endl;
	std::cout << "cmd - one of available commands" << std::endl;
	std::cout << "par - command's parameter" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "List of available command with parameters:" << std::endl;
	std::cout << " create p - create project file p" << std::endl;
	std::cout << " help - show list of available command" << std::endl;
	/*std::cout << "" << std::endl;*/
}
void ProgramController::CreateProject(std::string projectName)
{
	std::cout << "Project " << projectName << " has been created" << std::endl;
	FileSystemController::CreateFile(projectName);
}