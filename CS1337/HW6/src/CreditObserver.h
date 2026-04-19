/*	Author:			            Bushra Rahman
	Course:			            CS 1337 (Fall 2019)
	Date:			            12/5/2019
	CreditObserver.h:	    	This header file contains the class definition for CreditObserver, extended from AbstractObserver. */

// header for #include guard (preprocessor directives)
#ifndef CREDITOBSERVER_H_		// if CREDITOBSERVER_H_ is not defined, define it (start of header guard)
#define CREDITOBSERVER_H_		// define CREDITOBSERVER_H_ once to prevent multiple inclusions
#include "AbstractObserver.h"	// include the header file for the base class
#include <string>
#include <iostream>
using namespace std;

class CreditObserver : public AbstractObserver
{
public:
	// overridden virtual function from AbstractObserver
	virtual void subjectChanged(string str)
	{
		cout << "object ID: " << getObserverID() << ". ";
		cout << "The CreditObserver received an address change notification: <" << str << ">" << endl;
	}

	// inline destructor
	virtual ~CreditObserver(){}
};

#endif							// end of "if not defined" ifndef block