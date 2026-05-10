#ifndef __SHAPE_H
#define __SHAPE_H

#pragma warning(disable: 4996)

#include <iostream>
using namespace std;

class Shape
{
public:
	Shape( float frameWidth, const char* color );
	Shape( const Shape& other );
	Shape( Shape&& other );
	virtual ~Shape();

public:
	virtual const Shape& operator=( const Shape& other );
	virtual const Shape& operator=( Shape&& other );
	friend ostream& operator<<( ostream& os, const Shape& shape );

public:
	virtual void toOs( ostream& os ) const = 0;
	virtual float getArea() const = 0;
	virtual float getPerimeter() const = 0;

protected:
	float	m_frameWidth;
	char*	m_color;
};

#endif