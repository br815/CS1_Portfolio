/*	Author:			Bushra Rahman
	Course:			CS 1337 (Fall 2019)
	Date:			10/8/2019
	drinkMachine.c:	This source file contains the helper function definitions for this project.
					There are 17 helper functions in all:
					1)  create()
					2)  DrinkItem_create()
					3)  DrinkItem_destroy()
					4)  DrinkMachine_create()
					5)  destroy()
					6)  firstDrink()
					7)  nextDrink()
					8)  items()
					9)  cost()
					10) available()
					11) sell()
					12) purchase()
					13) dumpDrinkItemSimple()
					14) dumpDrinkItem()
					15) dumpDrinkMachine()
					16) dumpDrinkItemForBuyer()
					17) dumpDrinkMachineForBuyer() */

#include "drinkMachine.h"	// header file containing the function prototypes, struct definitions, and enum definitions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// global constant for invalid array index
const int INVALID_INDEX = -1;



/*	Function 1:		create()
	Descr:			This function opens the input file and creates the DrinkItemArray in the DrinkMachine.
	Param:			None.
	Return:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure. */
struct DrinkMachine* create()
{
	// string (char array) for the input file name
	char inputFileName[100];
	// prompt for and read in inputFileName: the input file provided is ../drinks.txt
	printf("Enter input file name: ");
	fflush(stdout);
	scanf("%s", inputFileName);
	fflush(stdout);
	printf("\n");
	fflush(stdout);

	// create the necessary variables
	FILE * filePtr;
	int numDrinks;
	char drinkName[25];
	double drinkPrice = 0.0;
	int initialDrinkCount = 0;

	// dynamically allocate the DrinkMachine to memory
	struct DrinkMachine* ptrDrinkMachine = malloc(sizeof(struct DrinkMachine));

	// initialize the members of the DrinkMachine
	ptrDrinkMachine->versionNum = 1;
	ptrDrinkMachine->numDrinks = 0;
	ptrDrinkMachine->DrinkItemArray = NULL;
	ptrDrinkMachine->currentIndex = INVALID_INDEX;

	// open the input file and check that it opened properly
	if((filePtr = fopen (inputFileName, "r")) == NULL )
	{
		// destroy the memory allocated for DrinkMachine
		destroy(ptrDrinkMachine);
		printf ("There has been a file error.\n");
		fflush(stdout);

		return NULL;
	}
	// proceed with normal processing
	else
	{
		// read in the first number in the input file, the number of drinks
		fscanf(filePtr, "%d", &numDrinks);

		// allocate the array of DrinkItems in the DrinkMachine
		int memoryRequired = sizeof(struct DrinkItem) * numDrinks;
		struct DrinkItem* DrinkItemArray = malloc(memoryRequired);

		// dynamically allocate a DrinkItem to memory
		struct DrinkItem* ptrDrinkItem = malloc(sizeof(struct DrinkItem));
		// read every DrinkItem from the input file
		for(int i = 0; i < numDrinks; i++)
		{
			fscanf(filePtr, "%s%lf%d", drinkName, &drinkPrice, &initialDrinkCount);
			// call the DrinkItem_create() function (use index+1 as the drinkID)
			ptrDrinkItem = DrinkItem_create(i + 1,drinkName,drinkPrice,initialDrinkCount);

			// de-reference each DrinkItem and store it into the array
			DrinkItemArray[i] = *ptrDrinkItem;
		}

		// provide the numDrinks and DrinkItemArray members with their proper contents
		ptrDrinkMachine->numDrinks = numDrinks;
		ptrDrinkMachine->DrinkItemArray = DrinkItemArray;

		// close the input file
		fclose(filePtr);
		return ptrDrinkMachine;
	}
}



/*	Function 2:		DrinkItem_create()
	Descr:			This function creates the DrinkItem by allocating it to memory.
	Param:			int drinkID, char* drinkName, double drinkPrice, int initialDrinkCount
					Variables from the input file indicating a DrinkItem's ID number, string for its name, decimal price, and amount in stock.
	Return:			struct DrinkItem* ptrDrinkItem
					A pointer to a dynamically-allocated DrinkItem structure. */
struct DrinkItem* DrinkItem_create(int drinkID, char* drinkName, double drinkPrice, int initialDrinkCount)
{
	// allocate the DrinkMachine to memory
	struct DrinkItem* ptrDrinkItem = malloc(sizeof(struct DrinkItem));

	// verify that the memory has been allocated successfully
	assert(ptrDrinkItem != NULL);
	// initialize the members of the DrinkItem
	ptrDrinkItem->drinkID = drinkID;
	ptrDrinkItem->drinkName = strdup(drinkName);
	ptrDrinkItem->drinkPrice = drinkPrice;
	ptrDrinkItem->drinkCount = initialDrinkCount;
	ptrDrinkItem->drinksSold = 0;

