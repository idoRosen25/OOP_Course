#include "Title.h"

//-----------------------------------------------------------------------------------------------//
Title::Title( const char* name, const char* author )
{
	cout << "Title C'tor" << endl;
	
	//m_name = nullptr;
	//m_author = nullptr;
	SetName( name );
	SetAuthor( author );
}
//-----------------------------------------------------------------------------------------------//
Title::Title( const Title& other )
{
	cout << "Title Copy C'tor" << endl;

	//m_name = nullptr;
	//m_author = nullptr;
	SetName( other.m_name );
	SetAuthor( other.m_author );
}
//-----------------------------------------------------------------------------------------------//
Title::Title( Title&& other )
{
	cout << "Title Move C'tor" << endl;

	m_name = other.m_name;
	m_author = other.m_author;

	other.m_name = nullptr;
	other.m_author = nullptr;
}
//-----------------------------------------------------------------------------------------------//
Title::~Title()
{
	cout << "Title D'tor" << endl;

	if( m_name )
		delete[] m_name;

	if( m_author )
		delete[] m_author;
}
//-----------------------------------------------------------------------------------------------//
void Title::SetName( const char* name )
{
	if( m_name )
		delete[] m_name;
	
	if( name )
		m_name = _strdup( name );
	else
		m_name = nullptr;
}
//-----------------------------------------------------------------------------------------------//
void Title::SetAuthor( const char* author )
{
	if( m_author )
		delete[] m_author;

	if( author )
		m_author = _strdup( author );
	else
		m_author = nullptr;
}
//-----------------------------------------------------------------------------------------------//
void Title::Print() const
{
	cout << "TITLE\n";
	if( m_name )
		cout << "Name: " << m_name;

	if( m_author )
		cout << ", Author: " << m_author << ", ";
}
//-----------------------------------------------------------------------------------------------//