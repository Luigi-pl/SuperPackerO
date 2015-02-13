#pragma once
#include <string>
#include <vector>
/*Class keeps information about project settings*/
class ProjectSettings
{
public:
	ProjectSettings(std::string, std::string, int, int, std::vector<std::string>);
	/*Method returns project name*/
	std::string GetProjectName();
	/*Method returns archiver used by project*/
	std::string GetArchiver();
	/*Method returns project's record number*/
	int GetRecordNumber();
	/*Method returns number of file to pack*/
	int GetNumberOfFile();
	/*Method returns list of file's path to pack*/
	std::vector<std::string> GetListOfFile();
	/*Method returns single file's path */
	std::string GetFileFromList(int);
	/*Mehod changes project name*/
	void ChangeProjectName(std::string);

	/*Method adds file's path to list of file*/
	void AddFileToListOfFile(std::string);
	/*Method removes file's path from list of file. 
	Return true if file's path was deleted from list */
	bool RemoveFileFromListOfFile(std::string);
	
private:
	std::string projectName;
	std::string archiver;
	int recordNumber;
	int numberOfFile;
	std::vector<std::string> listOfFile;
};

