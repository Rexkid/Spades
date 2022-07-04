#pragma once

/************************
	Andre Vernon
	Spades Program
	CPU HEADER FILE
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

#ifndef _CPU_H
#define _CPU_H

#include "Player.h"
#include <iostream>
using namespace std;


class CPU: public Player
{
public:	
	CPU();														//CONSTRUCTOR
	CPU(int seat);												//CONSTRUCTOR THAT SETS A PLAYERS SEAT POSITION
	~CPU();														//DECONSTRUCTOR
	
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
	int p_BidNum;												//THE BID GIVEN BY A PLAYER
	int p_TricksWon;											//USED TO KEEP COUNT OF THE NUMBER OF TRICKS WON
	
	Card* p_Card2play;											//THE CARD TO BE OR PLAYED BY A PLAYER
	vector<vector<Card*>*> p_CardsWon;							//THE TRICKS WON BY THE PLAYER

	Deck p_PlayerMemoryDeck;									//DECK OF CARDS USED TO KEEP TRACK OF WHAT CARDS HAVE BEEN PLAYED
};
#endif