#include "ProjectSettings.h"

ProjectSettings::ProjectSettings(std::string projectName, std::string archiver, int recordNumber, int numberOfFile, std::vector<std::string> listOfFile)
{
	this->projectName = projectName;
	this->archiver = archiver;
	this->recordNumber = recordNumber;
	this->numberOfFile = numberOfFile;
	this->listOfFile = listOfFile;
}
std::string ProjectSettings::GetProjectName()
{
	return projectName;
}
std::string ProjectSettings::GetArchiver()
{
	return archiver;
}
int ProjectSettings::GetRecordNumber()
{
	return recordNumber;
}
int ProjectSettings::GetNumberOfFile()
{
	return numberOfFile;
}
std::vector<std::string> ProjectSettings::GetListOfFile()
{
	return listOfFile;
}
std::string ProjectSettings::GetFileFromList(int i)
{
	return listOfFile.at(i);
}
void ProjectSettings::ChangeProjectName(std::string newProjectName)
{
	projectName = newProjectName;
}
void ProjectSettings::AddFileToListOfFile(std::string fileToAdd)
{
	listOfFile.push_back(fileToAdd);
	numberOfFile++;
}
bool ProjectSettings::RemoveFileFromListOfFile(std::string fileToRemove)
{

	for (int i = 0; i < numberOfFile; i++)
	{
		if (listOfFile[i].length() == fileToRemove.length() &&
			listOfFile[i].find(fileToRemove.c_str(), 0, listOfFile[i].length()) != std::string::npos)
		{
			listOfFile.erase(listOfFile.begin()+i);
			numberOfFile--;
			return true;
		}
	}
	return false;
}