#pragma once
#include "Action.h"
class loadAction :
	public Action
{
	ActionType ThisAction;
public:
	loadAction(ApplicationManager*);
	virtual void ReadActionParameters();
	void ReadFigures(ifstream&);
	virtual void Execute();
	void QuickLoad();
	
	~loadAction();
};

