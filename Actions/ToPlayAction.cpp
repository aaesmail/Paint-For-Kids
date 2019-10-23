#include "ToPlayAction.h"
#include "..\ApplicationManager.h"

ToPlayAction::ToPlayAction(ApplicationManager* pAct):Action(pAct)
{
}
void ToPlayAction::ReadActionParameters(){
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("You switched to play mode... Choose a property");
	

}

void ToPlayAction::Execute(){
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->unselect();
}

ToPlayAction::~ToPlayAction(void)
{
}
