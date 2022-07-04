/************************
	Andre Vernon
	Spades Program
	Card HEADER FILE
************************/
#pragma once
#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
#include <vector>
#include "stdafx.h"
using namespace std;
class Card
{
public:

	Card(void);										//CARD CONSTRUCTOR
	~Card(void);									//CARD DECONSTRUCTOR
	
	enum Suit {	Diamonds, Hearts, Clubs, Spades};	//DECLARES THE DIFFERENT NAMES OF A SUIT										
	Card(int suitOfcard, int cardValue);			//TAKES IN THE RANK AND SUIT OF THE CARD											
	
	int getCardNumValue();							//RETRIEVES THE NUMERIC VALUE OF THE CARD
	
	string getSuitOfCard();							//RETRIEVES THE SUIT OF A CARD
	string getValueOfCard();						//RETRIEVES THE VALUE OF A CARD	
	
	void setbeenPlayed(bool beenPlayed);			//DETERMINES WEATHER OR NOT THE CARD HAS BEEN PLAYED OR NOT
	void print();									//OUTPUTS SUIT AND CARD VALUE
	bool getBeenPlayed();							//RETRIEVES THE VALUE OF THE BOOL BEEN PLAYED
	
	

private:
	
	void setSuitOfCard(int cardSuit);	//FOR LOOP AND SETS THE SUIT OF THE CARD
	void setValueOfCard();				//SETS THE VALUE OF EACH CARD AND RETRIEVES THE VALUE OF A CARD
	void setCardNumValue(int cardValue);

	//PRIVATE SUITS
	int p_cardSuit;						//HOLDS THE VALUE OF THE SUITS
	int p_cardNumValue;
	
	//PRIVATE STRINGS
	string p_suitOfCard;				//HOLDS A STRING OF THE BEGINNING LETTER OF A SUIT
	string p_cardValue;					//HOLDS A Card VALUE	
	
	//PRIVATE BOOLS
	bool p_BeenPlayed;					//VERIFIER IF CARD HAS BEEN PLAYED 
};
#endif