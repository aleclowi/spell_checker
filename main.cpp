#include <iostream>
#include <string.h>
#include <sstream>
#include "SpellCheck.h"

using namespace std;

int main()
{
	//output statement for the user to enter the file name
	cout << "Enter a file to check: ";
	string fileName;
	//input filename
	getline(cin, fileName);
	//use stringstream INPUT for filename
	stringstream iss(fileName);
	SpellCheck f1(fileName);
	//call the read dictionary function after calling the class
	f1.read_dictionary("dictionary.txt");
	//call process file to output the new file.
	f1.process_file(fileName);
	return 0;
}