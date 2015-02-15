#include "FileController.h"
#include "../Data/ProjectSettings.h"
#include "../Data/ArchiverMap.h"

FileController::FileController(std::string fileNameToOpen, bool toWrite = false)
{
	isWriting = toWrite;
	fileName = fileNameToOpen;
	if (toWrite)
	{
		OpenFileToWrite(fileNameToOpen);
	}
	else
	{
		OpenFileToRead(fileNameToOpen);
	}

}
FileController::~FileController()
{
	CloseFile();
}
void FileController::SaveProjectSettingsToFile(ProjectSettings projectSettings)
{
	AddLineOfTextToFile("\"" + projectSettings.GetProjectName() + "\"");
	AddLineOfTextToFile("\"" + projectSettings.GetArchiver() + "\"");
	AddLineOfTextToFile(projectSettings.GetRecordNumber());
	AddLineOfTextToFile(projectSettings.GetNumberOfFile());
	if (projectSettings.GetNumberOfFile() > 0)
	{
		for (int i = 0; i < projectSettings.GetNumberOfFile(); i++)
		{
			AddLineOfTextToFile("\"" + projectSettings.GetFileFromList(i) + "\"");
		}
	}
}
void FileController::ChangeMode()
{
	if (isWriting)
	{
		ChangeModeFromWriteToRead();
	}
	else
	{
		ChangeModeFromReadToWrite();
	}
}
void FileController::SaveArchiverMapToFile(ArchiverMap archiverMap)
{
	std::string archiver = archiverMap.NextArchiver();
	while (archiver.size() > 0)
	{
		AddLineOfTextToFile(archiver);
		archiver = archiverMap.NextArchiver();
	}
}

ArchiverMap FileController::LoadArchiverMapFromFile()
{
	ArchiverMap archiverMap = ArchiverMap();
	std::string lineOfText = GetLineOfTextFromFile();
	while (lineOfText.size() > 0)
	{
		archiverMap.AddArchiver(lineOfText);
		lineOfText = GetLineOfTextFromFile();
	}
	return archiverMap;
}

ProjectSettings FileController::LoadProjectSettingsFromFile()
{
	std::string projectName = "";
	std::string archiver = "";
	int recordNumber = 1;
	int numberOfFile = 0;
	std::string file = "";
	std::vector<std::string> listOfFile;

	projectName = GetLineOfTextFromFile();
	projectName.erase(0, 1);
	projectName.erase(projectName.length() - 1, 1);

	archiver = GetLineOfTextFromFile();
	archiver.erase(0, 1);
	archiver.erase(archiver.length() - 1, 1);

	recordNumber = GetNumberFromFile();
	numberOfFile = GetNumberFromFile();
	for (int i = 0; i < numberOfFile; i++)
	{
		file = GetLineOfTextFromFile();
		file.erase(0, 1);
		file.erase(file.length() - 1, 1);
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
void FileController::OpenFileToRead(std::string fileNameToOpen)
{
	CloseFile();
	file.open((fileNameToOpen + ".txt").c_str(), std::fstream::in);
}
void FileController::OpenFileToWrite(std::string fileNameToOpen)
{
	CloseFile();
	file.open((fileNameToOpen + ".txt").c_str(), std::fstream::trunc | std::fstream::out);
}
void FileController::CloseFile()
{
	if (file.is_open())
	{
		file.close();
	}
}
void FileController::ChangeModeFromWriteToRead()
{
	OpenFileToRead(fileName);
}
void FileController::ChangeModeFromReadToWrite()
{
	OpenFileToWrite(fileName);
}