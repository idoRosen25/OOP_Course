#include "survivor.h"

Survivor::Survivor( const char* name, int age, eStatus status){
     cout << "In Survivor's ctor for " << name <<endl;
     setName ( name);
     setAge( age );
     setStatus( status );
}

Survivor::Survivor( const Survivor& s){
     cout << "In Survivor's copy ctor for " << m_name <<endl;
     setName ( s.m_name);
     setAge( s.m_age );
     setStatus( s.m_status );
}

Survivor::Survivor( Survivor&& other){
     cout << "In Survivor's move ctor for " << m_name <<endl;
     m_name = other.m_name;
     setAge( other.m_age );
     setStatus( other.m_status);
     other.m_name=nullptr;
}

Survivor::~Survivor(){
    cout << "In Survivor dtor for " << m_name << endl;
    delete[] m_name;
}

void Survivor::setName( const char* name) {

   delete[] m_name;
   m_name = new char[strlen(name)+1];
    strcpy( m_name, name );

}

void Survivor::setAge( int age ) {
    m_age = age;
}

void Survivor::setStatus( Survivor::eStatus status ) {
    m_status = status;
}

const char* Survivor::getName() const {
    return m_name;
}

int Survivor::getAge() const {
    return m_age;
}

Survivor::eStatus Survivor::getStatus() const {
    return m_status;
}

void Survivor::print() const {
    cout << "name: " << m_name << endl << "age: " << m_age << endl << "status: " << familyStatusStr[m_status] << endl;
}