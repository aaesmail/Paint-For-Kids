#pragma once
#include "Action.h"

#include "..\AppManagerIncludes.h"

class CopyAction :
	public Action 
{
	
public:
	CopyAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	~CopyAction(void);
};

