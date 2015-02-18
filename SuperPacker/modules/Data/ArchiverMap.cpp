#include "ArchiverMap.h"

ArchiverMap::ArchiverMap()
{
	archiverMap = std::map<std::string, std::string>();
	archiverListIteratorActualElement = archiverMap.begin();
	archiverListIteratorLastElement = archiverMap.end();
	listFinished = false;
}
void ArchiverMap::AddArchiver(std::string archiver)
{
	if (archiver.size() > 0)
	{
		size_t position = archiver.find_first_of(';');

		std::string key = archiver.substr(0, position);
		std::string value = archiver.substr(position + 1, archiver.length() - position - 1);

		archiverMap.emplace(key, value);

		archiverListIteratorActualElement = archiverMap.begin();
		archiverListIteratorLastElement = archiverMap.end();
		listFinished = false;
	}
}
void ArchiverMap::AddArchiver(std::string key, std::string value)
{
	archiverMap.emplace(key, value);
	archiverListIteratorActualElement = archiverMap.begin();
	archiverListIteratorLastElement = archiverMap.end();
	listFinished = false;
}
void ArchiverMap::RemoveArchiver(std::string archiver, bool UsingKey = false)
{
	if (!UsingKey)
	{
		if (archiver.size() > 0)
		{
			size_t position = archiver.find_first_of(';');

			std::string key = archiver.substr(0, position);

			archiverMap.erase(key);
		}
	}
	else
	{
		archiverMap.erase(archiver);
	}
	archiverListIteratorActualElement = archiverMap.begin();
	archiverListIteratorLastElement = archiverMap.end();
	listFinished = false;
}
std::string ArchiverMap::getCommand(std::string archiverName)
{
	std::map<std::string, std::string>::iterator position = archiverMap.find(archiverName);
	return position->second;
}
void ArchiverMap::ChangeArchiver(std::string archiver)
{
	if (archiver.size() > 0)
	{
		size_t position = archiver.find_first_of(';');

		std::string key = archiver.substr(0, position);
		std::string value = archiver.substr(position + 2, archiver.length() - position - 1);

		archiverMap[key] = value;

		archiverListIteratorActualElement = archiverMap.begin();
		archiverListIteratorLastElement = archiverMap.end();
		listFinished = false;
	}
}
void ArchiverMap::ChangeArchiver(std::string key, std::string value)
{
	archiverMap[key] = value;

	archiverListIteratorActualElement = archiverMap.begin();
	archiverListIteratorLastElement = archiverMap.end();
	listFinished = false;
}

void ArchiverMap::ResetList()
{
	archiverListIteratorActualElement = archiverMap.begin();
	archiverListIteratorLastElement = archiverMap.end();
	listFinished = false;
}
std::string ArchiverMap::NextArchiver()
{
	std::string archiver;
	if (archiverMap.size() != 0 && !listFinished)
	{
		if (archiverListIteratorActualElement == archiverListIteratorLastElement)
		{
			archiver = "";
			listFinished = true;
		}
		else
		{
			archiver = archiverListIteratorActualElement->first + ";" + archiverListIteratorActualElement->second;
			++archiverListIteratorActualElement;
		}

	}
	else
	{
		archiver = "";
	}
	
	return archiver;
}