#pragma once

#include "Action.h"


class ToPlayAction: public Action
{
public:
	ToPlayAction( ApplicationManager* pAct);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	~ToPlayAction(void);
};

