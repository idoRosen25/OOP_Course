//-----------------------------------------------------------------------------------------------//
#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------------------------//
#include "AllShapes.h"
#include "square.h"
#include "circle.h"
//-----------------------------------------------------------------------------------------------//
enum eShapeType { SQUARE = 1, CIRCLE };
//-----------------------------------------------------------------------------------------------//
void main()
{
	int shapesSize;

	cout << "Please enter the amount of shapes:" << endl;
	cin >> shapesSize;

	AllShapes shapes(shapesSize);
	Shape* s;

	for (int i = 0; i < shapesSize; i++)
	{
		int shapeType;
		float frameWidth;
		char color[30];

		cout << "Enter 1 for square or 2 for circle:" << endl;
		cin >> shapeType;

		cout << "Please enter the frameWidth and the color:" << endl;
		cin >> frameWidth >> color;

		switch (shapeType)
		{
		case SQUARE:
		{
			float sideLength;

			cout << "Please enter the side length:" << endl;
			cin >> sideLength;

			s = new Square(frameWidth, color, sideLength);

			break;
		}
		case CIRCLE:
		{
			float radius;

			cout << "Please enter the radius:" << endl;
			cin >> radius;

			s = new Circle(frameWidth, color, radius);

			break;
		}
		default:
			cout << "Invalid choice, try again..\n";
			i--;
			continue;
		}

		shapes.AddShape(s);
	}

	shapes.PrintShapes();

	system("pause");
}
//-----------------------------------------------------------------------------------------------//