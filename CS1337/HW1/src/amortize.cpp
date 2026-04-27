/*	Author:			Bushra Rahman
	Course:			CS 1337 (Fall 2019)
	Date:			9/5/2019
	amortize.cpp:	This source file contains the definition of the amortize function.
					The arguments of this function are the output file and the three pieces of data about a single loan payment.
					The function calculates the number of payments,
					the amount of each payment,
					the interest and principal paid with each payment,
					and account balance.
					It displays all this data as a table in both the output console and an output file.
					The function is void and returns no data. */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include "amortize.h"	// header file containing the amortize function prototype
using namespace std;



void amortize(double loanAmt, double annualInterestRate, double monthlyPayment, ofstream & outputFile)
{
	// set precision to 2 places after the decimal in both the console and output file
	cout << fixed << setprecision(2) << endl << endl << endl;
	outputFile << fixed << setprecision(2) << endl << endl << endl;

	// print the first 3 lines of information to the output console
	cout << "Starting Balance: $" << loanAmt << endl;
	cout << "Annual Interest Rate: " << annualInterestRate << endl;
	cout << "Monthly Payment: $" << monthlyPayment << endl << endl;

	// write the first 3 lines of information to the output file
	outputFile << "Starting Balance: $" << loanAmt << endl;
	outputFile << "Annual Interest Rate: " << annualInterestRate << endl;
	outputFile << "Monthly Payment: $" << monthlyPayment << endl << endl;


	// print the table headers to the output console
	cout << "Payment" << "     " << "Amount" << "     " << "Interest" << "     " << "Principal" << "     " << "Balance" << endl;

	// write the table headers to the output file
	outputFile << "Payment" << "     " << "Amount" << "     " << "Interest" << "     " << "Principal" << "     " << "Balance" << endl;



	double monthlyInterestRate = annualInterestRate / 12.0;	// calculate the monthly interest rate
	int paymentNum = 0;										// the number of payments made
	double paymentAmtForThisMonth = monthlyPayment;			// the payment made for a given month (could be different from monthlyPayment for the last month)
	double balance = loanAmt;								// account balance after each payment
	double interestPaid = 0.0;								// amount paid towards interest
	double principalPaid = 0.0;								// amount paid towards principal
	double totalInterestPaid = 0.0;							// running total of payments towards interest
	bool errorOcurred = false;								// flag to make sure that the monthly payment amount is more than the monthly interest amount

	// check that the current balance is greater than the monthly payment, since that may not be the case for the last month
	while(balance >= monthlyPayment)
	{
		/*	Converted to pennies to be rounded properly,
			rounded down so that interestPaid isn't inaccurately larger than the actual interest paid,
			and then converted back to dollars. */
		interestPaid = floor(balance * monthlyInterestRate * 100)/100.0;

		if(interestPaid >= monthlyPayment)
		{
			errorOcurred = true;
			cout << "***Error: Monthly payment amount must be greater than the monthly interest amount, which is $" << interestPaid << endl;
			break;
		}
		else
		{
			paymentNum++;
			principalPaid = paymentAmtForThisMonth - interestPaid;
			balance = balance - principalPaid;
			totalInterestPaid = totalInterestPaid + interestPaid;

			// print the entries to the table in the output console
			cout << left << setw(12) << paymentNum;
			cout << left << setw(11) << paymentAmtForThisMonth;
			cout << left << setw(13) << interestPaid;
			cout << left << setw(14) << principalPaid;
			cout << left << setw(5) << balance << endl;

			// write the entries to the table in the output file
			outputFile << left << setw(12) << paymentNum;
			outputFile << left << setw(11) << paymentAmtForThisMonth;
			outputFile << left << setw(13) << interestPaid;
			outputFile << left << setw(14) << principalPaid;
			outputFile << left << setw(5) << balance << endl;
		}
	}



	// if at this point the balance is still greater than 0, then that means the final payment is less than monthlyPayment and requires different calculations
	if(balance > 0 && errorOcurred == false)
	{
		paymentNum++;

		// for this final payment, the previous payment's balance is the current principal paid, and the balance is paid off in full
		principalPaid = balance;
		interestPaid = floor(balance * monthlyInterestRate * 100)/100.0;
		paymentAmtForThisMonth = principalPaid + interestPaid;
		balance = 0.00;
		totalInterestPaid = totalInterestPaid + interestPaid;

		// print the entries to the table in the output console
		cout << left << setw(12) << paymentNum;
		cout << left << setw(11) << paymentAmtForThisMonth;
		cout << left << setw(13) << interestPaid;
		cout << left << setw(14) << principalPaid;
		cout << left << setw(5) << balance << endl;

		// write the entries to the table in the output file
		outputFile << left << setw(12) << paymentNum;
		outputFile << left << setw(11) << paymentAmtForThisMonth;
		outputFile << left << setw(13) << interestPaid;
		outputFile << left << setw(14) << principalPaid;
		outputFile << left << setw(5) << balance << endl;
	}



	// print the last two lines of information to the output console
	cout << endl;
	cout << "Total Payments Made: " << paymentNum << endl;
	cout << "Total Interest Paid: $" << totalInterestPaid << endl << endl << endl;

	// write the last two lines of information to the output file
	outputFile << endl;
	outputFile << "Total Payments Made: " << paymentNum << endl;
	outputFile << "Total Interest Paid: $" << totalInterestPaid << endl << endl << endl;
}