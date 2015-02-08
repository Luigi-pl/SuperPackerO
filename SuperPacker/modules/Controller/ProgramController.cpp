#include "ProgramController.h"
#include "FileSystemController.h"
#include "FileController.h"
#include "../Data/ProjectSettings.h"

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
	FileController projectSettingsFile(projectName, true);
	if (projectSettingsFile.IsFileOpen())
	{
		ProjectSettings projectSettings(projectName, "WinRAR", 1, 0, std::vector<std::string>());
		std::cout << "[SUCCESS] Project \"" << projectName << "\" settings file has been created" << std::endl;
		projectSettingsFile.SaveProjectSettingsToFile(projectSettings);
	}
	else
	{
		std::cout << "[FAIL] Project " << projectName << " settings file hasn't been created" << std::endl;
		return;
	}
}
void ProgramController::ListProject(std::string projectName)
{
	FileController projectSettingsFile(projectName, false);
	if (projectSettingsFile.IsFileOpen() && projectSettingsFile.IsFileCorrect())
	{
		ProjectSettings projectSettings = projectSettingsFile.LoadProjectSettingsFromFile();
		std::cout << "Project name: " << projectSettings.GetProjectName() << std::endl;
		std::cout << "Archiver: " << projectSettings.GetArchiver() << std::endl << std::endl;

		std::cout << "Record number: " << projectSettings.GetRecordNumber() << std::endl << std::endl;

		std::cout << "Number of files: " << projectSettings.GetNumberOfFile() << std::endl;
		std::cout << "Files: " << std::endl;
		for (int i = 0; i < projectSettings.GetNumberOfFile(); i++)
		{
			std::cout << i + 1 << " " << projectSettings.GetFileFromList(i);
		}
	}
	else
	{
		std::cout << "[FAIL] Project " << projectName << " settings file doesn't exist" << std::endl;
	}
}
void ProgramController::AddFileToProject(std::string projectName, std::string fileToAdd)
{
	FileController projectSettingsFile(projectName, false);
	
	if (projectSettingsFile.IsFileOpen() && projectSettingsFile.IsFileCorrect())
	{
		ProjectSettings projectSettings = projectSettingsFile.LoadProjectSettingsFromFile();
		projectSettings.AddFileToListOfFile(fileToAdd);

		projectSettingsFile.ChangeMode();
		projectSettingsFile.SaveProjectSettingsToFile(projectSettings);
	}

}