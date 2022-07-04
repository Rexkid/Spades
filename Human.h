#pragma once
/************************
	Andre Vernon
	Spades Program
	HUMAN HEADER FILE

************************/
/* 
	-All players will have a hand of 13 cards (meaning a vector of cards)
	-All players must play a card
	-All players must bid
	-A check of no face cards and no spades  
	(bool playableHand) 
		[if( suit == 4 or card > 10 or card == 11) playable = true;
	-All players have a turn
	(bool myTurn)
		[if(firstHand == true) user is first  
		 else if( the player that won that hand 
*/

#ifndef _HUMAN_H
#define _HUMAN_H

#include "Player.h"
#include <iostream>
#include <sstream>
#include "string.h"
using namespace std;

class Human : public Player
{
public:
	
	Human();
	Human(int seat);
	~Human();
	
	//------------------------------------------VIRTUALS--------------------------------------------------------------//
	//ALL VOID VIRTUAL FUNCTIONS
	void setBid();										//COLLECTS THE BIDS FROM A PLAYER	
	void setBidToZero();								//SETS THE BID COUNT BACK TO ZERO
	void setCollectTrick(vector<Card*>& cardsWon);		//DOUBLE VECTOR, HOLDS THE HANDS THAT WERE WON 
	void setTrickCountToZero();							//SETS THE WON TRICK COUNT BACK TO ZERO
	void setPlayACard();								//GIVES THE NUMBER OF A CARD IN THE GROUP
	void setPlayACard(Card* c);							//GIVES THE NUMBER OF A CARD IN THE GROUP
	void print();										//PRINTS OFF THE CARDS OF A PLAYER
	
	//ALL RETURNING A VALUE VIRTUAL FUNCTIONS
	int getBid();										//RETRIEVES THE BID OF A PLAYER 
	Card* getPlayACard();								//RETRIEVES THE CARD DESIRED TO PLAY
	vector< vector<Card*> *> getCollectTrick();			//RETRIEVES THE 4 OF CARDS IN WON HANDS	

private:
	int p_BidNum;						//THE BID GIVEN BY A PLAYER
	Card* p_Card2play;					//THE CARD TO BE OR PLAYED BY A PLAYER
	vector<vector<Card*>*> p_CardsWon;	//THE TRICKS WON BY THE PLAYER
	int p_TricksWon;					//USED TO KEEP COUNT OF THE NUMBER OF TRICKS WON
	Deck* p_d;							//POINTER TO THE DECK CLASS
};
#endif