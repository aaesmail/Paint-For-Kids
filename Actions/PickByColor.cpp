#include "PickByColor.h"
#include <time.h> //used in random function

PickByColor::PickByColor(ApplicationManager* pAct):PickAndHide(pAct)
{
}

void PickByColor::ReadActionParameters(){
}//no action parameter needed from the user



void PickByColor::Execute(){
	pManager->restoreHiddenFigs(); //to restore the hidden figures when the user restarts the game
	pManager->UpdateInterface(); 

	bool stopGame = false; //changes if an error occurs
	Output* pOut = pManager->GetOutput();
	const int RndmFig = pManager->getRndFigure(1); //gets a random figure color-->  1-black 2-white 3-red 4-green 5-blue
	switch(RndmFig){
	case 1:
		pOut->PrintMessage(std::string("Here we Go...Pick the figures of color [") + std::string("Black") + std::string("]! ...Click anywhere to start picking") );
		break;
	case 2:
		pOut->PrintMessage(std::string("Here we Go...Pick the figures of color [") + std::string("White") + std::string("]! ...Click anywhere to start picking") );
		break;
	case 3:
		pOut->PrintMessage(std::string("Here we Go...Pick the figures of color [") + std::string("Red") + std::string("]! ...Click anywhere to start picking") );
		break;
	case 4:
		pOut->PrintMessage(std::string("Here we Go...Pick the figures of color [") + std::string("Green") + std::string("]! ...Click anywhere to start picking") );
		break;
	case 5:
		pOut->PrintMessage(std::string("Here we Go...Pick the figures of color [") + std::string("Blue") + std::string("]! ...Click anywhere to start picking") );
		break;
	case 0:
		pOut->PrintMessage("You have no figures with a fill color...Switch to draw mode to fill some figures[Note: Lines have no fill color]");
		stopGame = true;
		break;
	case -1:
		pOut->PrintMessage("You have no figures in your draw area...Switch to draw mode to draw some figures and fill them with colors to be able to pick by color");
		stopGame = true;
		break;
	default:
		pOut->PrintMessage("A fatal error occured...please try again");
		stopGame = true;
		break;
	}
	if(!stopGame){
		ActionType act = EMPTY;

		int  rightPicks, wrongPicks, nReqFigs;
		nReqFigs = pManager->figsOfSameType(1,RndmFig); //gets the # required figures to be picked that matches the random figure color
		gameLoop(rightPicks, wrongPicks, RndmFig, nReqFigs, 1, act);

		if(act == EMPTY){
			if(rightPicks == nReqFigs && wrongPicks == 0){
				pOut->PrintMessage(std::string("You Win!...Congrats your picks are all correct!  you picked ") + std::to_string(rightPicks) + std::string(" right picks and no wrong picks!"));
			}
			else{
				pOut->PrintMessage(std::string("Game Over...You picked :") + std::to_string(rightPicks) + std::string("    and :") + std::to_string(wrongPicks)+ std::string(" wrong picks "));
			
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
		
	}
	

}

PickByColor::~PickByColor(void)
{
}
