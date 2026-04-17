/*	Author:		    Bushra Rahman
	Course:		    CS 1337 (Fall 2019)
	Date:			9/24/2019
	doTasks.h:      This header file contains the 6 function prototypes for this project. */

// header for #include guard (preprocessor directives)
#ifndef DOTASKS_H_		// if DOTASKS_H_ is not defined, define it (start of header guard)
#define DOTASKS_H_		// define DOTASKS_H_ once to prevent multiple inclusions
#include <fstream>
#include <string>
using namespace std;

void doSort (int sortingType, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[]);
void doSearch (string searchingFor, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[]);
void printArrays(string title, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[]);
int getSortingType();
string searchString();
int getPrompt();

#endif					// end of "if not defined" ifndef block