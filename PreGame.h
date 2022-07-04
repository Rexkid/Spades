#pragma once

/************************
	Andre Vernon
	Spades Program
	PreGame HEADER FILE
************************/

#ifndef _PREGAME_H
#define _PREGAME_H

#include ".\Deck.h"
#include ".\Human.h"
#include ".\cpu.h"
#include ".\Game.h"
#include <iostream>
#include "string.h"
#include <sstream>
using namespace std;



class PreGame
{
public:
				 
	PreGame();		//CONSTRUCTOR
	~PreGame();		//DECONSTRUCTOR

	int getPointsToPlayUpTo();			//RETURNS THE GAME POINT LIMIT

protected:
	
	/***********************************FUNCTIONS WITHIN THE DRIVER************************************************/
	void runPreGame();					//ASKS IF INSTRUCTIONS ARE DESIRED TO BE READ AND SETS GAME POINT LIMIT

	/***********************************SETTERS********************************************************************/
	void setThePointsToPlayUpTo();		//TAKES IN A STRING AND MAKES SURE IT'S A VALID NUMBER

	/***********************************GETTERS********************************************************************/
	string getInstructions(string read);//GIVES THE USER THE INSTRUCTIONS OF SPADES CREATED BY REXKID	
	string getOutsideInstructions(string read);//GIVES THE USER THE INSTRUCTIONS OF SPADES CREATED BY REXKID	

private:
	int p_numberOfTimesReadInstructions;//COUNTER FOR AMOUNT OF TIMES INSTRUCTIONS ARE READ
	int p_PlayUpTo;						//HOLDS THE VALUE FOR THE DESIRED WINNING SCORE 
	
};
#endif