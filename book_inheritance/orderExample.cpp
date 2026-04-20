//--------------------------------- ctor.cpp --------------------------------------

#include <iostream>

using namespace std;

class A
{
public:
  A() { cout <<  "ctor:A\n"; }
  A( int x ) { cout << "ctor:A int\n"; }
  ~A() { cout << "dtor:A\n"; }
};

class B: public A
{
public:
  B() : A( 5 ) { cout << "ctor:B\n"; }     // creates A first
  ~B() { cout << "dtor:B\n"; }
  
private:
	A a1;
};

class C: public B
{
public:
  C() { cout << "ctor:C\n"; }    // creates B first
  ~C() { cout << "dtor:C\n"; }
};

class D: public C
{
public:
  D() { cout << "ctor:D\n"; }    // creates C first
  ~D() { cout << "dtor:D\n"; }

private:
	A a2;
};

int main()
{
	A a1;
	cout <<"********************" << endl;
	B b1;
	cout <<"********************" << endl;
	C c1;
	cout <<"********************" << endl;
	D d1;
	cout <<"********************" << endl;
	
	return 0;
}
