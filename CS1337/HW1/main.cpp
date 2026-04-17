/*	Author:			Bushra Rahman
	Course:			CS 1337 (Fall 2019)
   Date:          9/5/2019
	main.cpp:      This is the main source file.
                  It creates and opens an input file, which contains the amortization data, 
                  and an output file, which will be written to with the amortization schedules generated from each set of data. */

#include <iostream>
#include <fstream>
#include <string>
#include "amortize.h"   // header file containing the amortize function prototype
using namespace std;



int main()
{
   // create the input file and its name
   ifstream inputFile;
   string inputFileName;

   // create the output file and its name
   ofstream outputFile;
   string outputFileName;

   // prompt user for input file, read it in, and display it for debug purposes
   cout << "Please enter the input file name: ";
   cin >> inputFileName;
   cout << "User entered input file name as: " << inputFileName << endl << endl;

   // prompt user for output file, read it in, and display it for debug purposes
   cout << "Please enter the output file name: ";
   cin >> outputFileName;
   cout << "User entered output file name as: " << outputFileName << endl;



   int numLoans = 0;                   // the first number in the input file, denoting the number of amortization schedules that need to be generated
   double loanAmt = 0.0;               // the 1st number in every subsequent set of 3 numbers, denoting the principal loan amount/starting balance
   double annualInterestRate = 0.0;    // the 2nd number in every subsequent set of 3 numbers, denoting the annual interest rate
   double monthlyPayment = 0.0;        // the 3rd number in every subsequent set of 3 numbers, denoting the monthly payment

   // open the input file
   inputFile.open(inputFileName);

   if (inputFile)
   {
	   // open the output file
	     outputFile.open(outputFileName);

	     if (outputFile)
	     {
	    	 // read in the first number, the number of amortization schedules to be generated
	    	 inputFile >> numLoans;

	    	 // for each set of 3 numbers (one set of amortization data), generate one schedule
	         for (int currentLoan = 0; currentLoan < numLoans; currentLoan++)
	         {
	        	 // read in the 3 numbers and call the amortize function on them
	        	 inputFile >> loanAmt >> annualInterestRate >> monthlyPayment;
	        	 amortize(loanAmt,annualInterestRate,monthlyPayment,outputFile);
	         }
	         outputFile.close();
	     }
	      else
	      {
	         cout << "Error: File \"" << outputFileName << "\" could not be opened" << endl;
	      }

      inputFile.close();
   }
   else
   {
      cout << "Error: File \"" << inputFileName << "\" could not be opened" << endl;
   }

   return 0;
}