	return ptrDrinkItem;
}



/*	Function 3:		DrinkItem_destroy()
	Descr:			This function destroys the DrinkItem by freeing it from memory.
	Param:			struct DrinkItem* ptrDrinkItem
					A pointer to a dynamically-allocated DrinkItem structure.
	Return:			None. */
void DrinkItem_destroy(struct DrinkItem* ptrDrinkItem)
{
	// verify that the DrinkMachine has been allocated to memory to begin with
	assert(ptrDrinkItem != NULL);
	// first free the char array (the string) within the pointer
	free(ptrDrinkItem->drinkName);
	// then free the pointer itself
	free(ptrDrinkItem);
}



/*	Function 4:		DrinkMachine_create()
	Descr:			This function creates the DrinkMachine by allocating it to memory.
	Param:			int numDrinks, struct DrinkItem* DrinkItemArray
					Variables whose values are used to initialize the members of the DrinkMachine structure.
	Return:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure. */
struct DrinkMachine* DrinkMachine_create(int numDrinks, struct DrinkItem* DrinkItemArray)
{
	// allocate the DrinkMachine to memory
	struct DrinkMachine* ptrDrinkMachine = malloc(sizeof(struct DrinkMachine));

	// verify that the memory has been allocated successfully
	assert(ptrDrinkMachine != NULL);
	// initialize the members of the DrinkMachine
	ptrDrinkMachine->versionNum = 1;
	ptrDrinkMachine->numDrinks = numDrinks;
	ptrDrinkMachine->DrinkItemArray = DrinkItemArray;
	ptrDrinkMachine->currentIndex = INVALID_INDEX;

	return ptrDrinkMachine;
}



/*	Function 5:		destroy()
	Descr:			This function destroys the DrinkMachine by freeing it from memory.
	Param:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure.
	Return:			None. */
void destroy(struct DrinkMachine* ptrDrinkMachine)
{
	// verify that the DrinkMachine has been allocated to memory to begin with
	assert(ptrDrinkMachine != NULL);
	// first free the array within the pointer
	free(ptrDrinkMachine->DrinkItemArray);
	// then free the pointer itself
	free(ptrDrinkMachine);
}



/*	Function 6:		firstDrink()
	Descr:			This function accesses the currentIndex member of the DrinkMachine and sets it to 0 (ie. the first drink).
					This function is used in every for() loop header that increments through the DrinkMachine.
					It is used to initialize the pointer counter in those for() loops.
	Param:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure.
	Return:			struct DrinkItem* or NULL
					An unnamed pointer to the first DrinkItem in DrinkItemArray, or NULL if there is no first item. */
struct DrinkItem* firstDrink(struct DrinkMachine* ptrDrinkMachine)
{
	// if numDrinks (the DrinkItemArray size) < 1, meaning the array has no elements
	if(ptrDrinkMachine->numDrinks < 1)
	{
		// since there are no array elements, the array index is set to INVALID_INDEX
		ptrDrinkMachine->currentIndex = INVALID_INDEX;
		return NULL;
	}
	// if there is a valid value of numDrinks
	else
	{
		// initialize the currentIndex member of the DrinkMachine to 0
		ptrDrinkMachine->currentIndex = 0;
		// return a pointer to the first byte of the first element of DrinkItemArray
		return ptrDrinkMachine->DrinkItemArray;
	}
}



/*	Function 7:		nextDrink()
	Descr:			This function increments the currentIndex member of the DrinkMachine.
					This function is used in every for() loop header that increments through the DrinkMachine.
					It is used to increment the pointer counter in those for() loops.
	Param:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure.
	Return:			struct DrinkItem* or NULL
					An unnamed pointer to the next DrinkItem in DrinkItemArray, or NULL if there is no next item. */
struct DrinkItem* nextDrink(struct DrinkMachine* ptrDrinkMachine)
{
	// initialize currentIndex to the current index stored in the DrinkMachine
	int currentIndex = ptrDrinkMachine->currentIndex;

	// if currentIndex == -1, then that means numDrinks == 0 in the first if-block of firstDrink()
	if(currentIndex == INVALID_INDEX)
	{
		return NULL;
	}
	// if currentIndex is a valid index
	else
	{
		// update currentIndex
		currentIndex++;
		// if currentIndex exceeds numDrinks (the DrinkItemArray size), then the end of the array has been reached and currentIndex is reset
		if(currentIndex >= ptrDrinkMachine->numDrinks)
		{
			ptrDrinkMachine->currentIndex = INVALID_INDEX;
			return NULL;
		}
		// if currentIndex is still a valid index within the array's bounds
		else
		{
			// the currentIndex member in the DrinkMachine is updated
			ptrDrinkMachine->currentIndex = currentIndex;
			// the address of this currentIndex is returned
			return &(ptrDrinkMachine->DrinkItemArray[currentIndex]);
		}
	}
}



