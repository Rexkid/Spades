
/************************
	Andre Vernon
	Spades Program
	DECK HEADER FILE
************************/

#ifndef DECK_H
#define DECK_H

#pragma once
#include ".\Card.h"
#include <iostream>
#include <vector>
#include <ctime>	   //IS USED TO RANDOMLY MIX UP THE CARDS
using namespace std;

class Deck
{
public:
	Deck();										//CONSTRUCTOR THAT SETS AND CREATES 52 CARDS
	Deck(int numOfCards);						//CONSTRUCTOR THAT SETS AND CREATES DESIRED NUMBER OF CARDS
	~Deck();									//DECONSTRUCTOR
	bool Shuffle( vector<Card*> &deckOfCards);	//DOUBLE ARRAY TO MIX THE CARDS
	
	Card * getCard();							//RETRIEVES A SPECIFIC CARD IN THE DECK
	vector<Card*>& getCards();					//RETRIEVES THE ADDRESS OF A CARD OUT OF A CARD POINTER VECTOR


private:
	vector<Card*> deckOfCards;					//HOLDS A VECTOR OF CARD POINTERS
	
	int p_cardPointer;							//HOLDS AN INTEGER

	int p_numOfCards;							//HOLDS THE VALUE FOR THE NUMBER OF CARDS CREATED
	
	bool p_deckShuffled;						//IS SET TO SAY IF THE DECK OF CARDS HAS BEEN SHUFFLED
	
	Card * c;									//HOLDS A POINTER TO A CARD

};
#endif