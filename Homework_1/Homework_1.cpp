#include <iostream>
#include "Coffee.h"
using namespace std;



int main()
{
	setlocale(0, "");

	Book first; // создание одного объекта (паеременной) типа Бук на стеке
	cout << &first << "\n";

	first.Show();

	//Book::Show(&first);

	Book second;
	cout << &second << "\n";
	second.Show();

	// Book::Show(&second);

	//cout << &second << "\n";

	//Book library[1000]; // создание статического массива объектов НА СТЕКЕ

	//Book* ptr_book = new Book; // создание одной переменной типа БУк В ХИПЕ
	//delete ptr_book;

	// создание ДИНАМИЧЕСКОГО массива ОБЪЕКТОВ типа БУк
	//Book* dynamic_array = new Book[1000000];
	//delete[] dynamic_array;

}