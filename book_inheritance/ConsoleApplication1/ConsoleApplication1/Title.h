#ifndef TITLE_H
#define TITLE_H
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

class Title
{
public:
	Title( const char* name = nullptr, const char* author = nullptr );
	Title( const Title& other );
	Title( Title&& other );
	~Title();

public:
	void SetName( const char* name );
	void SetAuthor( const char* author );

	const char* GetName() const { return m_name; }
	const char* GetAuthor() const { return m_author; }

public:
	void Print()const;

protected:
	char* m_name = nullptr;
	char* m_author = nullptr;
};

#endif