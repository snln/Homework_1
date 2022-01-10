#pragma once
#include <iostream>;
using namespace std;

class Coffee
{
public:
	char* breed; //сорт
	char* name;
	int volume;
	int price;
	bool milk;

public:
	Coffee() // конструктор БЕЗ параметров 
	{
		cout << "DEFAULT CTOR!\n";
		volume = 250;
		price = 20;
		milk = true;
		breed = new char[100];
		strcpy_s(breed, 99, "Arabica");
		name = new char[100];
		strcpy_s(name, 99, "Cappucino");
	}
	Coffee(const char* breed, const char* name,
		int volume, int price, int milk) // конструктор С параметрами
	{
		cout << "PARAM CTOR!\n";

		this->breed = new char[100];
		strcpy_s(this->breed, 99, breed);

		this->name = new char[100];
		strcpy_s(this->name, 99, name);

		this->volume = volume;
		this->milk = milk;
		this->price = price;
	}

	// конструктор копирования
	Coffee(const Coffee& original)
	{
		cout << "COPY CTOR!\n";

		// под поля указатели выделяем новую память!
		breed = new char[100];
		strcpy_s(breed, 99, original.breed);
		name = new char[100];
		strcpy_s(name, 99, original.name);



		// нежелательное поведение куонструктора копирования по умолчанию - он копирует АДРЕСА указателей!
		//author = original.author;
		//name = original.name;

		milk = original.milk;
		price = original.price;
		volume = original.volume;
	}

	~Coffee() // деструктор
	{
		cout << "DEST\n";
		if (breed != nullptr) delete[] breed;
		if (name != nullptr) delete[] name;
	}

	void Show(/*const Book* this*/)
	{
		// this = new Book;
		//cout << "Книга автора  " << author << "  \"" << name << "\" издание " << edition << "-е\n";

		cout << name << "\n";
		cout << this << "\n";
		//Book first;
		//cout << &first << "\n";
	}
};