#include "saveByTypeAction.h"

#include "../ApplicationManager.h"



saveByTypeAction::saveByTypeAction(ApplicationManager * pApp) :Action(pApp)
{}

void saveByTypeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Save by Figure Type, Click on any of the Figure Icons.");
	ThisAction = pIn->GetUserAction();
}

FigureType saveByTypeAction::SavedType()
{
	switch (ThisAction)
	{
	case DRAW_RECT:
		return RECTANGLE;

	case DRAW_TRI:
		return TRIANGLE;

	case DRAW_ELLIPSE:
		return ELLIPSE;

	case DRAW_RHOMBUS:
		return RHOMBUS;

	case DRAW_LINE:
		return LINE;

	default:
		return EMPTY_TYPE;
	}
}

void saveByTypeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	FigureType Saved = SavedType();
	if (Saved == EMPTY_TYPE)
	{
		pOut->PrintMessage("Cancelled!");
		return;
	}

	pOut->PrintMessage("Enter the name of the file including the extension  OR  Press [ENTER] to save to " + StoreType(Saved) + ".txt");
	string FileName = pIn->GetString(pOut);
	FileName = (FileName != "") ? FileName : StoreType(Saved) + ".txt";

	ofstream OutFile;
	OutFile.open(FileName);
	pManager->WriteFigures(OutFile, Saved);

	OutFile.close();
	pManager->GetOutput()->PrintMessage("Saved Successfully to " + FileName + "!");
}


saveByTypeAction::~saveByTypeAction()
{}
