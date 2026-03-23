#ifndef __TRIBE_H
#define __TRIBE_H

#include "survivor.h"

class Tribe 
{
public:
	Tribe( int maxSurvivors);
	Tribe( const Tribe&);
	Tribe( Tribe&& );
	~Tribe();

	bool addSurvivor(Survivor& newSurvivor);

	/*inline*/ Survivor** getAllSurvivors();
	/*inline*/ int getMaxSurvivors() const;
	/*inline*/ int getCurrentNumOfSurvivors() const;

	void print() const;

private:
	Survivor**	m_allSurvivors;
	int			m_maxSurvivors;
	int			m_currentNumOfSurvivors;
};

#endif // __TRIBE_H