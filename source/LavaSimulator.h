#pragma once
#include "FluidSimulator.h"

class cLavaSimulator : public cFluidSimulator
{
public:
	cLavaSimulator( cWorld* a_World );

	virtual bool IsAllowedBlock( char a_BlockID );
	

};