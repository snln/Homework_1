#pragma once
#include <iostream>;
using namespace std;

class Apartment
{
private:
	char* street;
	int rent;
	int rooms;
	int people;
	double area;

public:
	Apartment()
	{
		rent = 10000;
		rooms = 2;
		people = 2;
		street = new char[100];
		strcpy_s(street, 99, "Deribasovskaya");
		area = 65.3;
	}
	Apartment(const char* street,
		int rent, double area, int rooms, int people)
	{
		SetStreet(street);
		SetRent(rent);
		SetArea(area);
		SetRooms(rooms);
		SetPeople(people);
	}

	~Apartment()
	{
		if (street != nullptr) delete[] street;
	}

	void Show() const
	{
		cout << "This is apartment on " << street << " street, it has " << rooms << " rooms. Area is " << area << " m2, and rent is " << rent << " UAH.\n";
	}
	void People() const
	{
		if (people == 0) cout << "This apartment's used for technical purpose, no one's living in there\n";
		else cout << "There's " << people << " living in there\n";
	}
	void Evict(int p)
	{
		if (GetPeople() < p) cout << "There's not that much people living in there!\n";
		else
		{
			(SetPeople(GetPeople() - p));
			cout << p << " people has been succefully evicted.\n";
		}
	}
	void RentUp(int r)
	{
		SetRent(GetRent() + r);
		cout << "Rent has been raised on " << r << " UAH.\n";
	}
	void RentDown() const
	{
		cout << "Lol, it never happens :)\n";
	}

	void SetStreet(const char* street)
	{
		if (strlen(street) == 0)
			throw "Oops! Incorrect value for street!\n";

		this->street = new char[100];
		strcpy_s(this->street, 99, street);
	}
	void SetArea(double area)
	{
		if (area <= 0)
			throw "Oops! Incorrect value for area!\n";

		this->area = area;
	}
	void SetRent(int rent)
	{
		if (rent < 0)
			throw "Oops! Incorrect value for rent!\n";

		this->rent = rent;
	}
	void SetRooms(int rooms)
	{
		if (rooms <= 0)
			throw "Oops! Incorrect value for rooms!\n";

		this->rooms = rooms;
	}
	void SetPeople(int people)
	{
		if (people < 0)
			throw "Oops! Incorrect value for people!\n";

		this->people = people;
	}

	unsigned int GetRooms() const
	{
		return rooms;
	}
	int GetPeople() const
	{
		return people;
	}
	int GetRent() const
	{
		return rent;
	}
	double GetArea() const
	{
		return area;
	}
	string GetStreet() const
	{
		return street;
	}
};