#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"

//include all figures
#include "..\Figures\CRectangle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CRhombus.h"

class PickAndHide: public Action
{
public:
	PickAndHide(ApplicationManager* pAct);



	void hideFig(CFigure* fig); //hides figure when clicked on
	void gameLoop(int &rightPicks, int &wrongPicks, const int &RndmFig, int &nReqPicks, int mode, ActionType &act);

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() = 0;
	//Execute action (code depends on action type)
	virtual void Execute() = 0;
	~PickAndHide(void);
};

