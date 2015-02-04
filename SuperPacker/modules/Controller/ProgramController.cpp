#include "ProgramController.h"
#include "FileSystemController.h"
#include "FileController.h"

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
	FileSystemController::CreateFile(projectName);
	FileController projectSettingsFile(projectName);
	if (projectSettingsFile.IsFileOpen())
	{
		std::cout << "[SUCCESS] Project \"" << projectName << "\" settings file has been created" << std::endl;
		projectSettingsFile.AddLineOfTextToFile(projectName);
		projectSettingsFile.AddLineOfTextToFile("WinRAR"); //for now program can only use WinRAR to pack files (it will be changed)
		projectSettingsFile.AddLineOfTextToFile("1");	//Record number of next archive
		projectSettingsFile.AddLineOfTextToFile("0");	//number of files to add to archive
	}
	else
	{
		std::cout << "[FAIL] Project " << projectName << " settings file hasn't been created" << std::endl;
		return;
	}
}