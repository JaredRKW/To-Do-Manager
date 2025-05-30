#pragma once

#include <iostream>
#include <vector>
#include <string>

struct task_Data
{
	std::string task_Who;		// Who gave you the task
	std::string task_What;		// What the task is
	std::string task_Where;		// Where the task is to be completed
	std::string task_When;		// When the task was given
	std::string task_Due;		// When the task is due by
};

extern std::vector<task_Data> task_Vector;

void testPopulateDatabase();	// From test_data.cpp
								// Adds test cases to memory but does not write to file until called!