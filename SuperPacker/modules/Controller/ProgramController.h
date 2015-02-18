#pragma once
#include <iostream>
#include <string>
/*Class responsible for controlling console's command*/
class ProgramController
{
public:
	/*Implementation of console command:
	help, which shows list of available commands
	*/
	static void ListAvailableCommand();
	/*Implementation of console command:
	create %p - create project (%p) settings file
	*/
	static void CreateProject(std::string);
	/*Implementation of console command:
	list %p - show project (%p) settings file
	*/
	static void ListProject(std::string);
	/*Implementation of console command:
	add-file %p %f - add file (%f) to project (%p) settings file
	*/
	static void AddFileToProject(std::string, std::string);
	/*Implementation of console command:
	remove-file %p %f - remove file (%f) from project (%p) settings file
	*/
	static void RemoveFileFromProject(std::string, std::string);
	/*Implementation of console command:
	rename %op %np - change project name (%od) to (%np)
	*/
	static void ChangeProjectName(std::string, std::string);
	/*Implementation of console command:
	remove %p - remove project (%p) settings file
	*/
	static void RemoveProject(std::string);
	/*Implementation of console command:
	execute %p - execute packing to archive project (%p)
	*/
	static void ExecuteProject(std::string);

	/*Implementation of console command:
	add-archiver %a %c - add archiver (%a) to list of available archivers, archiver (%a) use console command (%c) to pack files
	*/
	static void AddArchiver(std::string, std::string);
	/*Implementation of console command:
	change-archiver %a %c - change archiver (%a) console command to (%c) to pack files
	*/
	static void ChangeArchiver(std::string, std::string);
	/*Implementation of console command:
	remove-archiver %a - remove archiver (%a) from list of available archivers
	*/
	static void RemoveArchiver(std::string);

};

