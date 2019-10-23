#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "Figures/CEllipse.h"
#include "Figures/CLine.h"
#include "Figures/CRectangle.h"
#include "Figures/CRhombus.h"
#include "Figures/CTriangle.h"
#include "GUI\input.h"
#include "GUI\output.h"

//////////////////////////////////////////////////////////////MohamedAdel
//to play sound
#include <windows.h>
#include <mmsystem.h>
//////////////////////////////////////////////////////////////

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure
	CFigure* cutfig;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	// tracking filling of figures.
	bool isfilled;
	bool isCut;
	int ID;


	bool exiting;

	//////////////////////////////////////////////////////////////////////////////////////// MohamedAdel
	GUI_MODE Mode;
	bool soundIsEnabled;
	////////////////////////////////////////////////////////////////////////////////////////

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void setSelected(CFigure* try_to_select, bool ifselected);
	CFigure* getSelected();
	int getfigcount();
	int findFigure(CFigure* figure);
	void decFigCount(int index);
	int getID();
	void incID();

	void sendtofront(int location);
	void sendtoback(int location);

	void WriteFigures(ofstream&);
	void WriteFigures(ofstream&, FigureType);
	void unselect();
	void setFill(bool s);
	bool getFill();
	CFigure * AccessClipboard();
	void setClipboard(CFigure*);
	bool getIsCut();
	void setIsCut(bool);
	void setCutFig(CFigure*);
	CFigure* getCutFig();
	void ClearClipboard();
	
	//////////////////////////////////////////////////////////////////////////////////////////////////////  MohamedAdel

	//assuming :: black = 1, white = 2, red = 3, green = 4, blue = 5
	//assuming :: rect = 1, line = 2, tri = 3, rhom = 4, ellipse = 5
	int getRndFigure(int prop); // prop = 0 --> byType /  prop = 1--> byColor
	int figsOfSameType(int figProp, int value);
	void restoreHiddenFigs() const;
	void setSound(bool x);
	bool getSound();
	//////////////////////////////////////////////////////////////////////////////////////////////////////


	void setExiting();


	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif