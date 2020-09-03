#include "Plane.h"


// Constructors
Plane::Plane()
{
	next = nullptr;
	time = 0;
	flight = "";
}

Plane::Plane(Plane *n, int t, string flt)
{
	next = n;
	time = t;
	flight = flt;
}

// Destructor
Plane::~Plane()
{
}

//Accessors
Plane* Plane::nextPlane()
{
	return next;
}

int Plane::getTime()
{
	return time;
}

string Plane::getFlight()
{
	return flight;
}

//Mutators
void Plane::setPlane(Plane* n)
{
	next = n;
	return;
}