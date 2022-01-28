#include <iostream>
#include "Coffee.h"
using namespace std;



int main()
{
	setlocale(0, "");

	Coffee first;
	//cout << &first << "\n";
	first.Show();
	first.Drink();
	first.Show();

	return 0;
}