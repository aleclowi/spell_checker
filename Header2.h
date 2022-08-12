#ifndef _HOURLYWORKER_
#define _HOURLYWORKER_

#include <iostream>
#include <string.h>
#include "Employee.h"

class HourlyWorker : public Employee
{
public:

	/**
	Constructor: accepts a name, email, and hourly rate, setting the hours worked to 0 initially;

	@param name and email of the employee, the hourly pay rate
	*/
	HourlyWorker(const std::string& name, const std::string& email, double rate);

	/**
	Constructor: accepts an input file stream to read in the name, email, id,
	hours worked, and hourly rate;.

	@param the file name of the input string
	*/

	HourlyWorker(const std::string inFile);

	/**
	This function that sets the hours worked;


	@param none
	@return type void, will modify the hours variable of the employe hours worked
	*/

	void set_hours();

	/**
	This function (that could be overridden) that writes the name, email, and id of the Employee
	to a file, each entry separated by a tab

	@param employee
	@return type void, inputs information into a txt file
	*/

	void write_data();

	/**
	Override the print pay function here, define here to override the function for another definition of this class

	@param employee
	@return type void, prints out the employee's name and their pay amount
	*/

	void print_pay() const override
	{

	}

	/**
	Override the save function to save the employee' function to the file

	@param employee
	@return type void, inputs information into the employee's file
	*/

	void save() override
	{

	}

private:
	double rate; //  track the hourly pay rate
	double hours; // track the integer number of hours worked

};
#endif




