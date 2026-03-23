#ifndef __SURVIVORS_H
#define __SURVIVORS_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

class Survivor {
public:
    enum eStatus { SINGLE, MARRIED, IN_A_RELATIONSHIP };
    static constexpr char* familyStatusStr[] = {"Single", "Married", "In_A_Relationship"};

public:
    Survivor( const char* name, int age, eStatus status);
    Survivor( const Survivor& );
    Survivor( Survivor&&);
    ~Survivor();

public:
    inline void setName( const char* name );
    inline void setAge( int age );
    inline void setStatus( eStatus status );
    inline const char* getName() const;
    inline int getAge() const;
    inline eStatus getStatus() const;

    // void init( const char* name, int age, eStatus status );
    void print() const;

private:
    char* m_name = nullptr;
    int m_age;
    eStatus m_status;
};

#endif // __SURVIVORS_H
