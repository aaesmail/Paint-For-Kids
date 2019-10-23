#include "SendToFront.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SendToFront::SendToFront(ApplicationManager *pApp) : Action(pApp)
{
}

void SendToFront::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	pOut->ClearStatusBar();
	pOut->PrintMessage("Sent to Front!");
}

void SendToFront::Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure* selected_figure = pManager->getSelected();

	if (selected_figure) {
		ReadActionParameters();
		int location = pManager->findFigure(selected_figure);
		pManager->sendtofront(location);
	}
	else
		pOut->PrintMessage("Please select a figure first!");
}


SendToFront::~SendToFront()
{
}
