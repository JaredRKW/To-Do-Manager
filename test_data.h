#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct task_Data
{
	std::string task_Who;		// Who gave you the task
	std::string task_What;		// What the task is
	std::string task_Where;		// Where the task is to be completed
	std::string task_When;		// When the task was given
	std::string task_Due;		// When the task is due by
};

extern std::vector<task_Data> task_Vector;

inline std::ostream& operator<<(std::ostream& os, const task_Data& task)
{
	os << task.task_Who << "|"	// Uses '<<' operator and separates each attribute in an 'task_Data' item by a 'pipe'
		<< task.task_What << "|"
		<< task.task_Where << "|"
		<< task.task_When << "|"
		<< task.task_Due;

	return os;
}

inline std::istream& operator>>(std::istream& is, task_Data& task)
{
	std::string line;
	if (std::getline(is, line))
	{
		std::stringstream ss(line);			// uses 'line' as a stringstream.
		std::string field;

		if (std::getline(ss, field, '|')) task.task_Who = field;		// Each line takes whatever is after each 'pipe' and appends it to the task.attribue
		if (std::getline(ss, field, '|')) task.task_What = field;
		if (std::getline(ss, field, '|')) task.task_Where = field;
		if (std::getline(ss, field, '|')) task.task_When = field;
		if (std::getline(ss, field, '|')) task.task_Due = field;
	}
	return is;
}

void testPopulateDatabase();	// From test_data.cpp