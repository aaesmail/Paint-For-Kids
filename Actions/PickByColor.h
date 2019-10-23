#pragma once
#include "PickAndHide.h"

class PickByColor: public PickAndHide
{
public:
	PickByColor(ApplicationManager* pAct);

	virtual void ReadActionParameters();
	virtual void Execute();

	~PickByColor(void);
};

