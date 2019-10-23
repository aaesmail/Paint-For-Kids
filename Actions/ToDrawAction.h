#pragma once
#include "Action.h"

class ToDrawAction: public Action
{
public:
	ToDrawAction(ApplicationManager* pAct);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	~ToDrawAction(void);
};

