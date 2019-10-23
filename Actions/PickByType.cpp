#include "PickByType.h"







PickByType::PickByType(ApplicationManager* pAct):PickAndHide(pAct)
{
}

void PickByType::ReadActionParameters(){
} //no action parameter needed from the user



void PickByType::Execute(){
	pManager->restoreHiddenFigs(); //to restore the hidden figures when the user restarts the game
	pManager->UpdateInterface();
	Output* pOut = pManager->GetOutput();


	const int RndmFig = pManager->getRndFigure(0);
	
	if(RndmFig != -1){
		char* figName;
		switch(RndmFig){
		case 1:
			figName = "Rectangle";
			break;
		case 2:
			figName = "Line";
			break;
		case 3:
			figName = "Triangle";
			break;
		case 4:
			figName = "Rhombus";
			break;
		case 5:
			figName = "Ellipse";
			break;
		
		}
		pOut->PrintMessage(std::string("Here we Go...Pick the figure [") + std::string(figName) + std::string("]! ...Click anywhere to start picking") );

		ActionType act = EMPTY;

		int  rightPicks, wrongPicks, nReqFigs;
		nReqFigs = pManager->figsOfSameType(0,RndmFig);
		gameLoop(rightPicks, wrongPicks, RndmFig, nReqFigs, 0, act);

		if(act == EMPTY){
			if(rightPicks == nReqFigs && wrongPicks == 0){
				pOut->PrintMessage(std::string("You Win!...Congrats your picks are all correct!  you picked ") + std::to_string(rightPicks) + std::string(" right picks and no wrong picks!"));
			}else{
				pOut->PrintMessage(std::string("Game Over...You picked :") + std::to_string(rightPicks) + std::string(" right picks") + std::string("               ") + std::to_string(wrongPicks)+ std::string(" wrong picks "));
			
			}
		}
		else if(act == PICKPROP){
			pManager->ExecuteAction(PICKPROP);
		}
		else if(act == PICKCLR){
			pManager->ExecuteAction(PICKCLR);
		}
		else if(act == TO_DRAW){
			pManager->ExecuteAction(TO_DRAW);
		}
		else if(act == EXIT){
			pManager->ExecuteAction(EXIT);
		}
	}else{
			pOut->PrintMessage("You have no figures in your draw area...Switch to draw mode to draw some figures");
	}
	
}


PickByType::~PickByType(void)
{
}
