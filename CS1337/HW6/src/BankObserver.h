/*	Author:			            Bushra Rahman
	Course:			            CS 1337 (Fall 2019)
	Date:			            12/5/2019
	BankObserver.h:	    		This header file contains the class definition for BankObserver, extended from AbstractObserver. */

// header for #include guard (preprocessor directives)
#ifndef BANKOBSERVER_H_			// if BANKOBSERVER_H_ is not defined, define it (start of header guard)
#define BANKOBSERVER_H_			// define BANKOBSERVER_H_ once to prevent multiple inclusions
#include "AbstractObserver.h"	// include the header file for the base class
#include <string>
#include <iostream>

using namespace std;

class BankObserver : public AbstractObserver
{
public:
	// overridden virtual function from AbstractObserver
	virtual void subjectChanged(string str)
	{
		cout << "object ID: " << getObserverID() << ". ";
		cout << "The BankObserver received an address change notification: <" << str << ">" << endl;
	}

	// inline destructor
	virtual ~BankObserver(){}
};

#endif							// end of "if not defined" ifndef block