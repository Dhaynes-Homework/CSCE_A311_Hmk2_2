#include "PlaneLL.h"

// Constructor
PlaneLL::PlaneLL()
{
	head = nullptr;
}

// Destructor
PlaneLL::~PlaneLL()
{
}

// Functions
void PlaneLL::push(int t, string flt)
{

	Plane *temp;
	temp = new Plane(head, t, flt);
	head = temp;

	return;
}

// Searching for earliest time
Plane* PlaneLL::findTime()
{
	if (isEmpty())
	{
		return nullptr;
	}
	if (head->nextPlane() == nullptr)
	{
		return head;
	}
	Plane* smallT = head;
	Plane* temp = head;
	while (temp != nullptr)
	{
		if (smallT->getTime() > temp->getTime())
		{
			smallT = temp;
		}
		temp = temp->nextPlane();
	}
	return smallT;
}

// Removing set flight from list
void PlaneLL::removeItem(Plane* item)
{
	Plane *temp = head;
	if (head == nullptr)
	{
		return;
	}
	else if (head == item)
	{
		head = head->nextPlane();
		delete temp;
		return;
	}
	while (temp->nextPlane() != item)
	{
		if (temp == nullptr)
		{
			cout << "Didn't find item in list" << endl;
			return;
		}
		temp = temp->nextPlane();
	}
	temp->setPlane(item->nextPlane());
	delete item;
}

// adding a flight to the back of the list
void PlaneLL::pop_back(int t, string flt)
{
	if (isEmpty())
	{
		head = new Plane(nullptr, t, flt);
	}
	else
	{
		Plane* temp = head;
		while (temp->nextPlane() != nullptr)
		{
			temp = temp->nextPlane();
		}
		temp->setPlane(new Plane(nullptr, t, flt));
	}
	return;
}

// getting end of list's flight
int PlaneLL::endTime()
{
	Plane* temp = head;
	while (temp->nextPlane() != nullptr)
	{
		temp = temp->nextPlane();
	}
	return temp->getTime();
}

// Outputing flight details and times in list
void PlaneLL::outputList()
{
	Plane* temp = head;
	while (temp != nullptr)
	{
		cout << temp->getFlight() << " " << temp->getTime() << endl;
		temp = temp->nextPlane();
	}
	return;
}

// searching list for available times
void PlaneLL::remainSlot()
{
	Plane* temp = head;
	Plane* temp2 = head->nextPlane();
	while (temp2 != nullptr)
	{
		if ((temp2->getTime() - temp->getTime() - 100) * 60 / 100 >= 60)
		{
			cout << "Time slot open between " << (temp->getTime() + 100) << " and " << (temp2->getTime() - 100) << endl;
		}
		temp = temp2;
		temp2 = temp2->nextPlane();
	}

	if ((2400 - temp->getTime() - 100) * 60 / 100 >= 60)
	{
		cout << "Time slot open between " << (temp->getTime() + 100) << " and " << 2300 << endl;
	}
	return;
}

// checking if list is empty
bool PlaneLL::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}