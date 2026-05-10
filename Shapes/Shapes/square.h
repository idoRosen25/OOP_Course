#ifndef __SQUARE_H
#define __SQUARE_H

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

#include "shape.h"

class Square : public Shape
{
public:
	Square( float frameWidth, const char* color, float sideLength );
	Square( const Square& other ) = default;
	Square( Square&& other ) = default;
	virtual ~Square() {}

public:
	virtual Square& operator=( const Square& other ) = default;
	virtual Square& operator=( Square&& other ) = default;

public:
	virtual void toOs( ostream& os ) const override;
	virtual float getArea() const override;
	virtual float getPerimeter() const override;

public:
	void draw() const;

protected:
	float m_sideLength;
};

#endif