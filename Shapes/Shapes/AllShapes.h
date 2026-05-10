#ifndef __ALLSHAPES_H
#define __ALLSHAPES_H

#pragma warning(disable: 4996)

#include "shape.h"

class AllShapes
{
public:
	AllShapes( int size = 10 );
	~AllShapes();

public:
	void AddShape( const Shape* s );
	void PrintShapes() const;

private:
	Shape** m_shapes;
	int		m_shapesSize;
	int		m_shapesCount;
};

#endif