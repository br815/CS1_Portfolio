/*	Author:		    		Bushra Rahman
	Course:		    		CS 1337 (Fall 2019)
	Date:					10/8/2019
	drinkMachineDriver.c:	This source file is the main driver of the program. It contains 1 helper function in addition to main(). */

#include "drinkMachine.h"		// header file containing the function prototypes, struct definitions, and enum definitions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



/*	Function 1:		main()
	Descr:			This function simply calls the driver function.
	Param:			None.
	Return:			None. */
int main(void)
{
	drinkMachineDriver();
	
}



/*	Function 2:		drinkMachineDriver()
	Descr:			This function is the driver function called by main().
	Param:			None.
	Return:			None. */
void drinkMachineDriver()
{
	// create a DrinkMachine
	struct DrinkMachine* ptrDrinkMachine = create();

	// verify that the memory has been allocated successfully
	assert(ptrDrinkMachine != NULL);

	// print the full contents of the DrinkMachine
	dumpDrinkMachine(ptrDrinkMachine);

	// the option picked by the user
	int option = -1;
	// call items to retrieve the number of DrinkItems in the DrinkMachine
	int numDrinks = items(ptrDrinkMachine);
	// the amount paid by the user
	double amountForPurchase = -1.0;
	// used to store the return value of the purchase() function
	enum Purchase purch;
	// the cost of the drink picked by the user
	double costOfDrink = -1.0;
	// flag
	int askForPurchaseAmount = 1;
	// amount in change
	double changeAmount = -1.0;

	// while the user does not select the option to quit
	while(option != 0)
	{
		// print the prompt
		printf("Enter a drink ID for the drink you want to purchase or 0 to quit.\n");
		fflush(stdout);

		// print the version of the drink machine's contents for the buyer to use
		dumpDrinkMachineForBuyer(ptrDrinkMachine);

		// read in the user's option
		scanf("%d", &option);

		// if the option entered is not one listed in the DrinkMachine
		if(option < 0 || option > numDrinks)
		{
			printf("The drink ID is not valid.\n");
			fflush(stdout);
		}
		// if the user chose to quit
		else if (option == 0)
		{
			continue;
		}
		// the user chose a valid drinkID
		else
		{
			// call the cost() function on the drink chosen
			costOfDrink = cost(ptrDrinkMachine, option);

			// set flag to true
			askForPurchaseAmount = 1;
			// while the flag is true, the user must be prompted again for their purchase amount
			while(askForPurchaseAmount == 1)
			{
				// prompt for the user's payment and read it in
				printf("Enter the amount for the purchase (up to $2.00): ");
				fflush(stdout);
				scanf("%lf", &amountForPurchase);

				// if the user's payment isn't enough to purchase the drink
				if(amountForPurchase < costOfDrink)
				{
					printf("The amount you entered is insufficient to purchase the drink. The price is %4.2lf\n", costOfDrink);
					fflush(stdout);
					// break because the user doesn't have the money for this drink
					break;
				}
				// if the user's payment is more than the maxiumum valid amount, $2.00
				else if(amountForPurchase > 2.0)
				{
					printf("The amount entered is not valid.\n");
					fflush(stdout);
					// continue because the user does have enough money for this drink, and simply needs to re-enter it (and is thus re-prompted for it)
					continue;
				}
				// if the user has entered a valid payment amount
				else
				{
					// set the flag to false, so the inner while loop is broken
					askForPurchaseAmount = 0;
				}
			} // end of inner while loop

			// call the purchase() function on the user's chosen drink
			purch = purchase(ptrDrinkMachine, option, amountForPurchase, &changeAmount);

			// if the purchase was successful
			if(purch == PURCHASED)
			{
				// if the buyer has some change to get back
				if(changeAmount > 0)
				{
					printf("Your drink has been purchased. Your change is $ %4.2lf\n", changeAmount);
					fflush(stdout);
				}
				// if the buyer paid exactly the cost of the drink, meaning they have no change to get back
				else
				{
					printf("Your drink has been purchased.\n");
					fflush(stdout);

				}
			}
			// if the purchase was unsuccessful because of the chosen drink is not available
			else if (purch == NOT_AVAILABLE)
			{
				printf("Sorry, we are out of your drink. Please select another drink.\n");
				fflush(stdout);
			}
		}
	}

	// print the full contents of the DrinkMachine
	dumpDrinkMachine(ptrDrinkMachine);

	printf("\nThank you for using the drink machine.\n");
	fflush(stdout);
}