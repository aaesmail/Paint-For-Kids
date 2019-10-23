#include "PickAndHide.h"

PickAndHide::PickAndHide(ApplicationManager* pAct):Action(pAct)
{
}

void PickAndHide::hideFig(CFigure* fig){
	fig->setIsHidden(true);
}

void PickAndHide::gameLoop(int &rightPicks, int &wrongPicks, const int &RndmFig, int &nReqPicks, int mode, ActionType &act){
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	
	pIn->GetPointClicked(x,y);
	rightPicks = 0;
	wrongPicks = 0;
	int compareValue;
	
	//game loop
	pOut->PrintMessage(std::string("Right picks: ") + std::to_string(rightPicks) + std::string("   Wrong picks: ") + std::to_string(wrongPicks));
	bool changeMode = false;
	while(rightPicks < nReqPicks && !changeMode){



		//Add exit option-------------------------------------------------------------------

		pIn->GetPointClicked(x, y);
		if(y < 50){
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_PICKPROP:
				act = PICKPROP;
				return;
			case ITM_PICKCLR:
				act = PICKCLR;
				return;
			case ITM_SWITCHDRAW:
				act = TO_DRAW;
				return;
			case ITM_EXIT2:
				act = EXIT;
				return;

			default: 	//A click on empty place in desgin toolbar
				break;
			}
			
		}
		CFigure* pickedFig = pManager->GetFigure(x,y);
		if(pickedFig != NULL && !pickedFig->getIsHidden()){

			if(mode == 0)
				compareValue = pickedFig->getFigType();
			else if(mode == 1)
				compareValue = pickedFig->getFigColor();

			if(compareValue == RndmFig){
				rightPicks++;
			}
			else{
				wrongPicks++;

			}
			pOut->PrintMessage(std::string("Right picks: ") + std::to_string(rightPicks) + std::string("   Wrong picks: ") + std::to_string(wrongPicks));
			hideFig(pickedFig);
			pManager->UpdateInterface();
	
		}
		
	
	}
}






PickAndHide::~PickAndHide(void)
{
}
