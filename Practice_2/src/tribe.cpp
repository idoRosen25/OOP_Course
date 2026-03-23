#include "tribe.h"
//----------------------------------------------------------------------------------------//
Tribe::Tribe( int maxSurvivors){
	cout << "In Tribe ctor maxSurvivors="<< maxSurvivors << endl;
	m_maxSurvivors=maxSurvivors;
	m_currentNumOfSurvivors=0;
	m_allSurvivors = new Survivor*[m_maxSurvivors];
}
//----------------------------------------------------------------------------------------//
Tribe::Tribe( const Tribe& tribe){
	
	m_maxSurvivors=tribe.m_maxSurvivors;
	m_currentNumOfSurvivors=tribe.m_currentNumOfSurvivors;
	m_allSurvivors = new Survivor*[m_maxSurvivors];
	for( int i=0; i<m_currentNumOfSurvivors;i++){
		m_allSurvivors[i]= new Survivor(*(tribe.m_allSurvivors[i]));
	}
}
//----------------------------------------------------------------------------------------//
Tribe::Tribe( Tribe&& tribe){
	
	m_maxSurvivors=tribe.m_maxSurvivors;
	m_currentNumOfSurvivors=tribe.m_currentNumOfSurvivors;
	m_allSurvivors = tribe.m_allSurvivors;

	tribe.m_allSurvivors = nullptr;
	tribe.m_currentNumOfSurvivors=0;
}
//----------------------------------------------------------------------------------------//
Tribe::~Tribe(){
	cout << "In Tribe dtor for _currentNumOfSurvivors=" << m_currentNumOfSurvivors << endl;

	for(int i=0;i<m_currentNumOfSurvivors;i++){
		delete m_allSurvivors[i];
	}

	delete[] m_allSurvivors;
}
//----------------------------------------------------------------------------------------//
bool Tribe::addSurvivor( Survivor& newSurvivor )
{
	if(m_currentNumOfSurvivors < m_maxSurvivors){
		m_allSurvivors[m_currentNumOfSurvivors++] = &newSurvivor;
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------------------//
Survivor** Tribe::getAllSurvivors()
{
	return m_allSurvivors;
}
//----------------------------------------------------------------------------------------//
int Tribe::getCurrentNumOfSurvivors() const
{
	return m_currentNumOfSurvivors;
}
//----------------------------------------------------------------------------------------//
int Tribe::getMaxSurvivors() const
{
	return m_maxSurvivors;
}
//----------------------------------------------------------------------------------------//
void Tribe::print() const
{

	for(int i = 0; i< m_currentNumOfSurvivors; ++i){
		m_allSurvivors[i]->print();
	}
}
