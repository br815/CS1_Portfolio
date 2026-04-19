/*	Author:				Bushra Rahman
	Course:				CS 1337 (Fall 2019)
	Date:				10/31/2019
	Aircraft-Test.cpp:	This source file is the main driver of the project. It contains 8 helper functions in addition to main(): 
						1) parseStringByDelimiter()
						2) parseString()
						3) stringBeforeComment()
						4) isPositiveInteger()
						5) hasDoubleQuotedText()
						6) readFileAndBuildAircraft()
						7) testAircraft()
						8) testAircraftClass() */

#include "PassengerAircraft.h"	// header file for the derived class PassengerAircraft
#include "AcrobatAircraft.h"	// header file for the derived class AcrobatAircraft
#include "FreightAircraft.h"	// header file for the derived class FreightAircraft

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <cstring>
#include <vector>

using namespace std;



/*	Function 1:		parseStringByDelimiter()
	Descr:			This function parses a string by a delimiter string. The parsed tokens are then pushed to a vector.
	Param:    		string theLine, vector<string *> &theList, string delimiter
					The string being parsed, the vector storing the parsed tokens, and the delimiter string.
	Return:			None. */
void parseStringByDelimiter(string theLine, vector<string *> &theList, string delimiter)
{

	// Make copy because original modified
	//theLine to buffer
	int length_of_original_string = theLine.length();
	char buffer[length_of_original_string+1];
	theLine.copy(buffer, length_of_original_string, 0);
	buffer[length_of_original_string]='\0';   // Add NULL

	// Make copy of delimiter for char *
	//delimiter to delim
	int length_of_original_delimiter = delimiter.length();
	char delim[length_of_original_delimiter+1];
	delimiter.copy(delim, length_of_original_delimiter, 0);
	delim[length_of_original_delimiter]='\0';   // Add NULL

	char * token;
	token = strtok(buffer, delim);
	///token = strtok(buffer, "\"");


	while(token != NULL)
	{
		///cout << "Token was: " << token << endl;
		theList.push_back(new string(token));			// new IMPORTANT
		token = strtok(NULL, delim);
	}
}



/*	Function 2:		parseStringByDelimiter()
	Descr:			Delimiter option should be one of the following values:
					1: default: blank space, tab, and comma
					2: blank space and tab
					3: blank space and comma
					4: double quote
	Param:    		string theLine, vector<string *> &theList, string delimiter
					The string being parsed, the vector storing the parsed tokens, and the delimiter string.
	Return:			None. */
void parseString(string theLine, vector<string *> &theList, int option)
{
	if(option == 4)
	{
		// parse by the double quote character
		parseStringByDelimiter(theLine, theList, "\"");
	}
	else if(option == 3)
	{
		// parse by the blank space and comma only
		parseStringByDelimiter(theLine, theList, " ,");
	}
	else if(option == 2)
	{
		// parse by the blank space and tab characters only
		parseStringByDelimiter(theLine, theList, " \t");
	}
	else
	{
		// parse by the blank space, tab, comma characters
		parseStringByDelimiter(theLine, theList, " \t,");
	}
}



/*	Function 3:		stringBeforeComment()
	Descr:			This function parses a string disregarding any text after a comment (//).
	Param:    		string& theLine
					Reference to a string that will be directly modified by this function.
	Return:			None. */
void stringBeforeComment(string& theLine)
{
	int index = (int) theLine.find("//");
	//cout << endl << "index = [" << index << "]";
	string beforeComment = "";

	if (index >= 0)
	{
		// the line contains the // character sequence, so discard everything after the first //
		beforeComment = theLine.substr(0, index);
		theLine = beforeComment;
	}
	//cout << endl << "theLine = [" << theLine << "]]";
}



/*	Function 4:		isPositiveInteger()
	Descr:			If str contains a valid, positive integer then that number will be stored in num.
					Will accept a decimal period if that is the only non-numeric character AND that is the last character of str.
					Example: 245. is true but 4.5, +4, -245. are not.
	Param:    		string str, int &num
					A string possibly containing a valid integer to parse for, and reference to the int storing the parsed integer.
	Return:			int returnValue
					Returned value is 0 if false, or  1 if true. */
