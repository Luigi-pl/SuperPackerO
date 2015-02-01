#include "FileSystemController.h"

void FileSystemController::CreateFile(std::string fileToCreate)
{
	std::ofstream stream((fileToCreate + ".txt").c_str());
	stream << "";
}