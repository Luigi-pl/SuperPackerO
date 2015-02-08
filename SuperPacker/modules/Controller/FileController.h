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

	/*Method changes mode write->read/read->write*/
	void ChangeMode();

private:
	template <class T>
	/*Method adds line of text into file*/
	void AddLineOfTextToFile(T);
	/*Method loads line of text from file*/
	std::string GetLineOfTextFromFile();
	/*Method loads number from file*/
	int GetNumberFromFile();
	
	/*Method opens file to read*/
	void OpenFileToRead(std::string);
	/*Method opens file to write*/
	void OpenFileToWrite(std::string);
	/*Method closes file*/
	void CloseFile();
	/*Method changes mode from writing to reading*/
	void ChangeModeFromWriteToRead();
	/*Method changes mode from reading to writing*/
	void ChangeModeFromReadToWrite();

	std::fstream file;
	std::string fileName;
	bool isWriting;
};