int isPositiveInteger(string str, int &num)
{
	int returnValue = 0;
	if(str.find_first_not_of("0123456789") == std::string::npos)
	{
		// contains numeric character only
		num = stoi(str);
		returnValue = 1;
	}
	else
	{
		// includes non-numeric character
		//cout << endl << "stoi=" << str.find_first_not_of("0123456789") << " str =[" << str << "]";

		// if the first non-numeric character is just a decimal period at the end of a positive #, then accept it
		if(str.find_first_not_of("0123456789") == str.length()-1)
		{
			if(str.at(str.length()-1) == '.')
			{
				num = stoi(str);
				returnValue = 1;
			}
		}
	}

	return returnValue;
}



/*	Function 5:		hasDoubleQuotedText()
	Descr:			Checks if theLine has some text in between a pair of double quotes.
					If so, it returns 1 for true and also the text is stored in strDoubleQuotedText.
					It returns 0 for false and 1 for true.
	Param:    		string& theLine, string& strDoubleQuotedText
					Reference to a string that will be directly parsed by this function for a substring, 
					and reference to the string storing the parsed substring.
	Return:			int returnValue
					Returned value is 0 if false, or  1 if true. */
int hasDoubleQuotedText(string& theLine, string& strDoubleQuotedText)
{
	int returnValue = 0; // 0: false   1: true
	string rest = ""; //theLine.substr(firstPositionIndex+1, theLine.length()-1);

	size_t firstPositionIndex = theLine.find_first_of("\"");
	if(firstPositionIndex != std::string::npos)
	{
		// contains at least one "

		///cout << endl << "firstPositionIndex = [" << firstPositionIndex << "]";
		if(theLine.length() > firstPositionIndex+1)
		{
			//cout << endl << "has sufficient string length " << theLine.length();
			rest = theLine.substr(firstPositionIndex+1, theLine.length()-1);
			///cout << endl << "rest = [" << rest << "]";
			size_t secondPositionIndex = rest.find_first_of("\"");
			if(secondPositionIndex != std::string::npos)
			{
				strDoubleQuotedText = rest.substr(0, secondPositionIndex);
				returnValue = 1;
				///cout << endl << "strDoubleQuotedText = [" << strDoubleQuotedText << "]";

				// update theLine
				if(rest.length() > secondPositionIndex+1)
				{
					theLine = rest.substr(secondPositionIndex+1, rest.length()-1);
				}
				else
				{
					theLine = "";
				}
				///cout << endl << "Updated Line = [" << theLine << "]";
			}
		}
	}

	return returnValue;
}



/*	Function 6:		readFileAndBuildAircraft()
	Descr:			This function reads the contents of an input file and creates the Aircraft objects.
	Param:    		string inputFileName
					Name of input file containing commands to build various Aircraft objects.
	Return:			None. */
