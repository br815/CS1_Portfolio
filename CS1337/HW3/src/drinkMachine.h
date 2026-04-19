/*	Author:		    Bushra Rahman
	Course:		    CS 1337 (Fall 2019)
	Date:			10/8/2019
	drinkMachine.h:	This header file contains the function prototypes, struct definitions, and enum definitions for this project. */

// header for #include guard (preprocessor directives)
#ifndef DRINKMACHINE_H		// if DRINKMACHINE_H is not defined, define it (start of header guard)
#define DRINKMACHINE_H		// define DRINKMACHINE_H once to prevent multiple inclusions

// 2 STRUCTURE DEFINITIONS
// definition of a DrinkItem structure
struct DrinkItem
{
	// index of a drink in the list of drinks
	int drinkID;
	// char array (string) for the drink's name
	char* drinkName;
	// cost of the drink
	double drinkPrice;
	// the number in stock of this type of drink
	int drinkCount;
	// the number sold of this type of drink
	int drinksSold;
};

// definition of a DrinkMachine structure
struct DrinkMachine
{
	// a version number (for this project, it is 1)
	int versionNum;
	// the number of DrinkItems in this DrinkMachine
	int numDrinks;
	// an array of those DrinkItems
	struct DrinkItem* DrinkItemArray;
	// the current index in the DrinkItemArray
	int currentIndex;
};



// 2 ENUMERATION DEFINITIONS
enum DrinkAvailability {AVAILABLE = 1, VALID_SELECTION_BUT_OUT = 0, INVALID_SELECTION = -1 };
enum Purchase {PURCHASED = 1, INVALID = -1, NOT_AVAILABLE = 0, INSUFFICIENT_FUNDS = -2 };



// 17 HELPER FUNCTION PROTOTYPES
struct DrinkMachine* create();
struct DrinkItem *DrinkItem_create(int drinkID, char *drinkName, double drinkPrice, int initialDrinkCount);
void DrinkItem_destroy(struct DrinkItem *ptrDrinkItem);
struct DrinkMachine *DrinkMachine_create(int numDrinks, struct DrinkItem *DrinkItemArray);
void destroy(struct DrinkMachine *ptrDrinkMachine);
struct DrinkItem *firstDrink(struct DrinkMachine*);
struct DrinkItem *nextDrink(struct DrinkMachine*);
int items(struct DrinkMachine*);
double cost(struct DrinkMachine*, int drinkID);
enum DrinkAvailability available(struct DrinkMachine*, int drinkID);
void sell(struct DrinkMachine* ptrDrinkMachine, int drinkID);
enum Purchase purchase(struct DrinkMachine*, int drinkID, double customerPayment, double* ptrChange);
void dumpDrinkItemSimple(struct DrinkItem*);	// dumpDrinkItemSimple() exists for debugging only
void dumpDrinkItem(struct DrinkItem *ptrDrinkItem);
void dumpDrinkMachine(struct DrinkMachine* ptrDrinkMachine);
void dumpDrinkItemForBuyer(struct DrinkItem* ptrDrinkItem);
void dumpDrinkMachineForBuyer(struct DrinkMachine* ptrDrinkMachine);

// 2 FUNCTION PROTOTYPES FOR DRIVER FUNCTIONS
void drinkMachineDriver();
int testDriver();

#endif						// end of "if not defined" ifndef block