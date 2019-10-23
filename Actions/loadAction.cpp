#include "LoadAction.h"
#include "../ApplicationManager.h"


loadAction::loadAction(ApplicationManager * pApp) :Action(pApp)
{}

void loadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load Figures, click on the icon again to confirm.");
	ThisAction = pIn->GetUserAction();
	pOut->ClearStatusBar();
}

void SetFigType(CFigure *& FP, FigureType T)
{
	Point P1, P2, P3;
	P1 = P2 = P3 = { 400,400 };
	GfxInfo dummy;
	switch (T)
	{
	case LINE:
		FP = new CLine(P1, P2, dummy);
		break;

	case RECTANGLE:
		FP = new CRectangle(P1, P2, dummy);
		break;

	case TRIANGLE:
		FP = new CTriangle(P1, P2, P3, dummy);
		break;

	case RHOMBUS:
		FP = new CRhombus(P1, dummy);
		break;

	case ELLIPSE:
		FP = new CEllipse(P1, dummy);
		break;
	}
}
void loadAction::ReadFigures(ifstream& InFile)
{
	while (!InFile.eof())
	{
		CFigure* NewFig;
		string Cast;
		InFile >> Cast;
		FigureType FIG_TYPE = ReadType(Cast);
		if (FIG_TYPE == EMPTY_TYPE) break;
		SetFigType(NewFig, FIG_TYPE);
		NewFig->Load(InFile);
		pManager->AddFigure(NewFig);
	}
}

void loadAction::Execute()
{
	ReadActionParameters();
	if (ThisAction != LOAD)
		return;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Enter the name of the file  OR  Press [ENTER] to load from FigureList.txt");
	string FileName = pIn->GetString(pOut);
	FileName = (FileName != "") ? FileName : "FigureList.txt";
	ifstream InFile;
	InFile.open(FileName);

	color DrawClr = ReadColor(InFile);
	color FillClr = ReadColor(InFile);
	pOut->setCrntDrawColor(DrawClr);
	pOut->setCrntFillColor(FillClr);

	int NoOfFigures; InFile >> NoOfFigures;
	ReadFigures(InFile);

	InFile.close();
	pOut->PrintMessage("Loaded Successfully!");
}

void loadAction::QuickLoad()
{
	ifstream qin;
	qin.open("SaveGame.txt");
	UI.DrawColor = ReadColor(qin);
	UI.FillColor = ReadColor(qin);
	int NoOfFigures; qin >> NoOfFigures;
	ReadFigures(qin);
	qin.close();
}

loadAction::~loadAction()
{}