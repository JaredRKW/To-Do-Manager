// Used to handle the reading and writing from file

// Imports
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "test_data.h"

// Externals
extern std::vector<task_Data> task_Vector;


// Functions
int readFile()
{
	std::cout << "\ndebug readFile()\n";

	std::ifstream task_Data_File("./task_Data_File.txt");

	if (!task_Data_File || task_Data_File.fail())
	{
		std::cout << "\ndebug Couldn't find task_Data_File.";

		return 1;
	}

	task_Vector.clear();									// So we don't have any leftover items

	task_Data task;											// Creates an empty task object to hold each task
	while (task_Data_File >> task)							// Takes each attribute from each item and converts it into standalone tasks
	{
		task_Vector.push_back(task);
	}

	task_Data_File.close();									// Good practice

	std::cout << "\ndebug Loaded task_Data_File... " << task_Vector.size() << " tasks loaded from file!";

	return 0;
}

int writeFile()
{
	std::cout << "\ndebug writeFile()\n";
	std::ofstream task_Data_File("./task_Data_File.txt");					// If file doesn't exist, it is created in the same folder as the '.exe'

	if (!task_Data_File || task_Data_File.fail())							// For redundancy
	{
		std::cerr << "\ndebug Failed to open vector_Data.txt!\n";

		return 1;
	}

	for (auto element : task_Vector)
	{
		task_Data_File << element << std::endl;
	}

	char buffer[MAX_PATH];													// Windows specific path-size buffer				 
	GetCurrentDirectoryA(MAX_PATH, buffer);									// Because of UTF-8, have to explicitly tell compiler to use ANSI encoding (We speak English here)
	std::cout << "\ndebug GetCurrentDirectory:  " << buffer << "\n";		// Sanity check, so I can find task_Data_File

	task_Data_File.close();

	return 0;
}