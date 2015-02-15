#include "ProgramController.h"
#include "FileSystemController.h"
#include "FileController.h"
#include "../Data/ProjectSettings.h"
#include "../Data/ArchiverMap.h"

#define archiverFile "archiverFile" 

void ProgramController::ListAvailableCommand()
{
	std::cout << "SuperPacker command line syntax" << std::endl;
	std::cout << "SuperPacker cmd par" << std::endl;
	std::cout << "cmd - one of available commands" << std::endl;
	std::cout << "par - command's parameter" << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "List of available command with parameters:" << std::endl;
	std::cout << " help - show list of available command" << std::endl;
	std::cout << " create p - create project settings file p" << std::endl;
	std::cout << " list p - show project settings file p" << std::endl;
	std::cout << " add-file %p %f - add file f to project settings file p" << std::endl;
	std::cout << " remove-file %p %f - remove file f from project settings file p" << std::endl;
	std::cout << " rename %op %np - change project name od to new project name np" << std::endl;
	std::cout << " remove %p - remove project p settings file" << std::endl;


	std::cout << " add-archiver %a %c - add archiver a to list of available archivers, archiver a use console command c to pack files" << std::endl;
	std::cout << " change-archiver %a %c - change archiver a console command to c" << std::endl;
	std::cout << " remove-archiver %a - remove archiver a from list of available archivers" << std::endl;

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
void ProgramController::RemoveFileFromProject(std::string projectName, std::string fileToRemove)
{
	FileController projectSettingsFile(projectName, false);

	if (projectSettingsFile.IsFileOpen() && projectSettingsFile.IsFileCorrect())
	{
		ProjectSettings projectSettings = projectSettingsFile.LoadProjectSettingsFromFile();
		//TODO if success
		projectSettings.RemoveFileFromListOfFile(fileToRemove);

		projectSettingsFile.ChangeMode();
		projectSettingsFile.SaveProjectSettingsToFile(projectSettings);
	}
}
void ProgramController::ChangeProjectName(std::string oldProjectName, std::string newProjectName)
{
	//TODO if success
	FileSystemController::RenameFile(oldProjectName, newProjectName);

	FileController projectSettingsFile(newProjectName, false);
	if (projectSettingsFile.IsFileOpen() && projectSettingsFile.IsFileCorrect())
	{
		ProjectSettings projectSettings = projectSettingsFile.LoadProjectSettingsFromFile();
		projectSettings.ChangeProjectName(newProjectName);

		projectSettingsFile.ChangeMode();
		projectSettingsFile.SaveProjectSettingsToFile(projectSettings);
	}

}
void ProgramController::RemoveProject(std::string projectName)
{
	FileSystemController::DeleteFile(projectName);
}
void ProgramController::AddArchiver(std::string key, std::string value)
{
	FileController archiverListFile(archiverFile, true);

	if (archiverListFile.IsFileOpen() && archiverListFile.IsFileCorrect())
	{
		ArchiverMap archiverMap = archiverListFile.LoadArchiverMapFromFile();
		archiverMap.AddArchiver(key, value);

		archiverListFile.ChangeMode();
		archiverListFile.SaveArchiverMapToFile(archiverMap);
	}
}
void ProgramController::ChangeArchiver(std::string key, std::string value)
{
	FileController archiverListFile(archiverFile, true);

	if (archiverListFile.IsFileOpen() && archiverListFile.IsFileCorrect())
	{
		ArchiverMap archiverMap = archiverListFile.LoadArchiverMapFromFile();
		archiverMap.ChangeArchiver(key, value);

		archiverListFile.ChangeMode();
		archiverListFile.SaveArchiverMapToFile(archiverMap);
	}
}
void ProgramController::RemoveArchiver(std::string key)
{
	FileController archiverListFile(archiverFile, true);

	if (archiverListFile.IsFileOpen() && archiverListFile.IsFileCorrect())
	{
		ArchiverMap archiverMap = archiverListFile.LoadArchiverMapFromFile();
		archiverMap.RemoveArchiver(key, true);

		archiverListFile.ChangeMode();
		archiverListFile.SaveArchiverMapToFile(archiverMap);
	}
}