/*	Author:			Bushra Rahman
	Course:			CS 1337 (Fall 2019)
	Date:			9/24/2019
	main.cpp:		This source file is the driver of the program.
					It opens and closes the input file, 
					initializes and dynamically allocates the parallel arrays to memory, 
					and displays the menu and makes decisions based on user input. */

#include "doTasks.h"	// header file containing the tasks' function prototypes
#include <iostream>
#include <fstream>
#include <string>
using namespace std;



int main() {

	// create the input file and its name
	ifstream inputFile;
	string inputFileName;

	// prompt user for input file and read it in
	cout << "Please enter the input file name: ";
	cin >> inputFileName;

	// the number of records in the input file, specified at the beginning
	int numItems;

	// open the input file
	inputFile.open(inputFileName);

	if (inputFile)
	{
		// read in the number of records
		inputFile >> numItems;

		// if the number of records is valid
		if (numItems > 0)
		{
			// dynamically allocate memory to the arrays
			string *lastNameArray = new string[numItems];
			string *firstNameArray = new string[numItems];
			string *birthdateArray = new string[numItems];

			// read in the contents of the input file into the arrays
			int count = 0;
			while (count < numItems && inputFile >> lastNameArray[count]
					&& inputFile >> firstNameArray[count]
					&& inputFile >> birthdateArray[count])
			{
			count ++;
			}

			int prompt = -1;			// initial value for the user-inputted prompt value
			string searchingFor = "";	// initial value for the user-inputted substring
			int sortingType = -1;		// initial value for the user-inputted sorting type

			// if the number of records read in matches the number of items
			if (count == numItems)
			{
				// the menu displays until the user exits by entering 0
				while (prompt != 0)
				{
					// call the prompt-displaying function
					prompt = getPrompt();

					// if the option to search is selected
					if(prompt == 1)
					{
						// re-initialize searchingFor
						searchingFor = "";

						// call the prompt-displaying function
						searchingFor = searchString();

						// call the searching function
						doSearch(searchingFor, numItems, lastNameArray, firstNameArray, birthdateArray);
					}

					// if the option to sort is selected
					else if (prompt == 2)
					{
						// call the prompt-displaying function
						sortingType = getSortingType();

						// if the option to display the original records has been selected
						if(sortingType == 0)
						{
							// call the array-displaying function
							printArrays("** Original Records **", numItems, lastNameArray, firstNameArray, birthdateArray);
						}

						// if the options to sort by either first or last name have been selected
						else if (sortingType == 1 || sortingType == 2)
						{
							// call the sorting function
							doSort (sortingType, numItems, lastNameArray, firstNameArray, birthdateArray);
						}

					}
				}
			}
			// if the number of records read in doesn't match the number of items
			else
			{
				cout << "*** Error: numItems = " << numItems << " and count = " << count << endl;
			}

			// de-allocate the used memory before exiting
			delete [] lastNameArray;
			delete [] firstNameArray;
			delete [] birthdateArray;
		}

		inputFile.close();
	}
	else
	{
		cout << "Error: File \"" << inputFileName << "\" could not be opened" << endl;
	}

	return 0;
}