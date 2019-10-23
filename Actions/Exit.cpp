#include "Exit.h"
#include "../ApplicationManager.h"


Exit::Exit(ApplicationManager *pApp):Action(pApp)
{

}
void Exit::ReadActionParameters() 
{

}
void Exit::Execute()
{
	pManager->~ApplicationManager();
	pManager->setExiting();
}
Exit::~Exit()
{
}
