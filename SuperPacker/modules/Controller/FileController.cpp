#include "FileController.h"


FileController::FileController(std::string fileToOpen)
{
	file.open((fileToOpen + ".txt").c_str(), std::fstream::trunc | std::fstream::out);
}
FileController::~FileController()
{
	if (file.is_open())
	{
		file.close();
	}
}
void FileController::AddLineOfTextToFile(std::string lineOfText)
{
	file << lineOfText << std::endl;
}
bool FileController::IsFileOpen()
{
	return file.is_open();
}