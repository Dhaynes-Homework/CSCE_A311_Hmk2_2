#pragma once
#include"Plane.h"
class PlaneLL
{
public:
	// Constuctor
	PlaneLL();

	// Destructor
	~PlaneLL();

	// Functions
	void push(int t, string flt);
	Plane* findTime();
	void removeItem(Plane* item);
	void pop_back(int t, string flt);
	int endTime();
	void outputList();
	void remainSlot();
	bool isEmpty();

private:
	Plane * head;



};