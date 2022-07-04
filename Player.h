#pragma once

/************************
	Andre Vernon
	Spades Program
	PLAYER HEADER FILE
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

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include "Deck.h"
using namespace std;

class Player
{
public:
	Player();									//CREATES A PLAYER AND PUTS THEM IN A RANDOM SEAT NOT FILLED
	Player(int seat);							//CREATES A PLAYER AND PUTS THEM IN A SEAT
	~Player();									//DECONSTRUCTOR

	void setHand(Card* myCard, int CardNum);	//ALL PLAYERS WILL RECEIVE A RANDOM AMOUNT OF 13 CARDS
	void setSeat(int seat);						//SETS A PLAYER IN A SEAT
	void setWinnerOfHand(bool winnerOfHand);	//CHANGES IF WINNER OR NOT
	void setBlind(bool ableToBidBlind);			//SETS IF A TEAM IS ABLE TO BID BLIND TO DOUBLE POINTS IF SET AMOUNT OF BOOKS
	
	bool getWinnerOfCard();						//RETURNS TRUE OR FALSE IF PLAYER IS WINNER OF HAND
	bool getBlind();							//RETURNS IF TEAM IS BIDDING BLIND

	int getSeat();								//RETRIEVES THE SEAT OF A PLAYER
	vector<Card*> getHand();					//RETURNS A PLAYERS HAND OF CARDS

//------------------------------------------VIRTUALS--------------------------------------------------------------//
	//ALL VOID VIRTUAL FUNCTIONS
	virtual void setBid() = 0;										//COLLECTS THE BIDS FROM A PLAYER
	virtual void setBidToZero() = 0;								//SETS THE BID COUNT BACK TO ZERO
	virtual void setCollectTrick(vector<Card*>& cardsWon) = 0;		//DOUBLE VECTOR, HOLDS THE HANDS THAT WERE WON
	virtual void setTrickCountToZero() = 0;							//SETS THE WON TRICK COUNT BACK TO ZERO 
	virtual void setPlayACard() = 0;								//GIVES THE NUMBER OF A CARD IN THE GROUP
	virtual void setPlayACard(Card* c) = 0;							//GIVES THE NUMBER OF A CARD IN THE GROUP
	virtual void print() = 0;										//PRINTS OFF THE CARDS OF A PLAYER 
	
	//ALL RETURNING A VALUE VIRTUAL FUNCTIONS
	virtual int getBid() = 0;										//RETRIEVES THE BID OF A PLAYER 

	virtual Card* getPlayACard() = 0;								//RETRIEVES THE CARD DESIRED TO PLAY

	virtual vector< vector<Card*> *> getCollectTrick() = 0;			//RETRIEVES THE 4 OF CARDS IN WON HANDS	

private:
	int p_Seat;							//THE SEAT OF A PLAYER
	bool p_winnerOfHand;				//HOLDS WHETHER OR NOT THE PLAYER JUST WON THAT HAND
	bool p_ableToBidBlind;				//IS SET WHEN A TEAM IS LOSING BY LESS THAN A HUNDRED
	vector<Card*> p_hand;				//THE CARDS OF A PLAYER
};
#endif	