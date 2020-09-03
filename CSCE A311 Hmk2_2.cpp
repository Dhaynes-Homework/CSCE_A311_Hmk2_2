// Devan Haynes
// CSCE A311 Hmk2_2
// Needs Plane.h, Plane.cpp, PlaneLL.h, PlaneLL.cpp, and flights.txt to run

// Used for CSCE A311 Homework Assignment 2 Part 2

// Objective is to create a linked list of flights and find open times to slot flights.

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"PlaneLL.h"

using namespace std;

int main()
{
	PlaneLL fltList;
	PlaneLL gate1, gate2, gate3, notList;
	string line;

	//Reading in file
	ifstream fltFile("flights.txt");
	if (fltFile.is_open())
	{
		while (getline(fltFile, line))
		{
			
			string parsed;
			string flight;
			int time;
			stringstream input_stringstream(line);

			// Parsing input
			input_stringstream >> parsed;
			flight = parsed + " ";
			input_stringstream >> parsed;
			flight += parsed;
			input_stringstream >> parsed;
			istringstream(parsed) >> time;

			// Pusing flight details into List
			fltList.push(time, flight);
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
		system("pause");
		return 0;
	}

	//Grabing earliest flight times and putting one in each gate and removing it from flight list
	Plane* small = fltList.findTime();

	gate1.pop_back(small->getTime(), small->getFlight());
	fltList.removeItem(small);
	small = fltList.findTime();
	gate2.pop_back(small->getTime(), small->getFlight());
	fltList.removeItem(small);
	small = fltList.findTime();
	gate3.pop_back(small->getTime(), small->getFlight());
	fltList.removeItem(small);

	// checking earliest flight remaning in list and putting it in a applicable gate or in the unschedueld flight list
	while (!(fltList.isEmpty()))
	{
		small = fltList.findTime();
		if (((small->getTime() - gate1.endTime())* 60 / 100) >= 60)
		{
			gate1.pop_back(small->getTime(), small->getFlight());
			fltList.removeItem(small);
		}
		else if (((small->getTime() - gate2.endTime()) * 60 / 100) >= 60)
		{
			gate2.pop_back(small->getTime(), small->getFlight());
			fltList.removeItem(small);
		}
		else if (((small->getTime() - gate3.endTime()) * 60 / 100) >= 60)
		{
			gate3.pop_back(small->getTime(), small->getFlight());
			fltList.removeItem(small);
		}
		else
		{
			notList.pop_back(small->getTime(), small->getFlight());
			fltList.removeItem(small);
		}
	}

	// Mass outputs
	cout << "Gate 1 scheduel" << endl;
	gate1.outputList();
	cout << "Gate 2 scheduel" << endl;
	gate2.outputList();
	cout << "Gate 3 scheduel" << endl;
	gate3.outputList();
	cout << "Unschedueld flights" << endl;
	notList.outputList();
	cout << "Gate 1 open slots:" << endl;
	gate1.remainSlot();
	cout << "Gate 2 open slots:" << endl;
	gate2.remainSlot();
	cout << "Gate 3 open slots:" << endl;
	gate3.remainSlot();
	system("pause");
	return 0;
}