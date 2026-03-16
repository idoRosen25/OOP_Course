#include <iostream>
using namespace std;

/*
-------------------------------------------------
Function Overloading
-------------------------------------------------
*/
int add(int a, int b) {
    a = 10;
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// double add(double a, int b) {
//     return a + b + 0.5;
// }

// void printNumberFloat(float f) {
//     cout << "Float: " << f << endl;
// }

// void printNumberInt(int f) {
//     cout << "Double: " << f << endl;
// }
/*


-------------------------------------------------
Default Parameters
-------------------------------------------------
*/

// int power(int exponent = 2, int base){ // THIS IS NOT ALLOWED, DEFAULT/OPTIONAL PARAMS MUST BE LAST
//     int result = 1;
//     for(int i = 0; i < exponent; i++)
//         result *= base;
//     return result;
// }

// int power(int base = 2, int exponent = 2) {
//     int result = 1;
//     for(int i = 0; i < exponent; i++)
//         result *= base;
//     return result;
// }


int power(int base, int exponent = 2) {
    int result = 1;
    for(int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

/*
-------------------------------------------------
Pass by Reference
-------------------------------------------------
*/

void swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

/*
Return by reference example
*/

int& maxRef(int &a, int &b) {
    if(a > b)
        return a;
    return b;
}

/*
-------------------------------------------------
Inline Function
-------------------------------------------------
*/

inline int square(int x) {
    return x * x;
}

/*
-------------------------------------------------
Struct (C style)
-------------------------------------------------
*/

struct Point {
    int x;
    int y;
};

void printPoint(Point p) {
    cout << "Point(" << p.x << "," << p.y << ")" << endl;
}

/*
-------------------------------------------------
Class (C++ style)
-------------------------------------------------
*/

class Counter {

private:
    int value;

public:

    Counter(int v) {
        value = v;
        cout << "Constructor called\n";
    }

    void increment() {
        value++;
    }

    int getValue() {
        return value;
    }

    ~Counter() {
        cout << "Destructor called\n";
    }
};

/*
-------------------------------------------------
Memory Allocation
-------------------------------------------------
*/

void memoryExample(int length =5) {

    int *p = new int;
    cout << "Single value before: " << *p << endl;
    *p = 10;

    cout << "Single value: " << *p << endl;

    delete p;

        cout << "Single value: " << *p << endl;
        
    int *arr = new int[length];

    for(int i = 0; i < length; i++)
        arr[i] = i * 10;

    cout << "Array values: ";

    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";

    cout << endl;

    delete[] arr;
}

/*
-------------------------------------------------
Main
-------------------------------------------------
*/

int main() {

    // cout << "=== Function Overloading ===\n";
    // cout << add(2,3) << endl;
    // cout << add(2.5,3.1) << endl;

    // cout << "\n=== Default Parameters ===\n";
    // cout << power(2) << endl;
    // cout << power(2, 2) << endl;
    // cout << power(5) << endl;
    // cout << power(5, 2) << endl;
    // cout << power(2,3) << endl;

//     cout << "\n=== Pass By Reference ===\n";

//     int a = 5;
//     int b = 10;

//  cout << "a=" << a << " b=" << b << endl;

//     swapNumbers(a,b);

//     cout << "a=" << a << " b=" << b << endl;

//     cout << "\n=== Return By Reference ===\n";

//     maxRef(a,b) = 100;

//     cout << "a=" << a << " b=" << b << endl;

    // cout << "\n=== Inline Function ===\n";
    // cout << square(6) << endl;

    // cout << "\n=== Struct Example ===\n";

    // Point p = {3,4};
    // printPoint(p);

    // cout << "\n=== Class Example ===\n";

    // Counter c(10);
    // c.increment();

    // cout << "Counter value: " << c.getValue() << endl;

    cout << "\n=== Memory Allocation ===\n";

    memoryExample();

    cout << "\n=== cin / cout Example ===\n";

    int number;

    cout << "Enter a number: " << flush;
    cin >> number;

    cout << "You entered: " << number << endl;

    memoryExample(number);
    return 0;
}