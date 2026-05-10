#include "shape.h"
//-----------------------------------------------------------------------------------------------//
Shape::Shape( float frameWidth, const char* color )
{
	m_frameWidth = frameWidth;
	m_color = strdup( color );
}
//-----------------------------------------------------------------------------------------------//
Shape::Shape( const Shape& other ) : m_color( nullptr )
{
	*this = other;
}
//-----------------------------------------------------------------------------------------------//
Shape::Shape( Shape&& other ) : m_color( nullptr )
{
	*this = move( other );
}
//-----------------------------------------------------------------------------------------------//
Shape::~Shape()
{
	delete[] m_color;
}
//-----------------------------------------------------------------------------------------------//
const Shape& Shape::operator=( const Shape& other )
{
	if( this != &other )
	{
		m_frameWidth = other.m_frameWidth;

		delete[] m_color;
		m_color = strdup( other.m_color );
	}

	return *this;
}
//-----------------------------------------------------------------------------------------------//
const Shape& Shape::operator=( Shape&& other )
{
	if( this != &other )
	{
		m_frameWidth = other.m_frameWidth;

		delete[] m_color;
		m_color = other.m_color;
		other.m_color = nullptr;
	}

	return *this;
}
//-----------------------------------------------------------------------------------------------//
ostream& operator<<( ostream& os, const Shape& shape )
{
	os << typeid( shape ).name() + 6 << " --> \tFrame width: " << shape.m_frameWidth << ", Color: " << shape.m_color << ", Area: " << shape.getArea() << ", Perimeter: " << shape.getPerimeter();
	shape.toOs( os );
	return os;
}
//-----------------------------------------------------------------------------------------------//