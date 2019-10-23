#pragma once

#include "Action.h"
#include "..\Figures\CFigure.h"

class SendToBack : public Action
{
private:
	CFigure* figure;

public:
	SendToBack(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	virtual void Execute();

	~SendToBack();
};
