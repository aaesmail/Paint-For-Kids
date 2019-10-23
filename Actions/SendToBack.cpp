#include "SendToBack.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SendToBack::SendToBack(ApplicationManager *pApp) : Action(pApp)
{
}

void SendToBack::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();
	pOut->PrintMessage("Sent to Back!");
}

void SendToBack::Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure* selected_figure = pManager->getSelected();

	if (selected_figure) {
		ReadActionParameters();
		int location = pManager->findFigure(selected_figure);
		pManager->sendtoback(location);
	}
	else
		pOut->PrintMessage("Please select a figure first!");
}


SendToBack::~SendToBack()
{
}
