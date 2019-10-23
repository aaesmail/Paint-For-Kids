#pragma once
#include "Action.h"
#include "..\AppManagerIncludes.h"
class PasteAction :
		public Action 
{
	Point P;
public:
	PasteAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	~PasteAction(void);
};

