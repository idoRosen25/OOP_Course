#include "AllShapes.h"
#include "circle.h"
#include "square.h"

//-----------------------------------------------------------------------------------------------//
AllShapes::AllShapes( int size /*= 10 */ )
{
	m_shapesCount = 0;
	m_shapesSize = size;
	m_shapes = new Shape*[m_shapesSize];
}
//-----------------------------------------------------------------------------------------------//
AllShapes::~AllShapes()
{
	for( int i = 0; i < m_shapesCount; ++i )
		delete m_shapes[i];

	delete[] m_shapes;
}
//-----------------------------------------------------------------------------------------------//
void AllShapes::AddShape( const Shape* s )
{
	if( m_shapesCount >= m_shapesSize )
		return;

	if( typeid( *s ) == typeid( Circle ) )
		m_shapes[m_shapesCount++] = new Circle( *( (Circle*)s ) );
	else if( typeid( *s ) == typeid( Square ) )
		m_shapes[m_shapesCount++] = new Square( *( (Square*)s ) );
}
//-----------------------------------------------------------------------------------------------//
void AllShapes::PrintShapes() const
{
	for( int i = 0; i < m_shapesCount; i++ )
	{
		cout << *m_shapes[i];
		cout << endl;

		Square* square = dynamic_cast<Square*>( m_shapes[i] );
		if( square )
			square->draw();
	}
}
//-----------------------------------------------------------------------------------------------//