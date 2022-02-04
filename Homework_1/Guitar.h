#pragma once
#include <iostream>;
using namespace std;

class Guitar
{
private:
	char* brand;
	char* model;
	unsigned int strings;
	double price;
	int pickup; //звукосниматель

public:
	Guitar()
	{
		strings = 6;
		price = 1699;
		pickup = 2;
		brand = new char[100];
		strcpy_s(brand, 99, "Gibson");
		model = new char[100];
		strcpy_s(model, 99, "Les Paul Special");
	}
	Guitar(const char* brand, const char* model,
		int strings, double price, int pickup)
	{
		SetBrand(brand);
		SetModel(model);
		SetStrings(strings);
		SetPrice(price);
		SetPickup(pickup);
	}

	~Guitar()
	{
		if (brand != nullptr) delete[] brand;
		if (model != nullptr) delete[] model;
	}

	void Show() const
	{
		cout << "This is " << brand << " guitar, model is " << model << ". It has " << strings << " strings and it costs " << price << " USD.\n";
	}
	void Pickup() const
	{
		cout << "This guitar has " << pickup << " working pickups\n";
	}
	void StringBroke()
	{
		cout << "OMG! String's broke.\n";
		SetStrings(GetStrings() - 1);
	}
	void Discount(int d)
	{
		cout << "You've got a discount.\n";
		double p = GetPrice();
		p -= (p / 100) * d;
		SetPrice(p);
	}
	void PickupTurnOff()
	{
		cout << "You've turned off one of the pickups\n";
		SetPickup(GetPickup() - 1);
	}

	void SetModel(const char* model)
	{
		if (strlen(model) == 0)
			throw "Oops! Incorrect value for model!\n";

		this->model = new char[100];
		strcpy_s(this->model, 99, model);
	}
	void SetBrand(const char* brand)
	{
		if (strlen(brand) == 0)
			throw "Oops! Incorrect value for brand!\n";

		this->brand = new char[100];
		strcpy_s(this->brand, 99, brand);
	}
	void SetPrice(double price)
	{
		if (price < 0)
			throw "Oops! Incorrect value for price!\n";

		this->price = price;
	}
	void SetStrings(int strings)
	{
		if (strings < 0 || strings > 48)
			throw "Oops! Incorrect value for strings!\n";

		this->strings = strings;
	}
	void SetPickup(int pickup)
	{
		if (pickup < 0 || pickup > 4)
			throw "Oops! Incorrect value for pickup!\n";

		this->pickup = pickup;
	}

	unsigned int GetStrings() const
	{
		return strings;
	}
	int GetPickup() const
	{
		return pickup;
	}
	double GetPrice() const
	{
		return price;
	}
	string GetModel() const
	{
		return model;
	}
	string GetBrand() const
	{
		return brand;
	}
};