#pragma once
#include "Action.h"
#include "..\AppManagerIncludes.h"
class CutAction :
	public Action 
{
	
public:
	CutAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	

	virtual void Execute();
	~CutAction(void);
};

