#include "FileSystemController.h"

void FileSystemController::CreateFile(std::string fileToCreate)
{
	std::ofstream stream((fileToCreate + ".txt").c_str());
	stream << "";
	stream.close();
}
bool FileSystemController::RenameFile(std::string oldFileName, std::string newFileName)
{
	if (rename((oldFileName + ".txt").c_str(),
		(newFileName + ".txt").c_str()) == 0) return true;
	return false;
}
bool FileSystemController::DeleteFile(std::string fileToDelete)
{
	if (remove((fileToDelete + ".txt").c_str()) == 0) return true;
	return false;
}
