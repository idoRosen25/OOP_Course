
//-----------------------------------------------------------------------------------------------//
#include <iostream>
using namespace std;

#include "SiamiStreetCat.h"
//-----------------------------------------------------------------------------------------------//
void main() 
{
	{
		StreetCat c1(Cat("mitzi", 30, "Black"), 10);
		cout << "StreetCat c1 details:\n";
		c1.show();
		cout << endl << endl;

		SiamiCat c2(Cat("kitzi", 50, "White"), "Shrimps");
		cout << "SiamiCat c2 details:\n";
		c2.show();
		cout << endl << endl;

		SiamiStreetCat c3(c2, c1);
		cout << "SiamiStreetCat c3 details:\n";
		c3.show();
		cout << endl;
	}
	system("pause");
}
//-----------------------------------------------------------------------------------------------//