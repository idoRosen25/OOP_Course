#ifndef __CIRCLE_H
#define __CIRCLE_H

#pragma warning(disable: 4996)

#include "shape.h"

class Circle : public Shape
{
public:
	Circle( float frameWidth, const char* color, float radius );
	Circle( const Circle& other );// = default;
	Circle( Circle&& other );// = default;
	virtual ~Circle() {}

public:
	virtual Circle& operator=( const Circle& other );// = default;
	virtual Circle& operator=( Circle&& other );// = default;

public:
	virtual void toOs( ostream& os ) const override;
	virtual float getArea() const override;
	virtual float getPerimeter() const override;

protected:
	constexpr static float PI = 3.14f;

	float m_radius;
};

#endif