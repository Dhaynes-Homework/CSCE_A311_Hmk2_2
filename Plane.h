#pragma once
#include<iostream>
#include<string>

using namespace std;

class Plane
{
public:
	// Constructors
	Plane();
	Plane(Plane *n, int t, string flt);

	// Destructor
	~Plane();

	// Accessors
	Plane* nextPlane();
	int getTime();
	string getFlight();

	// Mutators
	void setPlane(Plane* n);
private:
	Plane *next;
	int time;
	string flight;
};

