#include "set.h"
//-----------------------------------------------------------------------------------------------//
Set::Set( int maxSize )
	:	m_maxSize( maxSize ), 
		m_currentSize( 0 )
{
	cout << "**** in C'tor ****" << endl;
	m_arr = new int[maxSize];
}
//-----------------------------------------------------------------------------------------------//
Set::Set( const Set& other ) 
	:	m_arr( nullptr)
{
	cout << "**** in Copy C'tor ****" << endl;
	*this = other;
}
//-----------------------------------------------------------------------------------------------//
Set::Set( Set&& other )
	: m_arr( nullptr )
{
	cout << "**** in Move C'tor ****" << endl;
	*this = std::move( other );
}
//-----------------------------------------------------------------------------------------------//
Set::~Set()
{
	cout << "**** in D'tor ****" << endl;
	delete[] m_arr;
}
//-----------------------------------------------------------------------------------------------//
const Set& Set::operator=( const Set& other )
{
	cout << "**** in operator= ****" << endl;
	if( this != &other )
	{
		delete[] m_arr;
		m_maxSize = other.m_maxSize;
		m_currentSize = other.m_currentSize;
		m_arr = new int[m_maxSize];
		for( int i = 0; i < m_currentSize; ++i )
			m_arr[i] = other.m_arr[i];
	}

	return *this;
}
//-----------------------------------------------------------------------------------------------//
const Set& Set::operator=( Set&& other )
{
	cout << "**** in Move operator= ****" << endl;
	if( this != &other )
	{
		delete[] m_arr;

		m_maxSize = other.m_maxSize;
		m_currentSize = other.m_currentSize;
		m_arr = other.m_arr;

		other.m_arr = nullptr;
	}

	return *this;
}
//-----------------------------------------------------------------------------------------------//
Set operator+( int newVal, const Set& set )
{
	cout << "**** in operator+( int, Set ) ****" << endl;
	return set + newVal;
}
//-----------------------------------------------------------------------------------------------//
Set operator+( const Set& set, int newVal )
{
	cout << "**** in operator+( Set, int ) ****" << endl;
	if( set.exists( newVal ) )
		return set;

	Set temp( set );
	temp.m_arr[temp.m_currentSize++] = newVal;
	return temp;
}
//-----------------------------------------------------------------------------------------------//
Set Set::operator+( const Set& other ) const
{
	cout << "**** in operator+( Set ) ****" << endl;
	Set temp( m_currentSize + other.m_currentSize );

	for( int i = 0; i < m_currentSize; i++ )
		temp += m_arr[i];

	for( int i = 0; i < other.m_currentSize; ++i )
		temp += other.m_arr[i];

	return temp;
}
//-----------------------------------------------------------------------------------------------//
const Set& Set::operator+=( int newVal )
{
	cout << "**** in operator+= ****" << endl;
	if( !exists( newVal ) )
		m_arr[m_currentSize++] = newVal;

	return *this;
}
//-----------------------------------------------------------------------------------------------//
bool Set::operator>( const Set& other ) const
{
	cout << "**** in operator> ****" << endl;
	return m_currentSize > other.m_currentSize;
}
//-----------------------------------------------------------------------------------------------//
bool Set::operator==( const Set& other ) const
{
	cout << "**** in operator== ****" << endl;
	if( m_currentSize != other.m_currentSize )
		return false;

	for( int i = 0; i < m_currentSize; ++i )
	{
		if( !other.exists( m_arr[i] ) )
			return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------------//
bool Set::operator!=( const Set& other ) const
{
	cout << "**** in operator!= ****" << endl;
	return !( *this == other );
}
//-----------------------------------------------------------------------------------------------//
int& Set::operator[]( int index )
{
	cout << "**** in operator[] ****" << endl;
	return m_arr[index];
}
//-----------------------------------------------------------------------------------------------//
const Set& Set::operator++()
{
	cout << "**** in operator++ ****" << endl;
	for( int i = 0; i < m_currentSize; ++i )
		++(m_arr[i]);

	return *this;
}
//-----------------------------------------------------------------------------------------------//
Set Set::operator++( int )
{
	cout << "**** in operator++( int ) ****" << endl;
	Set temp( *this );

	++( *this );

	return temp;
}
//-----------------------------------------------------------------------------------------------//
bool Set::exists( int value ) const
{
	for( int i = 0; i < m_currentSize; ++i )
	{
		if( m_arr[i] == value )
			return true;
	}

	return false;
}
//-----------------------------------------------------------------------------------------------//
ostream& operator<<( ostream& os, const Set& obj )
{
	cout << "**** in operator<< ****" << endl;
	for( int i = 0; i < obj.m_currentSize; i++ )
	{
		os << obj.m_arr[i] << " ";
	}

	return os;
}
//-----------------------------------------------------------------------------------------------//