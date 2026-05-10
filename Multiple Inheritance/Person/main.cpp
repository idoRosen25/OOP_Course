#include <iostream>
using namespace std;

#include "person.h"
#include "employee.h"

void main()
{
	{
		Date d1( 2, 3, 2009 );
		cout << "1------------------------------\n";
		Person p1( "gogo", d1 );
		cout << "2------------------------------\n";
		Person p2( p1 );
		cout << "3------------------------------\n";
		Person p3( "momo", Date( 1, 2, 2000 ) );
		cout << "p3 is: " << p3 << endl;
		cout << "4------------------------------\n";

		Employee e1( p1, Date( 10, 12, 2030 ), "Amdocs" );
		cout << "5------------------------------\n";
		Employee e2( Person( "yoyo", Date( 1, 1, 1970 ) ), d1, "Comverse" );
		cout << "6------------------------------\n";
		Employee e3( e2 );
		cout << "e3 is: " << e3 << endl;
		cout << "7------------------------------\n";
	}
	system( "pause" );
}