#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	FigureType FigType;
	/// Add more parameters if needed.
	/////////////////////////////////////////////////////////////////////////////////////////// //MohamedAdel
	bool hidden;
	///////////////////////////////////////////////////////////////////////////////////////////
public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void setID(int id) = 0;


	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	virtual CFigure* insideme(int x, int y) = 0;

	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	FigureType getType() const;
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

	/////////////////////////////////////////////////////////////////////////////////////////// //MohamedAdel
	bool getIsHidden()const;
	void setIsHidden(bool x);
	virtual int getFigType()const = 0;
	GfxInfo getGfxInfo() const;
	int getFigColor() const;
	///////////////////////////////////////////////////////////////////////////////////////////
	GfxInfo GetFigGfxInfo();
	virtual void GetFigPoints(Point &P1);
	virtual void GetFigPoints(Point &P1, Point &P2);
	virtual void GetFigPoints(Point &P1, Point &P2, Point &P3);
	void  ChngFillClrCut(color c);
	void SetIsFilled(bool f);
	bool GetIsFilled();
};

#endif