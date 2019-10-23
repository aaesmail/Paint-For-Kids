#pragma once
#include "Action.h"
class Exit :
	public Action
{
public:
	Exit(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Exit();
};

