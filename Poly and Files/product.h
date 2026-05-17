#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>
#include <typeinfo>
#include <fstream>

using namespace std;

// Products.
////////////////////////////////////////////

// Product - Base class
class Product
{
protected:
	// Hide Ctor in order to disable the creation of Product objects.
	Product( const char* name = nullptr, double cost = 0); //c'tor with all data
	Product( ifstream& in_file ); //c'tor from bin file
	Product( const Product& other ); //copy c'tor
	Product( Product&& other ); //move c'tor

public:
	virtual ~Product(); //virtual d'tor	

public:
	// Reads Product data from console (user input).
	virtual void read( istream& is );

	// Writes Product data to console (user screen). 
	virtual void write( ostream& os ) const;

	// Used for the write method.
	void save_txt_type( ostream& os ) const { os << typeid( *this ).name() + 6 << endl; }

public:
	// Load Product data from text file.
	virtual void load( ifstream& in_file );

	// Save Product data to text file.
	virtual void save( ofstream& out_file ) const;

	// Used for the save method.
	void saveType( ofstream& out_file ) const;

public:
	// Save Product data in binary form.
	virtual void saveBin( ofstream& out_file ) const;

	// Used for the save method.
	void saveTypeBin( ofstream& out_file ) const;

protected:
	char* m_name;
	double m_cost;
};

istream& operator >> ( istream& is, Product& p );
ostream& operator<<( ostream& os, const Product& p );

ifstream& operator >> ( ifstream& ifs, Product& p );
ofstream& operator<<( ofstream& ofs, const Product& p );

#endif
