#include "AppManagerIncludes.h"
#include <time.h> //used in random function MohamedAdel

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	FigCount = 0;
	SelectedFig = NULL;
	isfilled = false;
	ID = 1;
	Clipboard = NULL;
	isCut = false;
	exiting = false;
	//////////////////////////////////////////////////////////////////////////////////////// MohamedAdel
	Mode = MODE_DRAW; // Changed in Play Mode to be used in the UpdateInterface func.
	soundIsEnabled = true;
	////////////////////////////////////////////////////////////////////////////////////////

	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case DRAW_RECT:
		pAct = new AddRectAction(this);
		break;

	case DRAW_LINE:
		pAct = new AddLineAction(this);
		break;

	case DRAW_ELLIPSE:
		pAct = new AddEllipseAction(this);
		break;

	case DRAW_TRI:
		pAct = new AddTriangleAction(this);
		break;

	case DRAW_RHOMBUS:
		pAct = new AddRhombusAction(this);
		break;

	case SELECT_FIGURE:
		pAct = new SelectFigureAction(this);
		break;

	case DRAWING_AREA:
		if (SelectedFig)
			pAct = new SelectFigureAction(this);
		break;

	case CHNG_DRAW_CLR:
		pAct = new ChangeDrawColorAction(this);
		break;

	case CHNG_FILL_CLR:
		pAct = new ChangeFillColorAction(this);
		break;
	
	case DEL:
		pAct = new DeleteFigureAction(this);
		break;
	case CPY_FIG:
		pAct = new CopyAction(this);
		break;
	case CUT_FIG:
		pAct = new CutAction(this);
		break;
	case PASTE_FIG:
		pAct = new PasteAction(this);
		break;
	case SAVE : 
		pAct = new SaveAction(this);
		break;
	case SAVE_BY_TYPE :
		pAct = new saveByTypeAction(this);
		break;
	case LOAD:
		pAct = new loadAction(this);
		break;
	case SNDFRNT:
		pAct = new SendToFront(this);
		break;
	case SNDBK:
		pAct = new SendToBack(this);
		break;
	case EXIT:
		pAct = new Exit(this);
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////////  MohamedAdel
	case TO_PLAY:
		pAct = new ToPlayAction(this);
		Mode = MODE_PLAY;
		break;
	case PICKPROP:
		pAct = new PickByType(this);
		break;
	case PICKCLR:
		pAct = new PickByColor(this);
		break;
	case TO_DRAW:
		pAct = new ToDrawAction(this);
		Mode = MODE_DRAW;
		break;
	case VOICE:
		pAct = new Sound(this);
		break;
//////////////////////////////////////////////////////////////////////////////////////////////////////
	case STATUS:	//a click on the status bar ==> no action
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
void ApplicationManager::WriteFigures(ofstream& OutFile)
{
	OutFile << ColorData(UI.DrawColor) << " " << ColorData(UI.FillColor) << endl;
	OutFile << FigCount;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(OutFile);
}

void ApplicationManager::WriteFigures(ofstream & OutFile, FigureType SavedType)
{
	int TypeCount = 0;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getType() == SavedType)
			TypeCount++;
	OutFile << ColorData(UI.DrawColor) << " " << ColorData(UI.FillColor) << endl;
	OutFile << TypeCount;
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->getType() == SavedType)
			FigList[i]->Save(OutFile);
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	CFigure* try_to_select = NULL;

	for (int i = FigCount - 1; i >= 0; i--) {
		try_to_select = FigList[i]->insideme(x, y);
		if (try_to_select)
			break;
	}

	return try_to_select;
}

void ApplicationManager::setSelected(CFigure* try_to_select, bool ifselected)
{
	if (ifselected) {
		SelectedFig = try_to_select;
	}
	else {
		SelectedFig = NULL;
	}
}

CFigure *ApplicationManager::getSelected()
{
	return SelectedFig;
}
int ApplicationManager::getfigcount()
{
	return FigCount;
}
int ApplicationManager::findFigure(CFigure * figure)
{
	int index = 0;
	for (int i = 0; i < FigCount; i++) {
		if (figure == FigList[i]) {
			index = i;
			break;
		}
	}
	return index;
}

void ApplicationManager::decFigCount(int index)
{
	FigList[index] = FigList[--FigCount];
	FigList[FigCount] = NULL;
}

int ApplicationManager::getID()
{
	return ID;
}

void ApplicationManager::incID()
{
	ID++;
}

void ApplicationManager::sendtofront(int location)
{
	CFigure* temp = SelectedFig;
	FigList[location] = FigList[FigCount - 1];
	FigList[FigCount - 1] = temp;
}

void ApplicationManager::sendtoback(int location)
{
	CFigure* temp = SelectedFig;
	FigList[location] = FigList[0];
	FigList[0] = temp;
}

