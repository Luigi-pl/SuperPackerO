#pragma once
#include <string>
#include <vector>
/*Class keeps information about project settings*/
class ProjectSettings
{
public:
	ProjectSettings(std::string, std::string, int, int, std::vector<std::string>);
	/*Method returns project name*/
	std::string getProjectName();
	/*Method returns archiver used by project*/
	std::string getArchiver();
	/*Method returns project's record number*/
	int getRecordNumber();
	/*Method returns number of file to pack*/
	int getNumberOfFile();
	/*Method returns list of file's path to pack*/
	std::vector<std::string> getListOfFile();
	/*Method returns single file's path */
	std::string getFileFromList(int);

private:
	std::string projectName;
	std::string archiver;
	int recordNumber;
	int numberOfFile;
	std::vector<std::string> listOfFile;
};

