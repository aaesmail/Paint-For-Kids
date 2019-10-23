#pragma once
#include "Action.h"
class Sound: public Action
{


public:
	Sound(ApplicationManager *);

	void soundDisable();
	void soundEnable();
	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();
	~Sound(void);
};

