/*	Author:		    Bushra Rahman
	Course:		    CS 1337 (Fall 2019)
	Date:			9/5/2019
	amortize.h:     This header file contains the contains the prototype for the amortize function. */

// header for #include guard (preprocessor directives)
#ifndef AMORTIZE_H_		// if AMORTIZE_H_ is not defined, define it (start of header guard)
#define AMORTIZE_H_		// define AMORTIZE_H_ once to prevent multiple inclusions
#include <fstream>
using namespace std;

void amortize(double loanAmt, double annualInterestRate, double monthlyPayment, ofstream & outputFile);

#endif					// end of "if not defined" ifndef block