#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	/////////////////////////////////////////////////////////////////////////////////////////// //MohamedAdel
	hidden = false;
	///////////////////////////////////////////////////////////////////////////////////////////
}
FigureType CFigure::getType() const
{
	return FigType;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////// MohamedAdel
bool CFigure::getIsHidden() const { return hidden; }
void CFigure::setIsHidden(bool x) { hidden = x; }
GfxInfo CFigure::getGfxInfo() const { return FigGfxInfo; }
int CFigure::getFigColor() const {
	if (FigGfxInfo.isFilled) {
		if (FigGfxInfo.FillClr == BLACK) return 1;
		if (FigGfxInfo.FillClr == WHITE) return 2;
		if (FigGfxInfo.FillClr == RED) return 3;
		if (FigGfxInfo.FillClr == GREEN) return 4;
		if (FigGfxInfo.FillClr == BLUE) return 5;

	}

}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void CFigure::ChngFillClrCut(color c)
{
	FigGfxInfo.FillClr = c;
}




GfxInfo CFigure::GetFigGfxInfo()
{
	return FigGfxInfo;
}


void CFigure::SetIsFilled(bool f)
{
	FigGfxInfo.isFilled = f;
}
bool CFigure::GetIsFilled()
{
	return FigGfxInfo.isFilled;
}

void CFigure::GetFigPoints(Point &P1)
{
}
void CFigure::GetFigPoints(Point &P1, Point &P2)
{
}
void CFigure::GetFigPoints(Point &P1, Point &P2, Point &P3)
{
}