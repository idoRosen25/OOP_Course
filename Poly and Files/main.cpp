#include "supermarket.h"
#include "food.h"
#include "medicine.h"
#include "product.h"

int main()
{
	SuperMarket s1;
	cin >> s1;		//operator>> of the SuperMarket
	cout << s1;		//operator<< of the SuperMarket


	//********** part 1 **********//
	//create empty super market, fill it from input.txt file then print it
	SuperMarket s2;
	ifstream InFile( "input.txt" );

	if( !InFile.is_open() )
	{
		cout << "Error opening input.txt!\n";
		return 1;
	}

	InFile >> s2;
	InFile.close();
	cout << s2;

	//********** part 2 **********//
	//create empty file output.txt, fill it from the super market that we created before
	ofstream OutFile( "output.txt" );
	if( !OutFile.is_open() )
	{
		cout << "Error opening output.txt!\n";
		return 1;
	}

	OutFile << s2;
	OutFile.close();

	//********** part 3 **********//
	//create a super market with some data, fill the file output2.txt with this data
	//then also print it to the screen
	Product** _products = new Product*[3];
	_products[0] = new Food( "Orbit-Gam", 6.90, 10 );
	_products[1] = new Medicine( "Moxipen", 17, 1 );
	_products[2] = new Medicine( "Liteers", 12, 0 );

	SuperMarket s3( "super-Farm", "unknown", "Ramat-Aviv", "8:00-Am", "10:00-Pm", 3, _products );

	ofstream OutFile2;
	OutFile2.open( "output2.txt", ios::out | ios::trunc );
	if( !OutFile2.is_open() )
	{
		cout << "Error opening output2.txt!\n";
		return 1;
	}

	OutFile2 << s3;
	cout << s3;
	OutFile2.close();

	//********** part 4 **********//
	//write the super market from before to a binary file binary.dat
	ofstream binFileOut;
	binFileOut.open( "binary.dat", ios::out | ios::binary | ios::trunc );
	if( !binFileOut.is_open() )
	{
		cout << "Error opening output2.txt!\n";
		return 1;
	}

	s3.saveBin( binFileOut );
	binFileOut.close();

	//********** part 5 **********//
	//create a super market from the binary file that we saved before and print the details to the console
	ifstream binFileIn;
	binFileIn.open( "binary.dat", ios::in | ios::binary );
	if( !binFileIn.is_open() )
	{
		cout << "Error opening output2.txt!\n";
		return 1;
	}

	SuperMarket s4( binFileIn );
	cout << s4;
	binFileIn.close();

	return 0;
}