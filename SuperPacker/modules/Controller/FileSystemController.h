#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
/*Class responsible for controlling file system*/
class FileSystemController
{
public:
	/*Method creates empty file*/
	static void CreateFile(std::string);
	/*Method renames file*/
	static bool RenameFile(std::string, std::string);
};

