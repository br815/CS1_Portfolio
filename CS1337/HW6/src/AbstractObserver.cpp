/*	Author:			            Bushra Rahman
	Course:			            CS 1337 (Fall 2019)
	Date:			            12/5/2019
	AbstractObserver.cpp:	    This source file is where the static variable observerCount is defined for the AbstractObserver abstract base class. */

#include "AbstractObserver.h"   // include the header file for this abstract base class
#include <iostream>
using namespace std;

// initializes static int observerCount
int AbstractObserver::observerCount = 0;