// To-Do Manager. Input tasks you need to complete, including "who, what, where, when," and write it to a text file.

// Imports
#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <limits>
#include <iomanip>
#include <sstream>
#include "test_data.h"

// Variables

std::vector<task_Data> task_Vector;	// Cannot use array, needs to be fluid



// Function Declaration
void displayMenu();				// They don't return anything, as such they are void  ¯\(ツ)/¯
void addTask();
void removeTask();
void displayTasks();
int readFile();
int writeFile();
void testPopulateDatabase();		// For testing purposes

// Start Program

int main()
{

	//std::cout << "\ndebug main\n"; 
	
	readFile();
									// In testing purposes, can add testPopulateDatabase();

	displayMenu();					// I don't want the whole program in main function

	return 0;
}

void displayMenu()
{
	std::string input_string;		// Take user input as a string then convert it into integer
	int converted_integer;

	//std::cout << "\ndebug displayMenu\n";


	while (true)					// Program basically loops back to this displayMenu function
	{
		try
		{
			std::cout << "\n\n========== TO-DO MENU ==========\n\n";

			std::cout << "\n\n1. Diplay Tasks\n2. Add Task\n3. Remove Task\n4. Quit\n\n>>>  ";
			std::cin >> input_string;
			converted_integer = std::stoi(input_string);	// This is where user's input string is converted into an integer

			if (converted_integer == 1)						// I'm sure this is what switch statements are for. However I am lazy
				displayTasks();
			else if (converted_integer == 2)
				addTask();
			else if (converted_integer == 3)
				removeTask();
			else if (converted_integer == 4)
			{
				std::cout << "\n\nThank you for using To-Do list, do come back!";
				exit(0);
			}
			else
				std::cout << "\nPlease enter a valid option!\n\n";
		}
		catch(std::invalid_argument)						// Your mom is an invalid argument ┌∩┐(◣_◢)┌∩┐
		{
			std::cout << "\nPlease enter a valid option!\n\n";
		}

	}

}

void displayTasks()
{
	//std::cout << "\ndebug display_Task\n";

	if (task_Vector.empty())
	{
		std::cout << "\nYou're all caught up!\n\nConsider adding a task to populate the database...\n";			// No need to display a whole database if it is empty
	}
	else
	{
		std::cout << "\n========== TASK DATABASE ==========\n\n";


		std::cout << std::left
			<< std::setw(5) << "ID"
			<< std::setw(20) << "Who"
			<< std::setw(40) << "What"
			<< std::setw(20) << "Where"
			<< std::setw(15) << "When"
			<< std::setw(15) << "Due"
			<< "\n";
		
		std::cout << std::string(115, '_') << "\n\n";		// std::string(n, '_') should be equal to sum of width padding

		for (size_t i = 0; i < task_Vector.size(); i++)		// size_t is the return type of .size(), using int makes for a bitchy compiler  (╯︵╰,)
		{
			const task_Data& task = task_Vector[i];			// task_Data& is a reference to task. Easy typing if mods are made
															// Reference is also made so a full copy isn't made every time this "for" loop is used
			std::cout << std::left
				<<std::setw(5) << (i + 1)
				<< std::setw(20) << task.task_Who			
				<< std::setw(40) << task.task_What			// Sum of width all "setw" here must equal "setw" width at lines 105-110.
				<< std::setw(20) << task.task_Where
				<< std::setw(15) << task.task_When
				<< std::setw(15) << task.task_Due
				<< "\n\n";
		}
		std::cout << std::string(115, '_') << "\n\n";		// refer to comment on line 106

		//std::cout << "\ndebug task_Vector.size():  " << task_Vector.size();
	}

}


