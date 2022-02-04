#pragma once
#include <iostream>;
using namespace std;

class Laptop
{
private:
	char* brand;
	char* model;
	char* processor;
	char* gCard;
	int ram;

public:
	Laptop()
	{
		ram = 8;
		brand = new char[100];
		strcpy_s(brand, 99, "HP");
		model = new char[100];
		strcpy_s(model, 99, "Pavillion Gaming 15");
		processor = new char[100];
		strcpy_s(processor, 99, "Ryzen 5 4600H");
		gCard = new char[100];
		strcpy_s(gCard, 99, "GTX 1650");
	}
	Laptop(const char* brand, const char* model, const char* processor,
		const char* gCard, int ram)
	{
		SetBrand(brand);
		SetModel(model);
		SetProcessor(processor);
		SetGCard(gCard);
		SetRam(ram);
	}

	~Laptop()
	{
		if (brand != nullptr) delete[] brand;
		if (model != nullptr) delete[] model;
		if (processor != nullptr) delete[] processor;
		if (gCard != nullptr) delete[] gCard;
	}

	void Show() const
	{
		cout << "This is " << brand << " laptop, model is " << model << ".\n";
	}
	void Specs() const
	{
		cout << "Technical specifications:\n";
		cout << "Processor - " << processor << "\n";
		cout << "Graphics card - " << gCard << "\n";
		cout << "Ram - " << ram << "\n";
	}
	void AddRam(int r)
	{
		SetRam(GetRam() + r);
	}
	void RemoveRam(int r)
	{
		if ((GetRam() - r) <= 0) cout << "Oops! Something gone wrong.\n";
		else (SetRam(GetRam() - r));
	}
	void Give() const
	{
		cout << "You've let someone use your laptop.\n";
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
	void SetProcessor(const char* processor)
	{
		if (strlen(processor) == 0)
			throw "Oops! Incorrect value for processor!\n";

		this->processor = new char[100];
		strcpy_s(this->processor, 99, processor);
	}
	void SetGCard(const char* gCard)
	{
		if (strlen(gCard) == 0)
			throw "Oops! Incorrect value for graphics card!\n";

		this->gCard = new char[100];
		strcpy_s(this->gCard, 99, gCard);
	}
	void SetRam(int ram)
	{
		if (ram < 0 || ram > 128)
			throw "Oops! Incorrect value for ram!\n";

		this->ram = ram;
	}

	int GetRam() const
	{
		return ram;
	}
	string GetBrand() const
	{
		return brand;
	}
	string GetModel() const
	{
		return model;
	}
	string GetProcessor() const
	{
		return processor;
	}
	string GetGCard() const
	{
		return gCard;
	}
};