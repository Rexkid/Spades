/************************
	Andre Vernon
	Spades Program
	Driver
	04-06-11
************************/

#include "stdafx.h"
#include ".\Game.h"
#include ".\PreGame.h"
using namespace std;

/*********FUNCTIONS RAN IN THE DRIVER********************

PreGame::PreGame getPointsToPlayUpTo();			ASKS USER TO INPUT THE SCORE TO WIN THE GAME
Game::Game MainProgram();						RUNS THE GAME

********************************************************/

/*****************************************************
NAME: main
FUNCTION: STARTS THE PREGAME AND RUNS THE SPADES GAME
TYPE: VOID
ARGUEMENTS: N/A
RETURNS: N/A
*****************************************************/
void main()
{	
	PreGame p;							//OPENS THE PREGAME OPTIONS
	Game g(p.getPointsToPlayUpTo());	//ALLOWS THE USER TO PLAY TO THE SCORE THEY DESIRE
	
	//Game g(100);						//ALLOWS THE USER TO PLAY A QUICK GAME TO 100 POINTS
	g.MainProgram();
}
