#include "DEFS.h"
#include "ApplicationManager.h"

// Additional Functions:
string StoreType(FigureType T)
{
	switch (T)
	{
	case RECTANGLE:
		return "RECTANGLE";
		break;
	case TRIANGLE:
		return "TRIANGLE";
		break;
	case ELLIPSE:
		return "ELLIPSE";
		break;
	case RHOMBUS:
		return "RHOMBUS";
		break;
	case LINE:
		return "LINE";
		break;
	}
	return "";
}

FigureType ReadType(string Str)
{
	switch (Str[1])
	{
	case 'E':
		return RECTANGLE;
		break;
	case 'R':
		return TRIANGLE;
		break;
	case 'L':
		return ELLIPSE;
		break;
	case 'H':
		return RHOMBUS;
		break;
	case 'I':
		return LINE;
		break;
	}
	return EMPTY_TYPE;
}

string ColorData(color C)
{
	string Data;
	Data += to_string(int(C.ucRed)) + " " + to_string(int(C.ucGreen)) + " " + to_string(int(C.ucBlue));
	return Data;
}

color ReadColor(ifstream& in)
{
	int Red, Green, Blue;
	in >> Red >> Green >> Blue;
	return color(Red, Green, Blue);
}