/*	Function 8:		items()
	Descr:			This function retrieves the numDrinks member of a valid DrinkItem.
	Param:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure.
	Return:			int n
					The numDrinks member field of the DrinkMachine. */
int items(struct DrinkMachine* ptrDrinkMachine)
{
	int n = ptrDrinkMachine->numDrinks;
	return n;
}



/*	Function 9:		cost()
	Descr:			This function retrieves the drinkPrice member of a valid DrinkItem.
					It is called by the purchase() function.
	Param:			struct DrinkMachine* ptrDrinkMachine, int drinkID
					A pointer to a dynamically-allocated DrinkMachine structure, and the drinkID of a DrinkItem in the DrinkMachine.
	Return:			double c
					The drinkPrice member field of the DrinkItem. */
double cost(struct DrinkMachine* ptrDrinkMachine, int drinkID)
{
	// initialized to invalid value
	double c = -2.0;

	for(struct DrinkItem* ptrDrinkItem = firstDrink(ptrDrinkMachine); ptrDrinkItem != NULL; ptrDrinkItem = nextDrink(ptrDrinkMachine))
	{
		// if the drinkID is valid
		if(drinkID == ptrDrinkItem->drinkID)
		{
			// retrieves drinkPrice
			c = ptrDrinkItem->drinkPrice;
			return c;
		}
	}
	// if the drinkID is not valid
	c = -1.0;
	return c;
}



/*	Function 10:	available()
	Descr:			This function retrieves the drinkCount member of a valid DrinkItem
					and returns a DrinkAvailability enum that corresponds 
					to whether there is enough of the drink (at least 1) to be purchased.
					It is called by the purchase() function.
	Param:			struct DrinkMachine* ptrDrinkMachine, int drinkID
					A pointer to a dynamically-allocated DrinkMachine structure, and the drinkID of a DrinkItem in the DrinkMachine.
	Return:			enum DrinkAvailability{3 options}
					1 of the 3 options listed in the DrinkAvailability enumeration. */
enum DrinkAvailability available(struct DrinkMachine* ptrDrinkMachine, int drinkID)
{
	int drinkCount = -1;
	for(struct DrinkItem* ptrDrinkItem = firstDrink(ptrDrinkMachine); ptrDrinkItem != NULL; ptrDrinkItem = nextDrink(ptrDrinkMachine))
	{
		// if the drinkID is valid
		if(drinkID == ptrDrinkItem->drinkID)
		{
			// retrieves drinkCount
			drinkCount = ptrDrinkItem->drinkCount;
			// if there is at least 1 of this drink
			if(drinkCount >= 1)
			{
				return AVAILABLE;
			}
			// the drinkID was valid, but there is not at least 1 of this drink
			else
			{
				return VALID_SELECTION_BUT_OUT;
			}
		}
	}
	// if the drinkID is invalid
	return INVALID_SELECTION;
}



/*	Function 11:	sell()
	Descr:			This function handles the incrementation of drinksSold and the decrementation of drinkCount 
					(assuming that a successful purchase has been made). 
					It is called by the purchase() function.
	Param:			struct DrinkMachine* ptrDrinkMachine, int drinkID
					A pointer to a dynamically-allocated DrinkMachine structure, and the drinkID of a DrinkItem in the DrinkMachine.
	Return:			None. */
void sell(struct DrinkMachine* ptrDrinkMachine, int drinkID)
{
	for(struct DrinkItem* ptrDrinkItem = firstDrink(ptrDrinkMachine); ptrDrinkItem != NULL; ptrDrinkItem = nextDrink(ptrDrinkMachine))
	{
		if(drinkID == ptrDrinkItem->drinkID)
		{
			ptrDrinkItem->drinksSold++;
			ptrDrinkItem->drinkCount--;
			return;
		}
	}
}



/*	Function 12:	purchase()
	Descr:			This function figures out if a buyer can make the purchase they request for.
					It returns 2 things: the enum for this purchase (through its return type) and the buyer's change, if any (through a pointer to the change).
					It calls the cost(), available(), and sell() functions to determine whether the purchase can be made.
	Param:			struct DrinkMachine* ptrDrinkMachine, int drinkID, double customerPayment, double* ptrChange
					A pointer to a dynamically-allocated DrinkMachine structure, the drinkID of a DrinkItem in the DrinkMachine,
					the decimal value of the customer's payment amt, and a pointer to the calculated change for the customer.
	Return:			enum Purchase{4 options}
					1 of the 4 options listed in the Purchase enumeration. */
enum Purchase purchase(struct DrinkMachine* ptrDrinkMachine, int drinkID, double customerPayment, double* ptrChange)
{
	// call cost() to determine the costOfDrink
	double costOfDrink = cost(ptrDrinkMachine, drinkID);
	// call available() to determine the drinkAvailability
	enum DrinkAvailability drinkAvailability = available(ptrDrinkMachine, drinkID);