void readFileAndBuildAircraft(string inputFileName)
{
	// creates an input file stream object and opens it
	ifstream inputFilestream;

	string str1="";
	string str2="";

	inputFilestream.open(inputFileName);

	string theLine = "";
	int currentLine = 0;
	int currentDataLine = 0;
	int numberOfAircraftsPrinted = 0;

	int optionForParsing = -1;
	int aircraftType = -1;
	int numberOfEngines = -1;
	int seatCapacity = -1;

	// the input file was successfully opened
	if (inputFilestream)
	{

		// vector is created only if the input file is opened properly
		vector<Aircraft *> vectorOfAircraft;

		while (!inputFilestream.eof())
		{
			// reads blank lines, spaces, tabs...
			getline(inputFilestream, theLine);
			currentLine++;
			//cout << "Line " << currentLine << ": [" << rowContents <<"]" <<endl;

			stringBeforeComment(theLine);
			vector<string *> stringList;
			optionForParsing = 1; // space, tab and comma
			parseString(theLine, stringList, optionForParsing);
			if(stringList.size() == 0)
			{
				continue;
			}

			currentDataLine++;
			//cout << endl << "vector size is:" << stringList.size();

			if( *stringList[0] != "p" && *stringList[0] != "n")
			{
				cout << endl << "invalid command ["
						<< *stringList[0] <<
						"] at line " << currentLine;
				continue;
			}

			aircraftType = -1;
			numberOfEngines = -1;
			seatCapacity = -1;
			str1 = "";
			str2 = "";

			if(*stringList[0] == "p")
			{
				if(stringList.size() != 2)
				{
					cout << endl << "invalid # of arguments at line " << currentLine;
					continue;
				}
				else
				{
					aircraftType = -1;
					str2 = "";
					str2 = *stringList[1];
					if( isPositiveInteger(str2, aircraftType) == 0)
					{
						cout << endl << "Print Aircraft Type: Either non-numeric character or negative number [" << str2 << "] at line " << currentLine;
						continue;
					}
					//id = stoi(str2);
					//cout << endl << "DO PRINT _____ Aircraft Type =[" << aircraftType << "]" << endl;

					// print out the aircafts
					numberOfAircraftsPrinted = 0;
					if(aircraftType == 0)
					{
						// print ALL the aircrafts in the list
						for(unsigned int i = 0; i < vectorOfAircraft.size(); ++i)
						{
							cout << endl;
							vectorOfAircraft[i]->printCharacteristics();
							numberOfAircraftsPrinted++;
						}
					}
					else if(aircraftType >= 1 && aircraftType <= 3)
					{
						// print only specific type aircrafts
						for(unsigned int i = 0; i < vectorOfAircraft.size(); ++i)
						{
							if(vectorOfAircraft[i]->getAircraftType() == aircraftType)
							{
								cout << endl;
								vectorOfAircraft[i]->printCharacteristics();
								numberOfAircraftsPrinted++;
							}
						}
					}
					else
					{
						cout << endl << "Print *** Invalid Aircraft Type: " << aircraftType;
						continue;
					}

					// if nothing printed, tell user:
					if(numberOfAircraftsPrinted < 1)
					{
						cout << endl << "Print Aircraft Type: " << aircraftType << " *** Nothing to print";
					}
				} // end of if(stringList.size() != 2) else
				continue;
			} // end of if(*stringList[0] == "p")
	//------------- End of Print related stuff here


			if(*stringList[0] == "n")
			{
				if(stringList.size() < 4)
				{
					cout << endl << "Too few arguments at line " << currentLine;
					continue;
				}

				aircraftType = -1;
				numberOfEngines = -1;
				seatCapacity = -1;

				str2 = "";
				str2 = *stringList[1];
				if( isPositiveInteger(str2, aircraftType) == 0)
				{
					cout << endl << "Aircraft Type: Either non-numeric character or negative number [" << str2 << "] at line " << currentLine;
					continue;
				}

				if(aircraftType < 0 || aircraftType > 3)
				{
					cout << endl << "Aircraft type " << aircraftType << " is invalid. Line # " << currentLine;
				}

				//cout << endl << "aircraftType = [" << aircraftType << "]";
				if(aircraftType == 0 || aircraftType == 1 || aircraftType == 3)
				{
					str2 = "";
					str2 = *stringList[2];
					if( isPositiveInteger(str2, numberOfEngines) == 0)
					{
						cout << endl << "Number of Engines: Either non-numeric character or negative number [" << str2 << "] at line " << currentLine;
						continue;
					}
				} // end of if(aircraftType == 0, 1, or 3)

				if(aircraftType == 0 || aircraftType == 1)
				{
					str2 = "";
					str2 = *stringList[3];
					if( isPositiveInteger(str2, seatCapacity) == 0)
					{
						cout << endl << "Seat Capacity: Either non-numeric character or negative number [" << str2 << "] at line " << currentLine;
						continue;
					}
				} // end of if(aircraftType == 0 || aircraftType == 1)

				if(aircraftType == 0)
				{
					if(stringList.size() > 4)
					{
						cout << endl << "Too many arguments [" << *stringList[4] << "] at line " << currentLine;
						continue;
					}

					vectorOfAircraft.push_back(new Aircraft (seatCapacity, aircraftType, numberOfEngines));
					//aa->printCharacteristics();

					//cout << endl << "Create new aircraft, type: " << aircraftType << ", Number of Engines: " << numberOfEngines << ", Seat Capacity: " << seatCapacity;
					continue;
				} // end of if(aircraftType == 0)

				if(aircraftType == 1)
				{
					///cout << endl << "vector size = " << stringList.size();
					if(stringList.size() < 5)
					{
						cout << endl << "Too few arguments at line " << currentLine;
						continue;
					}
					///cout << endl << "theLine = [" << theLine << "]";

					str1 = "";
					if(hasDoubleQuotedText(theLine, str1) == 0)
					{
						cout << endl << "Missing string data enclosed within matching double quotes at line " << currentLine;
					}
					else
					{
						vectorOfAircraft.push_back(new PassengerAircraft (str1, seatCapacity, numberOfEngines));
						//aa->printCharacteristics();

						//cout << endl << "Create new aircraft, type: " << aircraftType << ", Number of Engines: " << numberOfEngines << ", Seat Capacity: " << seatCapacity << ", Range & speed description: [" << str1 << "].";
					}
					continue;
				} // end of if(aircraftType == 1)


				size_t requiredSize = 4;
				if(aircraftType == 3)
					requiredSize = 5;

				if(aircraftType == 2 || aircraftType ==3)
				{
					///cout << endl << "vector size = " << stringList.size();
					if(stringList.size() < requiredSize)
					{
						cout << endl << "Too few arguments at line " << currentLine;
						continue;
					}
					///cout << endl << "theLine = [" << theLine << "]";

					str1 = "";
					if(hasDoubleQuotedText(theLine, str1) == 0)
					{
						cout << "Missing string data enclosed within matching double quotes at line " << currentLine;
						continue;
					}
					str2 = "";
					if(hasDoubleQuotedText(theLine, str2) == 0)
					{
						cout << "Missing string data enclosed within matching double quotes at line " << currentLine;
						continue;
					}

					if(aircraftType == 2)
					{
						vectorOfAircraft.push_back(new AcrobatAircraft(str1, str2));
						//cout << endl << "Create new aircraft, type: "  << aircraftType << ", Manufacturer: [" << str1 << "], Performance capability description: [" << str2 << "].";
					}
					else if(aircraftType == 3)
					{
						vectorOfAircraft.push_back(new FreightAircraft(str1, str2, numberOfEngines));
						//cout << endl << "Create new aircraft, type: " << aircraftType << ", Number of Engines: " << numberOfEngines << ", Freight company: [" << str1 << "], Cargo capacity: [" << str2 << "].";
					}
					continue;
				} // end of if(aircraftType == 2 or 3

			} // end of if(*stringList[0] == "n")



		} // end of while (!inputFile.eof())

		inputFilestream.close();
		if(currentDataLine < 1)
		{
			cout << endl << "Input file is either empty or contains only comments or delimiters. Nothing to process." << endl;
		}
	}
	// the input file was not successfully opened
	else
	{
		cout << "File \"" << inputFileName << "\" could not be opened" << endl;
	}

	//return currentValidRow;
}