void addTask()
{

	//std::cout << "\ndebug add_Task\n";

	std::cout << "\n========== ADD TASK ==========\n\n";

	std::cin.ignore();			// Otherwise "\n" remains inside the input buffer 

	task_Data new_Task;			

	int who = 0;				// For the "While" loops
	int what = 0;
	int where = 0;
	int when = 0;
	int due = 0;

	std::cout << ("\nYou will now be prompted for the \"Who,\" \"What,\" \"Where,\" \"When,\" and when it is due by. Be prompt and efficient in your answers.\n\neg. When prompted for \"What,\" try entering \"Clean Room,\" instead of \"Go to the master bedroom and start cleaning for the day\" \n\n");
	std::cout << ("Who: Who assigned you the task?\nWhat: What is the task?\nWhere: Where is the task to be completed?\nWhen: When was the task assigned to you?\nDue: When is it due by?\n\n");

	while (who < 1)
	{
		std::cout << "Who? (Who assigned the task)\n>>>  ";
		std::getline(std::cin, new_Task.task_Who);			// Need's to get the whole line, otherwise anything after the first word is ignored

		//std::cout << "\ndebug new_Task.task_Who: " << new_Task.task_Who << std::endl;

		who++;
	}

	while (what < 1)
	{
		std::cout << "What? (What is the task)\n>>> ";
		std::getline(std::cin, new_Task.task_What);			// Take input then push into assigned attribute of new_Task variable

		//std::cout << "\ndebug new_Task.task_What: " << new_Task.task_What << std::endl;

		what++;
	}

	while (where < 1)
	{
		std::cout << "Where? (Where is the task to be done)\n>>> ";
		std::getline(std::cin, new_Task.task_Where);		// Rest of the "While" loops work the same.

		//std::cout << "\ndebug new_Task.task_Where: " << new_Task.task_Where << std::endl;

		where++;
	}

	while (when < 1)
	{
		std::cout << "When? (When was it assigned)\n>>> ";
		std::getline(std::cin, new_Task.task_When);

		//std::cout << "\ndebug new_Task.task_When: " << new_Task.task_When << std::endl;

		when++;
	}

	while (due < 1)
	{
		std::cout << "Due? (When is it due by)\n>>> ";
		std::getline(std::cin, new_Task.task_Due);

		//std::cout << "\ndebug new_Task.task_Due: " << new_Task.task_Due << std::endl;

		due++;
	}

	task_Vector.push_back(new_Task);

	writeFile();

}

void removeTask()
{
	std::string input_string;
	int converted_integer;
	int r = 0;

	//std::cout << "\ndebug remove_Task\n";


	if (task_Vector.empty())
	{
		std::cout << "\nThere are no tasks available to remove!\n\nConsider adding a task to populate the database...\n";			// We use the same technique to display all tasks as in 'displayTasks()'
	}
	else
	{
		std::cout << "\n========== REMOVE TASK ==========\n\n";


		std::cout << std::left								// Violating DRY principles by copying 'displayTasks()'..... Oh well
			<< std::setw(5) << "ID"
			<< std::setw(20) << "Who"
			<< std::setw(40) << "What"
			<< std::setw(20) << "Where"
			<< std::setw(15) << "When"
			<< std::setw(15) << "Due"
			<< "\n";

		std::cout << std::string(115, '_') << "\n\n";		// Everything display-wise should be exact to 'displayTasks()'

		for (size_t i = 0; i < task_Vector.size(); i++)		// I could also just use 'displayTasks()' but why would I make things simple and readable 【ツ】
		{
			const task_Data& task = task_Vector[i];			
															
			std::cout << std::left
				<< std::setw(5) << (i + 1)
				<< std::setw(20) << task.task_Who
				<< std::setw(40) << task.task_What			
				<< std::setw(20) << task.task_Where
				<< std::setw(15) << task.task_When
				<< std::setw(15) << task.task_Due
				<< "\n\n";
		}
		std::cout << std::string(115, '_') << "\n\n";

		//std::cout << "\ndebug task_Vector.size():  " << task_Vector.size();

		while (r < 1)
		{
			try
			{
				std::cout << "\nEnter an ID number (the number in the left-most column) that is equal to the task you would like to remove\n\n>>> ";
				std::cin >> input_string;						// Refer to line 59 for explanation. Also violates DRY...
				converted_integer = std::stoi(input_string);
			}
			catch (std::invalid_argument)
			{
				std::cout << "\nPlease enter a valid option!\n\n";
			}

			r++;
		}

		if (converted_integer >= 1 && converted_integer <= static_cast<int>(task_Vector.size()))
		{
			task_Vector.erase(task_Vector.begin() + (converted_integer - 1));
			std::cout << "\nTask zapped succesfully!\n\n";

			writeFile();
		}
		else
		{
			std::cout << "\n\nSorry cowboy, looks like your aim was off. Try entering a valid ID ;)";
		}
		
	}

}


