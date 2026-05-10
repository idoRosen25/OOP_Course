#include "square.h"
//-----------------------------------------------------------------------------------------------//
Square::Square( float frameWidth, const char *color, float sideLength )
	: Shape( frameWidth, color )
{
	m_sideLength = sideLength;
}
//-----------------------------------------------------------------------------------------------//
void Square::toOs( ostream& os ) const
{
	os << ", Side Length: " << m_sideLength;
}
//-----------------------------------------------------------------------------------------------//
float Square::getArea() const
{
	return m_sideLength * m_sideLength;
}
//-----------------------------------------------------------------------------------------------//
float Square::getPerimeter() const
{
	return m_sideLength * 4;
}
//-----------------------------------------------------------------------------------------------//
void Square::draw() const
{
	for( int i = 0; i < m_sideLength; i++ )
	{
		for( int j = 0; j < m_sideLength; j++ )
			cout << "*";

		cout << endl;
	}
}
//-----------------------------------------------------------------------------------------------//