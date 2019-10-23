#include "CutAction.h"



CutAction::CutAction(ApplicationManager *pApp):Action(pApp)
{
}


void CutAction::ReadActionParameters()
{
}

void CutAction::Execute()
{

	Output* pOut = pManager->GetOutput();

	
	

	
	if ( (pManager->getSelected()) == NULL)
	{
		pOut->PrintMessage("No figure is selected");
		return;
	}
	Point P1 = { 0,0 }, P2 = { 0,0 }, P3 = { 0,0 }; GfxInfo TempGfx; 
	CFigure* copiedfig;
	TempGfx = (pManager->getSelected())->GetFigGfxInfo();
	

	if (dynamic_cast<CRectangle*>(pManager->getSelected())) { 
		pManager->getSelected()->GetFigPoints(P1, P2);
		copiedfig = new CRectangle(P1, P2, TempGfx);
	}
	else if (dynamic_cast<CLine*>(pManager->getSelected())) { 
		pManager->getSelected()->GetFigPoints(P1, P2);
		copiedfig = new CLine(P1, P2, TempGfx);
	}
	else if (dynamic_cast<CEllipse*>(pManager->getSelected())) {
		pManager->getSelected()->GetFigPoints(P1);
		copiedfig = new CEllipse(P1, TempGfx);
	}
	else if (dynamic_cast<CTriangle*>(pManager->getSelected())) { 
		pManager->getSelected()->GetFigPoints(P1, P2, P3);
		copiedfig = new CTriangle(P1, P2, P3, TempGfx);
	}
	else if (dynamic_cast<CRhombus*>(pManager->getSelected())) {
		pManager->getSelected()->GetFigPoints(P1);
		copiedfig = new CRhombus(P1, TempGfx);

	}
	
	
	if (pManager->getIsCut() )
	{
		
		(pManager->getCutFig())->ChngDrawClr( (pManager->AccessClipboard())->GetFigGfxInfo() .DrawClr );
		(pManager->getCutFig())->ChngFillClrCut( (pManager->AccessClipboard())->GetFigGfxInfo() .FillClr );
		(pManager->getCutFig())->SetIsFilled( ( pManager->AccessClipboard() )->GetFigGfxInfo().isFilled);
		pManager->setIsCut(false);
		pManager->setCutFig(NULL);
		pOut->ClearDrawArea();

	}
	pManager->setCutFig(pManager->getSelected());
	(pManager->getCutFig() )->ChngDrawClr(GREY);
	(pManager->getCutFig() )->ChngFillClr(LIGHTGREY);
	pManager->setIsCut(true);
	pManager->ClearClipboard();
	pManager->getSelected()->SetSelected(false);
	pManager->setClipboard(copiedfig);
	pManager->setSelected(NULL, false);
	pOut->PrintMessage("Figure saved to clipboard (Y)");

}


CutAction::~CutAction(void)
{
}
