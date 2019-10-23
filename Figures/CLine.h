#pragma once

#include "CFigure.h"

class CLine: public CFigure
{
private:
	Point point1;
	Point point2;

public:
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual void setID(int id);
	virtual void PrintInfo(Output* pOut);
	virtual CFigure* insideme(int x, int y);
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
	//////////////////////////////////////////////////////////////////////////////////////// MohamedAdel

	virtual int getFigType()const;
	//////////////////////////////////////////////////////////////////////////////////////// 
	virtual void GetFigPoints(Point &P1, Point &P2);
	~CLine();
};

