#ifndef __SET_H
#define __SET_H

#include <iostream>
using namespace std;

class Set
{
public:
	Set( int maxSize = 1000 );//1
	Set( const Set& other );//3
	Set( Set&& other );//4
	~Set();//2

public:
	const Set& operator=( const Set& other );//5
	const Set& operator=( Set&& other );//6

public:
	friend Set operator+( int newVal, const Set& set );//7
	friend Set operator+( const Set& set, int newVal );//7

public:
	Set        operator+( const Set& other )  const;//8
	const Set& operator+=( int newVal );//9
	bool       operator>( const Set& other )  const;//11
	bool       operator==( const Set& other ) const;//12
	bool       operator!=( const Set& other ) const;//13
	int&       operator[]( int index );//14
	const Set& operator++();//15
	Set		   operator++( int );//15

public:
	friend ostream& operator<<( ostream& os, const Set& obj );//10

private:
	bool exists( int value ) const;

private:
	int  m_maxSize;
	int  m_currentSize;
	int* m_arr;
};

#endif // __SET_H