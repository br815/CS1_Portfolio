/*	Author:			            Bushra Rahman
	Course:			            CS 1337 (Fall 2019)
	Date:			            12/5/2019
	AbstractObserver.h:	    	This header file contains the definition of the AbstractObserver class.
								This class is the abstract base class from which the BankObserver, CreditObserver, and SchoolObserver classes are derived. */

// header for #include guard (preprocessor directives)
#ifndef ABSTRACTOBSERVER_H_		// if ABSTRACTOBSERVER_H_ is not defined, define it (start of header guard)
#define ABSTRACTOBSERVER_H_		// define ABSTRACTOBSERVER_H_ once to prevent multiple inclusions
#include <string>
using namespace std;

class AbstractObserver
{
private:
	static int observerCount; // static member variable
	int observerID;           // designation of the object's number in order of creation
public:
	// inline constructor
	AbstractObserver()
	{
		// assigns the ID to the AbstractObserver object
		observerID = observerCount++;
	}

	// inline destructor
	virtual ~AbstractObserver(){}

	// inline getter for observerID
	int getObserverID() const
	{
		return observerID;
	}

	// overloaded == operator
	bool operator == (const AbstractObserver & otherObserver) const
	{
		// uses observerID to check whether two objects are equal
		if(this->observerID == otherObserver.observerID)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// pure virtual function
	virtual void subjectChanged(string) = 0;
};

#endif							// end of "if not defined" ifndef block