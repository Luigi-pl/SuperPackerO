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
};

