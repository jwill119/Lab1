// COSC 2030 Lab 01
// Jacob Williams


//  ***********************************************************************  //
//                              Number-reader code                           //
//  ***********************************************************************  //
// Reads ASCII-text files of arbitrary length containing numbers.
// Gives the number of numbers as well as displaying the first and last two.
//
// Compiled with g++ (Bash Subsystem for Windows), standard: C++11.
// (Without C++11, compiler doesn't string in theFile.open().)

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <string>
using std::string;


int main() {
	// Initialize basic variables
	int count = 0;
	double firstVal, secondVal, secondLastVal, lastVal = 0;
    double temp = 0;            // Stores a temporary value for use in our loop later
	ifstream theFile;
	string fileName;
	
	// Introductory remarks
	cout << endl << endl << "This program counts the number of numbers in the input file." << endl;
	cout << "Also, it will display the first, second, second-last, and last number." << endl;
	cout << "We assume that the input file is in the same directory as the program." << endl;
	cout << "Please enter your input file name here:  ";
	cin >> fileName;
	cout << endl;
	
	// Open the file
	theFile.open(fileName);
	
	// Check to make sure the file exists and can be opened
	if (!theFile.is_open()) {
		cout << "File not found. Program exits" << endl;
		return 1;
	}
	
    // Read the first two numbers. (We'll assume at least three in the file.)
    theFile >> firstVal;
    theFile >> secondVal;
    count += 2;

    // Set the second-last and last values for now.
    secondLastVal = firstVal;
    lastVal = secondVal;


	// Read the numbers
	while (theFile >> temp) {
        if (theFile.fail()) { 
            break;
        } else {
            secondLastVal = lastVal;
            lastVal = temp;
            count++;
        }
	}

    // Close the file
    theFile.close();


    // Concluding remarks
    cout << "Finished reading. There were " << count << " numbers in the file." << endl;
    cout << "The first two numbers in your file were: " << firstVal << ", and " << secondVal << "." << endl;
    cout << "And the last two numbers were: " << secondLastVal << ", and " << lastVal << "." << endl;
    cout << "Thanks for visiting!" << endl;
	
	
	return 0;
}
