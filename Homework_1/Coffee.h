#pragma once
#include <iostream>;
using namespace std;

class Coffee
{
private:
	char* breed; //сорт
	char* name;
	unsigned int volume;
	double price;
	bool milk;

public:
	Coffee()
	{
		volume = 250;
		price = 20.5;
		milk = true;
		breed = new char[100];
		strcpy_s(breed, 99, "Arabica");
		name = new char[100];
		strcpy_s(name, 99, "Cappucino");
	}
	Coffee(const char* breed, const char* name,
		int volume, int price, int milk)
	{
		SetBreed(breed);
		SetName(name);
		SetVolume(volume);
		SetPrice(price);
		SetMilk(milk);
	}

	~Coffee()
	{
		if (breed != nullptr) delete[] breed;
		if (name != nullptr) delete[] name;
	}

	void Show() const
	{
		cout << "This is " << name << ", made from " << breed << " breed. It's volume is " << volume << " ml and it costs " << price << " UAH.\n";
	}
	void Milk() const
	{
		if (milk) cout << "This coffee has milk in it.\n";
		else cout << "There's no milk in this coffee.\n";
	}
	void Drink()
	{
		cout << "You've drank your coffee.\n";
		SetVolume(0);
	}
	void Spill()
	{
		cout << "You've spilled your coffee :c\n";
		SetVolume(0);
	}
	void FreeCoffee()
	{
		cout << "Someone's bought you a cup of Coffee!\n";
		SetPrice(0);
	}

	void SetName(const char* name)
	{
		if (strlen(name) == 0)
			throw "Oops! Incorrect value for name!\n";

		this->name = new char[100];
		strcpy_s(this->name, 99, name);
	}
	void SetBreed(const char* breed)
	{
		if (strlen(breed) == 0)
			throw "Oops! Incorrect value for breed!\n";

		this->breed = new char[100];
		strcpy_s(this->breed, 99, breed);
	}
	void SetPrice(double price)
	{
		if (price < 0)
			throw "Oops! Incorrect value for price!\n";

		this->price = price;
	}
	void SetVolume(int volume)
	{
		if (volume < 0 || volume > 500)
			throw "Oops! Incorrect value for volume!\n";

		this->volume = volume;
	}
	void SetMilk(bool milk)
	{
		if (milk < 0 || milk > 1)
			throw "Oops! Incorrect value for milk!\n";

		this->volume = milk;
	}

	unsigned int GetVolume() const
	{
		return volume;
	}
	bool GetMilk() const
	{
		return milk;
	}
	double GetPrice() const
	{
		return price;
	}
	string GetName() const
	{
		return name;
	}
	string GetBreed() const
	{
		return breed;
	}
};