	// if the drink is availabe
	if(drinkAvailability == AVAILABLE )
	{
		// if the customer paid >= than the cost, they require >= 0 in change
		if(customerPayment >= costOfDrink)
		{
			// de-reference and calculate change
			*ptrChange = customerPayment - costOfDrink;
			// call sell() for the necessary incrementations and decrementations within the DrinkMachine structure
			sell(ptrDrinkMachine, drinkID);
			return PURCHASED;
		}
		// the customer paid < the cost
		else
		{
			// de-reference and allocate the costOfDrink to the change
			*ptrChange = costOfDrink;
			return INSUFFICIENT_FUNDS;
		}
	}
	// if the drink inputted is not a valid drink
	else if (drinkAvailability == INVALID_SELECTION)
	{
		return INVALID; //Purchase::INVALID;
	}
	// if drinkAvailability == VALID_SELECTION_BUT_OUT
	else
	{
		return NOT_AVAILABLE; //Purchase::NOT_AVAILABLE;
	}
}



/*	Function 13:	dumpDrinkItemSimple()
	Descr:			A simple version of dumpDrinkItem() for debugging purposes.
	Param:			struct DrinkItem* ptrDrinkItem
					A pointer to a dynamically-allocated DrinkItem structure.
	Return:			None. */
void dumpDrinkItemSimple(struct DrinkItem* ptrDrinkItem)
{
	if(ptrDrinkItem == NULL)
	{
		printf("DrinkItem: NULL\n");
		fflush(stdout);
	}
	else
	{
		printf("DrinkItem: %d %s %lf\n", ptrDrinkItem->drinkID, ptrDrinkItem->drinkName, ptrDrinkItem->drinkPrice);
		fflush(stdout);
	}
}



/*	Function 14:	dumpDrinkItem()
	Descr:			This function dumps all members of a single DrinkItem.
	Param:			struct DrinkItem* ptrDrinkItem
					A pointer to a dynamically-allocated DrinkItem structure.
	Return:			None. */
void dumpDrinkItem(struct DrinkItem* ptrDrinkItem)
{
	if(ptrDrinkItem == NULL)
	{
		printf("DrinkItem: NULL\n");
		fflush(stdout);
	}
	else
	{
		printf("%2d %15s %5.2lf %3d %4d\n", ptrDrinkItem->drinkID, ptrDrinkItem->drinkName, ptrDrinkItem->drinkPrice, ptrDrinkItem->drinkCount, ptrDrinkItem->drinksSold);
		fflush(stdout);

	}
}



/*	Function 15:	dumpDrinkMachine()
	Descr:			This function dumps all members of every DrinkItem in the DrinkMachine array.
	Param:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure.
	Return:			None. */
void dumpDrinkMachine(struct DrinkMachine* ptrDrinkMachine)
{
	printf("%2s %15s %5s %3s %4s\n", "Id", "Name", "Price", "Qty", "Sold");
	fflush(stdout);

	for(struct DrinkItem* ptrDrinkItem = firstDrink(ptrDrinkMachine); ptrDrinkItem != NULL; ptrDrinkItem = nextDrink(ptrDrinkMachine))
	{
		dumpDrinkItem(ptrDrinkItem);
	}

}



/*	Function 16:	dumpDrinkItemForBuyer()
	Descr:			This function accesses a single DrinkItem and prints its members for the buyer to use.
	Param:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure.
	Return:			None. */
void dumpDrinkItemForBuyer(struct DrinkItem* ptrDrinkItem)
{
	if(ptrDrinkItem == NULL)
	{
		printf("DrinkItem: NULL\n");
		fflush(stdout);
	}
	else
	{
		printf("%8d %15s  $ %5.2lf\n", ptrDrinkItem->drinkID, ptrDrinkItem->drinkName, ptrDrinkItem->drinkPrice);
		fflush(stdout);

	}
}



/*	Function 17:	dumpDrinkMachineForBuyer()
	Descr:			This function prints the version of the drink machine's contents that the buyer will use.
	Param:			struct DrinkMachine* ptrDrinkMachine
					A pointer to a dynamically-allocated DrinkMachine structure.
	Return:			None. */
void dumpDrinkMachineForBuyer(struct DrinkMachine* ptrDrinkMachine)
{
	printf("%8s %15s  $ %5s\n", "Drink Id", "Drink", "Price");
	fflush(stdout);

	for(struct DrinkItem* ptrDrinkItem = firstDrink(ptrDrinkMachine); ptrDrinkItem != NULL; ptrDrinkItem = nextDrink(ptrDrinkMachine))
	{
		dumpDrinkItemForBuyer(ptrDrinkItem);
	}

}