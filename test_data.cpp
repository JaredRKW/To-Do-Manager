// File used to populate the database and test data

#include <iostream>
#include "test_data.h"


// Externals 
extern std::vector<task_Data> task_Vector;



void testPopulateDatabase()
{
	task_Data test_data_01;									// Test cases made here are easier than remaking them every time the program is ran
	task_Data test_data_02;
	task_Data test_data_03;
	task_Data test_data_04;
	task_Data test_data_05;

	test_data_01.task_Who = "Accountant";
	test_data_01.task_What = "File for bankrupcy";
	test_data_01.task_Where = "The Bank";
	test_data_01.task_When = "5/26/25";
	test_data_01.task_Due = "5/28/25";


	test_data_02.task_Who = "Jessica";
	test_data_02.task_What = "Pickup from class";
	test_data_02.task_Where = "Old Main";
	test_data_02.task_When = "This Morning";
	test_data_02.task_Due = "4:30 PM";


	test_data_03.task_Who = "Father";
	test_data_03.task_What = "Clean Litterbox";
	test_data_03.task_Where = "Laundry Room";
	test_data_03.task_When = "N/A";
	test_data_03.task_Due = "Tonight";

	test_data_04.task_Who = "Blinn";
	test_data_04.task_What = "File for Appeal";
	test_data_04.task_Where = "N/A";
	test_data_04.task_When = "4/12/25";
	test_data_04.task_Due = "6/26/25";

	test_data_05.task_Who = "Myself";
	test_data_05.task_What = "Practice Trumpet";
	test_data_05.task_Where = "Where Available";
	test_data_05.task_When = "N/A";
	test_data_05.task_Due = "8:00 PM - Daily";


	task_Vector.push_back(test_data_01);
	task_Vector.push_back(test_data_02);
	task_Vector.push_back(test_data_03);
	task_Vector.push_back(test_data_04);
	task_Vector.push_back(test_data_05);

	//std::cout << "\ndebug testPopulateDatabase succeeded. Added " << task_Vector.size() << " test cases to the database!\n";
}