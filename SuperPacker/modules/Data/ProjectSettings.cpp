#include "ProjectSettings.h"

ProjectSettings::ProjectSettings(std::string projectName, std::string archiver, int recordNumber, int numberOfFile, std::vector<std::string> listOfFile)
{
	this->projectName = projectName;
	this->archiver = archiver;
	this->recordNumber = recordNumber;
	this->numberOfFile = numberOfFile;
	this->listOfFile = listOfFile;
}
std::string ProjectSettings::getProjectName()
{
	return projectName;
}
std::string ProjectSettings::getArchiver()
{
	return archiver;
}
int ProjectSettings::getRecordNumber()
{
	return recordNumber;
}
int ProjectSettings::getNumberOfFile()
{
	return numberOfFile;
}
std::vector<std::string> ProjectSettings::getListOfFile()
{
	return listOfFile;
}
std::string ProjectSettings::getFileFromList(int i)
{
	return listOfFile.at(i);
}