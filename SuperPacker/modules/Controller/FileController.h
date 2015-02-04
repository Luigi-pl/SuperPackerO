#pragma once
#include <iostream>
#include <string>
#include <fstream>
class FileController
{
public:
	/*Constuctor open file*/
	FileController(std::string);
	/*Destructor close file*/
	~FileController();

	/*Method adds line of into file*/
	void AddLineOfTextToFile(std::string);
	/*Method checks is file open*/
	bool IsFileOpen();
private:
	std::fstream file;
};

