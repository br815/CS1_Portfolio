/*	Author:		    		Bushra Rahman
	Course:		    		CS 1337 (Fall 2019)
	Date:					10/8/2019
	testDriver.c:			This source file contains a test driver for debugging purposes only. */

#include "drinkmachine.h"		// header file containing the function prototypes, struct definitions, and enum definitions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// test driver body can be commented out when compiling & executing project
int testDriver(void)
{
	//Test *test;
	//test = create();
	//printf("**%d**\n",test->i);
	fflush(stdout);

	struct DrinkMachine *ptrDrinkMachine = create();

	struct DrinkItem *ptrDrinkItem = firstDrink(ptrDrinkMachine);
	dumpDrinkItemSimple(ptrDrinkItem);

	printf("gonna call nextdrink\n");
	fflush(stdout);
	ptrDrinkItem = nextDrink(ptrDrinkMachine);
	dumpDrinkItemSimple(ptrDrinkItem);

	printf("gonna call nextdrink again\n");
	fflush(stdout);
	ptrDrinkItem = nextDrink(ptrDrinkMachine);
	dumpDrinkItemSimple(ptrDrinkItem);


	enum DrinkAvailability av = available( ptrDrinkMachine, 1);
	printf("av=%d\n", av);
	fflush(stdout);

	double c = cost( ptrDrinkMachine, 1);
	printf("cost=%lf\n", c);
	fflush(stdout);

	double change;
	enum Purchase purch = purchase(ptrDrinkMachine, 1, 5.0, &change);
	printf("purch=%d  Change=%lf\n", purch, change);
	fflush(stdout);

	purch = purchase(ptrDrinkMachine, 1, 1.25, &change);
	printf("purch=%d  Change=%lf\n", purch, change);
	fflush(stdout);

	purch = purchase(ptrDrinkMachine, 1, 5.0, &change);
	printf("purch=%d  Change=%lf\n", purch, change);
	fflush(stdout);

	dumpDrinkMachineForBuyer(ptrDrinkMachine);



	destroy(ptrDrinkMachine);



	return EXIT_SUCCESS;
}
