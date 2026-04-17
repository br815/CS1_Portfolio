/*	Author:			Bushra Rahman
	Course:			CS 1337 (Fall 2019)
	Date:			9/24/2019
	doTasks.cpp:	This source file contains the function definitions for this project.
					There are 6 functions in all:
					1)          The function getPrompt() is responsible for printing the main menu of the program 
                                and receiving the user-inputted prompt.
                    2)          The function printArrays() prints the contents of all the arrays.
                    3 and 4)    The function doSearch() takes the user-inputted substring 
                                received from the function searchString() as a parameter, and searches for that substring.
                    5 and 6)    The function doSort() takes the user-inputted sorting type
                                received from the function getSortingType() as a parameter,
                                and sorts according to that sorting type.
					In summary, 
					The functions getPrompt(), searchString(), and getSortingType() print out prompts for user input 
					and receive the instructions to either search, sort, or quit. 
					The function doSearch() searches for the user-inputted substring, 
					and the function doSort() sorts by either first name or last name. */

#include "doTasks.h"	// header file containing the tasks' function prototypes
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;



/*	Function 1:		doSort()
	Descr:			This function implements selection sort to sort the entries in the input file based on the user-inputted sortingType choice.
	Param:    		int sortingType, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[]
					Variables to control the sorting process, and arrays containing the values being sorted.
	Return:			None. */
void doSort (int sortingType, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[])
{
	string searchingIn;                // the string of the current element
	string searchingFor;               // the strings of the subsequent elements
	int compareResult = -1;            // the result of comparing these strings
	int len = searchingFor.length();   // the lengths of the subsequent strings
	int indexOfSmallestItem = -1;      // the index of the smallest string
	string savedString = "";           // the smallest string
	string title = "";                 // the title of the sorted array

	// initialize the new arrays of the sorted items
	string *lastNameArraySorted = new string[numItems];
	string *firstNameArraySorted = new string[numItems];
	string *birthdateArraySorted = new string[numItems];

	// initialize the array that gets sorted based on first name or last name
	string *name = new string[numItems];

	// initialization starts here
	for(int i = 0; i < numItems; i++)
	{
		// copy every item from the original arrays into the sorted arrays
		lastNameArraySorted[i] = lastNameArray[i];
		firstNameArraySorted[i] = firstNameArray[i];
		birthdateArraySorted[i] = birthdateArray[i];

		// if the arrays are to be sorted by last name
		if(sortingType == 1)
		{
			name[i] = lastNameArray[i];
			title = "** Records Sorted By Last Name **";
		}

		// if the arrays are to be sorted by first name
		else if (sortingType == 2)
		{
			name[i] = firstNameArray[i];
			title = "** Records Sorted By First Name **";
		}
	}
	// initialization ends here

	// actual sorting starts here (an implementation of selection sort)
	for (int i = 0; i < numItems; i++)
	{
		searchingIn = name[i];
		indexOfSmallestItem = -1;
		// this nested loop compares the current element to every element after it
		for (int j = i+1; j < numItems; j++)
		{
			compareResult = -1;           // result of the string comparison
			searchingFor = name[j];       // element being compared with name[i]
			len = searchingFor.length();  // length of the item being compared with name[i]

			// compares the first characters of the strings
			compareResult = searchingIn.compare(0, len, searchingFor);

			// if the compared string, name[i] is greater than the comparing string, name[j]
			if (compareResult > 0)
			{
				// name[i] is swapped with name[j] b/c name[j] is smaller and should come first
				searchingIn = searchingFor;
				indexOfSmallestItem = j;
			}
		}
		// end of nested loop


		// if the smallest item is further down the array after the current element
		if (indexOfSmallestItem > i)
		{
			savedString = name[i];                    // the i'th element is saved so it can be swapped later
			name[i] = name[indexOfSmallestItem];      // the i'th element receives the smallest string
			name[indexOfSmallestItem] = savedString;  // the string previously in name[i] gets swapped away

			savedString = lastNameArraySorted[i];
			lastNameArraySorted[i] = lastNameArraySorted[indexOfSmallestItem];
			lastNameArraySorted[indexOfSmallestItem]=savedString;

			savedString = firstNameArraySorted[i];
			firstNameArraySorted[i] = firstNameArraySorted[indexOfSmallestItem];
			firstNameArraySorted[indexOfSmallestItem]=savedString;

			savedString = birthdateArraySorted[i];
			birthdateArraySorted[i] = birthdateArraySorted[indexOfSmallestItem];
			birthdateArraySorted[indexOfSmallestItem] = savedString;
		}
	}


	printArrays(title, numItems, lastNameArraySorted, firstNameArraySorted, birthdateArraySorted);
}



