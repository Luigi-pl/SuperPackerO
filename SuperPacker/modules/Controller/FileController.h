#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class ProjectSettings;
/*Class responsible for controlling file*/
class FileController
{
public:
	/*Constuctor open file*/
	FileController(std::string, bool);
	/*Destructor close file*/
	~FileController();

	/*Method saves Project Settings into file*/
	void SaveProjectSettingsToFile(ProjectSettings);
	/*Method loads Project Settings from file*/
	ProjectSettings LoadProjectSettingsFromFile();
	/*Method checks is file open*/
	bool IsFileOpen();
	/*Method checks if file has correct structure*/
	bool IsFileCorrect();
private:
	template <class T>
	/*Method adds line of text into file*/
	void AddLineOfTextToFile(T);
	/*Method loads line of text from file*/
	std::string GetLineOfTextFromFile();
	/*Method loads number from file*/
	int GetNumberFromFile();

	std::fstream file;
};

