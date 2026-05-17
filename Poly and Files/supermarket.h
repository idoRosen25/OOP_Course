#ifndef _SUPERMARKET_H
#define _SUPERMARKET_H

#include <iostream>
#include <typeinfo>
#include "product.h"
#include "food.h"
#include "medicine.h"

using namespace std;
//------------------------------------------------------------------------------
// The Super Market 
//------------------------------------------------------------------------------
class SuperMarket
{
public:
	SuperMarket() : m_name( nullptr ), m_manager( nullptr ), m_address( nullptr ), m_opening_time( nullptr ), m_closing_time( nullptr ), m_num_products( 0 ), m_products( nullptr ) {}
	SuperMarket( const char* name,
		const char* manager,
		const char* address,
		const char* opening_time,
		const char* closing_time,
		unsigned int num_products,
		Product** products );
	SuperMarket( ifstream& in_file );
	// Dtor. of SuperMarket has to free all allocated memory for all the products.
	virtual ~SuperMarket();

	friend istream& operator>>( istream& is, SuperMarket& market );
	friend ostream& operator<<( ostream& os, const SuperMarket& market );

	friend ifstream& operator>>( ifstream& ifs, SuperMarket& market );
	friend ofstream& operator<<( ofstream& ofs, const SuperMarket& market );

	void saveBin( ofstream& out_file ) const;

private:
	// Eventually, there is no need to put these two methods in the Interface.
	void read( istream& is );
	void write( ostream& os ) const;

	// An auxiliary functions that writes all products to an output stream.
	void writeProducts( ostream& os ) const;

	// An auxiliary functions that reads from an input stream 
	// a given list of products, and inserts these products into the super market.
	void readProducts( istream& is );


	// Create a SPECIFIC product at running time from an input stream. 
	Product* createProduct( istream& is );

	void clearProducts();

private:
	// Eventually, there is no need to put these two methods in the Interface.
	void load( ifstream& in_file );
	void save( ofstream& out_file ) const;

	// An auxiliary functions that saves all products to a file.
	void saveProducts( ofstream& os ) const;

	// An auxiliary functions that load from a file
	// a given list of products, and inserts these products into the super market.
	void loadProducts( ifstream& is );

	// Create a SPECIFIC product at running time from a text file.
	Product* createProduct( ifstream& in_file );

	// Create a SPECIFIC product at running time from a binary file.
	Product* createProductBin( ifstream& in_file );

	// An auxiliary functions that saves all products to a binary file.
	void saveProductsBin( ofstream& os ) const;

	// An auxiliary functions that load from a binary file
	// a given list of products, and inserts these products into the super market.
	void loadProductsBin( ifstream& is );

private:
	char* m_name;
	char* m_manager;
	char* m_address;
	char* m_opening_time;
	char* m_closing_time;
	unsigned int m_num_products;
	Product** m_products;	// a container of all the product in the super market,
								// each product is either Food or Medicine.
};

//------------------------------------------------------------------------------
// IO operators (Extractor and Insertor) for SuperMarket.
//-----------------------------------------------------------------------------

istream& operator>>( istream& is, SuperMarket& market );
ostream& operator<<( ostream& os, const SuperMarket& market );

ifstream& operator>>( ifstream& ifs, SuperMarket& market );
ofstream& operator<<( ofstream& ofs, const SuperMarket& market );

#endif