/*	Function 2:		doSearch()
	Descr:			This function implements linear search to search the entries in the input file based on the user-inputted searchingFor choice.
	Param:    		string searchingFor, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[]
					Variables to control the searching process, and arrays containing the values being searched.
	Return:			None. */
void doSearch (string searchingFor, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[])
{
	string searchingIn = "";             // any string in any array
	int compareResult = -1;              // result of the string comparison
	int len = searchingFor.length();     // length of the user-inputted substring
	bool matchFound[numItems];           // array flags for all items that contain the given substring

	for(int i = 0; i < numItems; i++)
	{
		// searching in lastNameArray
		matchFound[i] = false;
		searchingIn = lastNameArray[i];
		compareResult = searchingIn.compare(0, len, searchingFor);
		// if the given substring is contained in the current item
		if (compareResult == 0)
		{
			matchFound[i] = true;   // a flag is made for this index
			continue;               // there's no need to search the other fields since a match was found here
		}


		// searching in firstNameArray
		searchingIn = firstNameArray[i];
		compareResult = searchingIn.compare(0, len, searchingFor);

		if (compareResult == 0)
		{
			matchFound[i] = true;
			continue;
		}


		// searching in birthdateArray
		searchingIn = birthdateArray[i];
		compareResult = searchingIn.compare(0, len, searchingFor);

		if (compareResult == 0)
		{
			matchFound[i] = true;
		}
	}


	int numMatchedItems = 0;
	// loops back through the array of flags to print out all the matches from each array
	for(int i = 0 ; i < numItems; i++)
	{
		if (matchFound[i])
		{
			numMatchedItems++;
			cout << lastNameArray[i] << " " << firstNameArray[i] << " " << birthdateArray[i] << endl;
		}
	}

	if(numMatchedItems == 0)
	{
		cout << "*** No matches found." << endl;
	}

}



/*	Function 3:		printArrays()
	Descr:			This function prints the original unsorted arrays.
	Param:    		string title, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[]
					Variables to control the printing process, and arrays containing the values being printed.
	Return:			None. */
void printArrays(string title, int numItems, string lastNameArray[], string firstNameArray[], string birthdateArray[])
{
	cout << endl;
	cout << title << endl;

	// prints the original unsorted arrays
	for (int i = 0; i < numItems; i++)
	{
		cout << lastNameArray[i] << " " << firstNameArray[i] << " " << birthdateArray[i] << endl;
	}

}



/*	Function 4:		getSortingType()
	Descr:			This function prints the sorting menu for the user when they choose the "Sort" option.
	Param:    		None.
	Return:			int prompt
					The user-inputted sortingType choice. */
int getSortingType()
{
	// print the menu for sorting options
	cout << endl << endl << "Available Sorting Options:" << endl;
	cout << "1 Sort By Last Name" << endl;
	cout << "2 Sort By First Name" << endl;
	cout << "0 Print Original Records" << endl;

	cout << "Please enter a sorting type: " << endl;
	int prompt = -1;
	cin >> prompt;

	return prompt;
}



/*	Function 5:		searchString()
	Descr:			This function gets a user-inputted substring that will be searched for.
	Param:    		None.
	Return:			string search
					The substring that will be searched for. */
string searchString()
{
	// asks the user for a substring to search for and returns that string
	string search = "";
	cout << "Please enter a search string: " << endl;
	cin >> search;

	return search;
}



/*	Function 6:		getPrompt()
	Descr:			This function displays the main menu which asks the user if they want to search, sort, or quit out of the program.
	Param:    		None.
	Return:			int prompt
					The user's choice to search, sort, or quit. */
int getPrompt()
{
	// print the starting menu
	cout << endl << endl << "Available Options:" << endl;
	cout << "1 Search" << endl;
	cout << "2 Sort" << endl;
	cout << "0 Quit" << endl;

	cout << "Please enter a number indicating which option you want: " << endl;

	int prompt = -1;
	cin >> prompt;

	return prompt;
}