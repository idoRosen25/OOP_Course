#ifndef _FOOD_H
#define _FOOD_H

#include "product.h"

// Food: Derived class.
class Food : public Product
{
public:
	Food( const char* name = nullptr, double cost = 0, double calories = 0 ); //c'tor for all data
	Food( ifstream& in_file );	//c'tor from bin file stream

public: //handle io stream from console (user input)
	virtual void read( istream& is );
	virtual void write( ostream& os ) const;

public: //handle io stream from text file
	virtual void load( ifstream& in_file );
	virtual void save( ofstream& out_file ) const;

public:
	virtual void saveBin( ofstream& out_file ) const; //save data to bin file ("loadBin" is in the c'tor)

private:
	double m_calories;
};

#endif

