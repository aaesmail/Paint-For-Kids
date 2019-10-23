#pragma once

#include "PickAndHide.h"

class PickByType: public PickAndHide
{
public:
	PickByType(ApplicationManager* pAct);

	virtual void ReadActionParameters();
	virtual void Execute();
	~PickByType(void);
};

