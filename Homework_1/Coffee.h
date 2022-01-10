#pragma once
#include <iostream>;
using namespace std;

class Coffee
{
public:
	char* breed; //����
	char* name;
	int volume;
	int price;
	bool milk;

public:
	Coffee() // ����������� ��� ���������� 
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
		int volume, int price, int milk) // ����������� � �����������
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

	// ����������� �����������
	Coffee(const Coffee& original)
	{
		cout << "COPY CTOR!\n";

		// ��� ���� ��������� �������� ����� ������!
		breed = new char[100];
		strcpy_s(breed, 99, original.breed);
		name = new char[100];
		strcpy_s(name, 99, original.name);



		// ������������� ��������� ������������� ����������� �� ��������� - �� �������� ������ ����������!
		//author = original.author;
		//name = original.name;

		milk = original.milk;
		price = original.price;
		volume = original.volume;
	}

	~Coffee() // ����������
	{
		cout << "DEST\n";
		if (breed != nullptr) delete[] breed;
		if (name != nullptr) delete[] name;
	}

	void Show(/*const Book* this*/)
	{
		// this = new Book;
		//cout << "����� ������  " << author << "  \"" << name << "\" ������� " << edition << "-�\n";

		cout << name << "\n";
		cout << this << "\n";
		//Book first;
		//cout << &first << "\n";
	}
};