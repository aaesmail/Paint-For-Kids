#pragma once
#include "CopyAction.h"




CopyAction::CopyAction(ApplicationManager *pApp):Action(pApp)
{

}

void CopyAction::ReadActionParameters()
{
}

void CopyAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->getSelected()==NULL)
	{
		pOut->PrintMessage("Select a figure first!!");
		return;
	}
	Point P1 , P2 , P3;

	CFigure* copiedfig;

	
	if (pManager->getIsCut() )
	{
		
		(pManager->getCutFig())->ChngDrawClr( (pManager->AccessClipboard())->GetFigGfxInfo() .DrawClr );
		(pManager->getCutFig())->ChngFillClrCut( (pManager->AccessClipboard())->GetFigGfxInfo() .FillClr );
		(pManager->getCutFig())->SetIsFilled( ( pManager->AccessClipboard() )->GetFigGfxInfo().isFilled);
		pManager->setIsCut(false);
		pManager->setCutFig(NULL);
		pOut->ClearDrawArea();
	}

	if (pManager->getSelected()==NULL)
	{
		pOut->PrintMessage("Please select a figure first!!");
		return;
	}
	else if (dynamic_cast<CRectangle*>(pManager->getSelected()))
	{	

		(pManager->getSelected() )->GetFigPoints(P1,P2);
		copiedfig = new CRectangle(P1,P2, pManager->getSelected()->GetFigGfxInfo());

	}
	else if (dynamic_cast<CLine*>(pManager->getSelected()))
	{ 

		(pManager->getSelected())->GetFigPoints(P1, P2);
		copiedfig = new CLine(P1,P2, pManager->getSelected()->GetFigGfxInfo());

	}
	else if (dynamic_cast<CEllipse*>(pManager->getSelected())) 
	{ 

		(pManager->getSelected())->GetFigPoints(P1);
		copiedfig = new CEllipse(P1, pManager->getSelected()->GetFigGfxInfo());
		

	}
	else if (dynamic_cast<CTriangle*>(pManager->getSelected())) 
	{ 
		(pManager->getSelected())->GetFigPoints(P1, P2, P3);
		copiedfig = new CTriangle(P1,P2,P3, pManager->getSelected()->GetFigGfxInfo());

	}
	else if (dynamic_cast<CRhombus*>(pManager->getSelected())) 
	{
		CFigure* p= pManager->getSelected();
		p->GetFigPoints(P1);
		copiedfig = new CRhombus(P1, pManager->getSelected()->GetFigGfxInfo());
	}
	pManager->ClearClipboard();
	pManager->getSelected()->SetSelected(false);
	pManager->setClipboard(copiedfig);
	(pManager->AccessClipboard() )->setID(pManager->getID() );
	pManager->incID();
	pManager->setSelected(NULL, false);
	pOut->PrintMessage("Figure saved to clipboard (Y)");




}
CopyAction::~CopyAction()
{
}
