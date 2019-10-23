#include "ToDrawAction.h"

#include "..\ApplicationManager.h"

ToDrawAction::ToDrawAction(ApplicationManager* pAct):Action(pAct)
{
}
//Reads rectangle parameters
void ToDrawAction::ReadActionParameters(){
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("You switched to Draw mode... Don't think about making art, just get it done.!");
}

//Add rectangle to the ApplicationManager
void ToDrawAction::Execute(){
	
	ReadActionParameters();
	pManager->restoreHiddenFigs();
}

ToDrawAction::~ToDrawAction(void)
{
}
