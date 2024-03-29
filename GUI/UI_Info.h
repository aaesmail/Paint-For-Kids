#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_CLR	//COLOR MODE
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	
	//TODO: Add more items names here
	//----------------------------------------------------------------------
	ITM_LINE,
	ITM_TRIANGLE,
	ITM_RHOMBUS,
	ITM_ELLIPSE,
	ITM_PLAYMODE,
	ITM_SELECTFIG,
	ITM_CHANGEDRAWCOL,
	ITM_CHANGEFILLCOL,
	ITM_DELETEFIG,
	ITM_COPYFIG,
	ITM_CUTFIG,
	ITM_PASTEFIG,
	ITM_SAVEGRAPH,
	ITM_SAVEBYTYPE,
	ITM_LOADGRAPH,
	//----------------------------------------------------------------------
	ITM_VOICE,
	ITM_RESIZE,
	ITM_SNDFRNT,
	ITM_SNDBK,
	//----------------------------------------------------------------------

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum COLORMENUITEMS //The items of the Color menu (you should add more items)
{
	ITM_BLACK,
	ITM_WHITE,
	ITM_RED,
	ITM_GREEN,
	ITM_BLUE,


	CLR_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	//--------------------------------------------------------------------------------------
	ITM_PICKPROP,
	ITM_PICKCLR,
	ITM_SWITCHDRAW,
	ITM_EXIT2,
	//--------------------------------------------------------------------------------------

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif