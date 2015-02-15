#pragma once
#include <iostream>
#include <map>
/*Class keeps information about archivers*/
class ArchiverMap
{
public:
	/*Constructor set iterators*/
	ArchiverMap();

	/*Method returns transformed archiverMap element into std::string*/
	std::string NextArchiver();
	/*Method resets iterators*/
	void ResetList();

	/*Method adds archiver to list*/
	void AddArchiver(std::string);
	/*Method adds archiver to list*/
	void AddArchiver(std::string, std::string);

	/*Method removes archiver from list*/
	void RemoveArchiver(std::string, bool);

	/*Method changes archiver on list*/
	void ChangeArchiver(std::string);
	/*Method changes archiver on list*/
	void ChangeArchiver(std::string, std::string);

private:
	/*Archiver map, key = archiver name, value = archiver command to pack file*/
	std::map<std::string, std::string> archiverMap;

	std::map<std::string, std::string>::iterator archiverListIteratorActualElement;
	std::map<std::string, std::string>::iterator archiverListIteratorLastElement;

	bool listFinished;
};