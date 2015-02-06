#include "FileController.h"
#include "../Data/ProjectSettings.h"

FileController::FileController(std::string fileToOpen, bool toWrite)
{
	if (toWrite)
	{
		file.open((fileToOpen + ".txt").c_str(), std::fstream::trunc | std::fstream::out);
	}
	else
	{
		file.open((fileToOpen + ".txt").c_str(), std::fstream::in);
	}
	
}
FileController::~FileController()
{
	if (file.is_open())
	{
		file.close();
	}
}
void FileController::SaveProjectSettingsToFile(ProjectSettings projectSettings)
{
	AddLineOfTextToFile(projectSettings.getProjectName());
	AddLineOfTextToFile(projectSettings.getArchiver());
	AddLineOfTextToFile(projectSettings.getRecordNumber());
	AddLineOfTextToFile(projectSettings.getNumberOfFile());
	if (projectSettings.getNumberOfFile() > 0)
	{
		for (int i = 0; i < projectSettings.getNumberOfFile(); i++)
		{
			AddLineOfTextToFile(projectSettings.getFileFromList(i));
		}
	}
}
ProjectSettings FileController::LoadProjectSettingsFromFile()
{
	std::string projectName = "";
	std::string archiver = "";
	int recordNumber=1;
	int numberOfFile=0;
	std::string file = "";
	std::vector<std::string> listOfFile;

	projectName = GetLineOfTextFromFile();
	archiver = GetLineOfTextFromFile();
	recordNumber = GetNumberFromFile();
	numberOfFile = GetNumberFromFile();
	for (int i = 0; i < numberOfFile; i++)
	{
		file = GetLineOfTextFromFile();
		listOfFile.push_back(file);
	}
	return ProjectSettings(projectName, archiver, recordNumber, numberOfFile, listOfFile);
}
bool FileController::IsFileOpen()
{
	return file.is_open();
}
bool FileController::IsFileCorrect()
{
	file >> std::noskipws;
	unsigned line_count = std::count(std::istream_iterator<char>(file), std::istream_iterator<char>(), '\n');
	
	file >> std::skipws;
	file.clear();
	file.seekg(0, std::ios::beg);
	if (line_count < 4)
	{
		return false;
	}
	else
	{
		return true;
	}
}
template <class T>
void FileController::AddLineOfTextToFile(T lineOfText)
{
	file << lineOfText << std::endl;
}

int GetNumberFromFile();
std::string FileController::GetLineOfTextFromFile()
{
	if (!file.good())
	{
		return "ERROR";
	}
	else
	{
		std::string lineOfText;
		file >> lineOfText;
		return lineOfText;
	}
}
int FileController::GetNumberFromFile()
{
	if (!file.good())
	{
		return -1;
	}
	else
	{
		int number;
		file >> number;
		return number;
	}
}