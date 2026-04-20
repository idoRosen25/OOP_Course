#include "Book_Title.h"
#include "Journal.h"
#include "Workbook_Title.h"
#include "Research_Title.h"

WorkbookTitle CreateWorkbook()
{
	WorkbookTitle w( "Learn c++", "Jonny Jonny", "OOP" );
	return w;
}

int main()
{
	BookTitle book;
	Journal journal;
	WorkbookTitle workbook;
	ResearchTitle research;

	book.SetName( "The Green Monkey" );
	book.SetAuthor( "John Grishem" );
	book.SetAddition( 2 );
	book.Print();

	journal.SetName( "Blazer" );
	journal.SetAuthor( "Yediot Aharonot" );
	journal.SetYear( 1855 );
	journal.Print();

	workbook.SetName( "Learn c++" );
	workbook.SetAuthor( "Jonny Jonny" );
	workbook.SetCourse( "OOP" );
	workbook.Print();

	research.SetName( "Robotics" );
	research.SetAuthor( "Someone" );
	research.SetSupervisor( "Somebody" );
	research.Print();

	BookTitle book1( "The Green Monkey", "John Grishem", 2 );
	Journal journal1( "Blazer", "Yediot Aharonot", 1855 );
	WorkbookTitle workbook1( "Learn c++", "Jonny Jonny", "OOP" );
	ResearchTitle research1( "Robotics", "Someone", "Somebody" );

	book1.Print();
	journal1.Print();
	workbook1.Print();
	research1.Print();

	BookTitle book2( book1 );
	Journal journal2( journal1 );
	WorkbookTitle workbook2( workbook1 );
	ResearchTitle research2( research1 );

	WorkbookTitle workbook3 = CreateWorkbook();
	workbook3.Print();

	return 0;
}