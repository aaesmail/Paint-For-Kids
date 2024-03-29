#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class SendToFront : public Action
{
private:
	CFigure* figure;

public:
	SendToFront(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~SendToFront();
};

