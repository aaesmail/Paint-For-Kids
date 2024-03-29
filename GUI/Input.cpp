#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetCurrentCoor(int &x, int &y) {
	pWind->GetMouseCoord(x, y);
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetString(Output *pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_LINE: return DRAW_LINE;
			case ITM_TRIANGLE: return DRAW_TRI;
			case ITM_RHOMBUS: return DRAW_RHOMBUS;
			case ITM_ELLIPSE: return DRAW_ELLIPSE;
			case ITM_PLAYMODE: return TO_PLAY;
			case ITM_SELECTFIG: return SELECT_FIGURE;
			case ITM_CHANGEDRAWCOL: return CHNG_DRAW_CLR;
			case ITM_CHANGEFILLCOL: return CHNG_FILL_CLR;
			case ITM_DELETEFIG: return DEL;
			case ITM_COPYFIG: return CPY_FIG;
			case ITM_CUTFIG: return CUT_FIG;
			case ITM_PASTEFIG: return PASTE_FIG;
			case ITM_SAVEGRAPH: return SAVE;
			case ITM_SAVEBYTYPE: return SAVE_BY_TYPE;
			case ITM_LOADGRAPH: return LOAD;
			case ITM_VOICE: return VOICE;
			case ITM_RESIZE: return RESIZE;
			case ITM_SNDFRNT: return SNDFRNT;
			case ITM_SNDBK: return SNDBK;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//--------------------------------------------------------------------
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_PICKPROP: return PICKPROP;
			case ITM_PICKCLR: return PICKCLR;
			case ITM_SWITCHDRAW: return TO_DRAW;
			case ITM_EXIT2: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		//--------------------------------------------------------------------
		return STATUS;	//just for now. This should be updated
	}
	else                 // COLOR MODE
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		//--------------------------------------------------------------------
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_BLACK: return TO_BLACK;
			case ITM_WHITE: return TO_WHITE;
			case ITM_RED: return TO_RED;
			case ITM_GREEN: return TO_GREEN;
			case ITM_BLUE: return TO_BLUE;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		//--------------------------------------------------------------------
		return STATUS;	//just for now. This should be updated
	}

}
/////////////////////////////////

Input::~Input()
{
}
