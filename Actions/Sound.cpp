#include "Sound.h"
#include "..\ApplicationManager.h"

Sound::Sound(ApplicationManager *pApp):Action(pApp)
{
	
}
void Sound::soundDisable(){
	pManager->setSound(false);
}
void Sound::soundEnable(){
	pManager->setSound(true);

}
//Reads parameters required for action to execute (code depends on action type)
void Sound::ReadActionParameters(){

}
	
//Execute action (code depends on action type)
void Sound::Execute(){
	if(pManager->getSound()){
		soundDisable();
	}else{
		soundEnable();
	}
}
Sound::~Sound(void)
{
}