void ApplicationManager::unselect()
{
	SelectFigureAction unSelectObject(this);
	unSelectObject.unselect();
}
void ApplicationManager::setFill(bool s)
{
	isfilled = s;
}
bool ApplicationManager::getFill()
{
	return isfilled;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	if (!exiting) {

		if (Mode == MODE_DRAW) {
			for (int i = 0; i < FigCount; i++)
				FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
		}
		else if (Mode == MODE_PLAY) { //MohamedAdel ->playMode
			pOut->ClearDrawArea();
			for (int i = 0; i < FigCount; i++) {
				if (!FigList[i]->getIsHidden())
					FigList[i]->Draw(pOut);
			}

		}

	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////  MohamedAdel

int ApplicationManager::getRndFigure(int prop) { //0-->byType  -->byColor

	if (FigCount > 0) {
		int FigsWithoutLinesCount = 0; //no. of figures without lines (lines has no fill color)
		CFigure* FigsNoLines[200];  //array of figures without lines (lines has no fill color)

		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CLine*>(FigList[i]) == NULL) {
				FigsNoLines[FigsWithoutLinesCount] = FigList[i];
				FigsWithoutLinesCount++;
			}
		}
		switch (prop) {
		case 0: //byType
		{

			srand(time(NULL));
			const int temp = (FigCount > 1) ? rand() % (FigCount - 1) : 0;
			return FigList[temp]->getFigType();
			break;

		}
		case 1://byColor
		{
			int temp;
			color availableColors[5];
			int clrCount = 0;

			for (int i = 0; i < FigsWithoutLinesCount; i++)
			{
				bool cont = false;
				if (FigsNoLines[i]->getGfxInfo().isFilled) {
					for (int j = 0; j < clrCount; j++) {
						if (FigsNoLines[i]->getGfxInfo().FillClr == availableColors[j])
							cont = true;
					}
					if (cont) continue;
					availableColors[clrCount] = FigsNoLines[i]->getGfxInfo().FillClr;
					clrCount++;
				}
			}

			if (clrCount > 0) {  //if any of the drawn figures has a fill color
				srand(time(NULL));
				temp = (clrCount > 1) ? rand() % (clrCount - 1) : 0;
				color rndmClr = availableColors[temp];
				if (rndmClr == BLACK) return 1;
				if (rndmClr == WHITE) return 2;
				if (rndmClr == RED) return 3;
				if (rndmClr == GREEN) return 4;
				if (rndmClr == BLUE) return 5;
			}

			return 0; //default value if no figure is filled with a color --- the user will get an error message
			break;
		}
		default:
			return -2; //its impossible to reach this default value :D
			break;

		}

	}
	else {
		return -1; //defalut value if the user has no figures drawn --> this will return an error to the user and send him back to the draw mode
	}


}
int ApplicationManager::figsOfSameType(int figProp, int value) {
	switch (figProp) {
	case 0: //by Type
	{
		int c = 0;
		for (int i = 0; i < FigCount; i++) {
			if (FigList[i]->getFigType() == value) c++;
		}
		return c;
		break;

	}
	case 1: //by Color
	{
		int FigsWithoutLinesCount = 0; //no. of figures without lines (lines has no fill color)
		CFigure* FigsNoLines[200];  //array of figures without lines (lines has no fill color)

		for (int i = 0; i < FigCount; i++)
		{
			if (dynamic_cast<CLine*>(FigList[i]) == NULL) {
				FigsNoLines[FigsWithoutLinesCount] = FigList[i];
				FigsWithoutLinesCount++;
			}
		}
		color test;
		switch (value) {
		case 1:
			test = BLACK;
			break;
		case 2:
			test = WHITE;
			break;
		case 3:
			test = RED;
			break;
		case 4:
			test = GREEN;
			break;
		case 5:
			test = BLUE;
			break;

		}
		int c = 0;
		for (int i = 0; i < FigsWithoutLinesCount; i++) {
			if (FigsNoLines[i]->getGfxInfo().FillClr == test) c++;
		}
		return c;
		break;

	}
	default:
		return -1; //default value for errors
		break;


	}
}
void ApplicationManager::restoreHiddenFigs() const {
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->setIsHidden(false);
	}
}
void  ApplicationManager::setSound(bool x) {

	soundIsEnabled = x;
}
bool ApplicationManager::getSound() {
	return soundIsEnabled;
}

void ApplicationManager::setExiting()
{
	exiting = true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL) {
			delete FigList[i];
			FigList[i] = NULL;
		}
	}
	if (pIn == NULL)
	{
		
	}
	else { delete pIn;
	pIn = NULL;
	}
	if (pOut == NULL)
	{
		
	}
	else { delete pOut;
	pOut = NULL;
	}

}

CFigure *ApplicationManager::AccessClipboard()
{
	return Clipboard;
}

void ApplicationManager::setClipboard(CFigure* fig_ptr)
{
	this->Clipboard = fig_ptr;
}

bool ApplicationManager::getIsCut()
{
	return isCut;
}

void ApplicationManager::setIsCut(bool c)
{
	isCut = c;
}

void ApplicationManager::setCutFig(CFigure* ptrtocut)
{
	cutfig = ptrtocut;
}
void ApplicationManager::ClearClipboard()
{
	if (Clipboard != NULL) { delete Clipboard; }
	Clipboard = NULL;
}

CFigure* ApplicationManager::getCutFig()
{
	return cutfig;
}