/*	Function 7:		testAircraft()
	Descr:			This function runs readFileAndBuildAircraft() on an input file.
	Param:    		None.
	Return:			None. */
void testAircraft()
{
	ifstream inputFile;
	// input a file name: the input files provided are ../aircraft.txt or ../test.txt
	string inputFileName;
	cout << "Enter the input file name: ";
	cin >> inputFileName;
	///inputFileName = "Aircraft.txt";
	cout << "Input file name is: " << inputFileName << endl;

	readFileAndBuildAircraft(inputFileName);
}



/*	Function 8:		testAircraftClass()
	Descr:			This function tests each Aircraft derived class by creating objects and callings their methods.
	Param:    		None.
	Return:			None. */
void testAircraftClass()
{
/**/
	Aircraft a(22, 0, 2); a.printCharacteristics();
	Aircraft b(400, 3, 1); b.printCharacteristics();
	Aircraft c; c.printCharacteristics();
	Aircraft d(24); d.printCharacteristics();

	PassengerAircraft p("pride of the sky");
	p.printCharacteristics();
	PassengerAircraft q("king of the clouds", 350, 2);
	q.printCharacteristics();

	q.announceConnectingFlights();
	p.announceConnectingFlights();

	p.setStrRangeAndSpeed("Range/speed updated");
	p.printCharacteristics();

/**/
	AcrobatAircraft ac("Boeing", "Acrobatic Performer");
	AcrobatAircraft ad("Airbus", "Sleek Dancer", 5, 3);
	ac.printCharacteristics(); ad.doAcrobaticManeuver();
	ad.printCharacteristics(); ac.doAcrobaticManeuver();
	string str = ac.getStrManufacturer();
	cout << endl << "str = " << str;
	str = "Oklahoman";
	ac.printCharacteristics();

	FreightAircraft f("Fed-Ex", "Carries domestic stuff only", 4, 4);
	f.printCharacteristics();

	Aircraft *aa = new AcrobatAircraft ("AirBuster", "Base Sleek Dancer", 15, 2);
	aa->printCharacteristics();

	Aircraft *af = new FreightAircraft ("DHL-OK", "European star", 3, 2);
	af->printCharacteristics();
	//cout << endl << endl;
	//af->printCharacteristics();

	fflush(stdout);

	delete aa;
	delete af;

}



/*	Function 9:		main()
	Descr:			This is the driver of the program.
	Param:    		None.
	Return:			0 */
int main()
{
	testAircraft();
	//testAircraftClass();
	return 0;
}