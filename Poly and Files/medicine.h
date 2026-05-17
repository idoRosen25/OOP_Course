#ifndef _MEDICINE_H
#define _MEDICINE_H

#include "product.h"

//  Medicine: Derived class.
class Medicine : public Product
{
public:
	Medicine( const char* name = nullptr, double cost = 0, bool prescription = true );	//c'tor for all data
	Medicine( ifstream& in_file );	//c'tor from bin file stream

public: //handle io stream from console (user input)
	virtual void read( istream& is );
	virtual void write( ostream& os ) const;

public: //handle io stream from text file
	virtual void load( ifstream& in_file );
	virtual void save( ofstream& out_file ) const;

public:
	virtual void saveBin( ofstream& out_file ) const;//save data to bin file ("loadBin" is in the c'tor)

private:
	bool m_prescription;
};

#endif
