#include "circle.h"
//-----------------------------------------------------------------------------------------------//
Circle::Circle( float frameWidth, const char* color, float radius )
	: Shape( frameWidth, color )
{
	m_radius = radius;
}
//-----------------------------------------------------------------------------------------------//
Circle::Circle( const Circle& other )
	: Shape( other )
{
	*this = other;
}
//-----------------------------------------------------------------------------------------------//
Circle::Circle( Circle&& other )
	: Shape( std::move( other  ) )
{
	*this = std::move( other );
}
//-----------------------------------------------------------------------------------------------//
Circle& Circle::operator=( const Circle& other )
{
	if( this != &other )
	{
		Shape::operator=( other );

		m_radius = other.m_radius;
	}

	return *this;
}
//-----------------------------------------------------------------------------------------------//
Circle& Circle::operator=( Circle&& other )
{
	if( this != &other )
	{
		Shape::operator=( std::move( other ) );

		m_radius = other.m_radius;
	}

	return *this;
}
//-----------------------------------------------------------------------------------------------//
void Circle::toOs( ostream& os ) const
{
	os << ", Radius: " << m_radius;
}
//-----------------------------------------------------------------------------------------------//
float Circle::getArea() const
{
	return m_radius * m_radius * PI;
}
//-----------------------------------------------------------------------------------------------//
float Circle::getPerimeter() const
{
	return 2.f * m_radius * PI;
}
//-----------------------------------------------------------------------------------------------//