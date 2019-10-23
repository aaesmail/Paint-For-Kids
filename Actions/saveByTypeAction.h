#pragma once
#include "Action.h"
class saveByTypeAction :
	public Action
{
	ActionType ThisAction;
public:
	saveByTypeAction(ApplicationManager*);
	void ReadActionParameters();
	FigureType SavedType();
	void Execute();
	~saveByTypeAction();
};

