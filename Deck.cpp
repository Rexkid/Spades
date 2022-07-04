#include "stdafx.h"
#include "Deck.h"

/************************
	Andre Vernon
	Spades Program
	DECK SOURCE FILE
*************************

************************************************************
public:
	Deck();		//CONSTRUCTOR THAT SETS AND CREATES 52 CARDS
	Deck(int numOfCards);
	~Deck();
	bool Shuffle( vector<Card*> &deckOfCards);
	void SetSuperiorSuit();	
	int GetSuperiorSuit();
	Card * getCard();
	vector<Card*>& getCards();


private:
	vector<Card*> deckOfCards;
	
	int p_cardPointer;	
	int p_superiorSuit;
	int p_numOfCards;
	
	bool p_deckShuffled;
	
	Card * c;
************************************************************
*/
/************************************************************************************/
/*****************************
NAME: Deck
FUNCTION:  CONSTRUCTOR CREATES 52 CARDS
TYPE: CONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Deck::Deck()
: deckOfCards(52),
  p_numOfCards(52),
  p_cardPointer(0)
{
	for(int suitsOfcards = Card::Diamonds; suitsOfcards <= Card::Spades; suitsOfcards++)
	{
		for(int cardsOfOneSuit = 1; cardsOfOneSuit < ((p_numOfCards/4)+1); cardsOfOneSuit++)	// THIS MAY ALSO WORK, HARD CODING IN THE NUMBER OF CARDS: for(int cardsOfOneSuit = 1; cardsOfOneSuit < (13); cardsOfOneSuit++)
		{
			c = new Card(Card::Suit(suitsOfcards), cardsOfOneSuit);			
			deckOfCards[p_cardPointer] = c;
			p_cardPointer++;
		}		
		
	}
	/*  CAN BE USED TO TEST IF ALL CARDS ARE PROPERLY LOADED
	for(int i = 0; i < p_cardPointer;i++)
	{
		cout << "Properly loaded: ";
		deckOfCards[i]->print();
	}
	*/
	srand(time(0));
	p_deckShuffled = false;
}
/************************************************************************************/
/*****************************
NAME: Deck
FUNCTION:  CREATES DESIRED NUMBER OF CARDS
TYPE: DECK CONTRUCTOR
ARGUEMENTS: numOfCards - HOLDS THE NUMBER OF CARDS TO CREATE
RETURNS: NONE
******************************/
Deck::Deck(int numOfCards)
: deckOfCards(numOfCards),
  p_numOfCards(numOfCards),
  p_cardPointer(0)
{
	for(int suitsOfcards = Card::Diamonds; suitsOfcards <= Card::Spades; suitsOfcards++)
	{
		for(int cardsOfOneSuit = 1; cardsOfOneSuit < ((p_numOfCards/4)+1); cardsOfOneSuit++)
		{
			c = new Card(Card::Suit(suitsOfcards), cardsOfOneSuit);			
			deckOfCards[p_cardPointer] = c;
			p_cardPointer++;
		}		
		
	}
	
	/*  CAN BE USED TO TEST IF ALL CARDS ARE PROPERLY LOADED
	for(int i = 0; i < p_cardPointer;i++)
	{
		cout << "Properly loaded: ";
		deckOfCards[i]->print();
	}
	*/
	srand(time(0));
	p_deckShuffled = false;
}
/************************************************************************************/
/*****************************
NAME: ~Deck
FUNCTION:  DECONSTRUCTOR
TYPE: Deck DECONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Deck::~Deck()
{}
/************************************************************************************/
/*****************************
NAME: Shuffle
FUNCTION:  MIXES/SHUFFLES CARDS 
TYPE: BOOL
ARGUEMENTS: deckOfCards - HOLDS A VECTOR OF CARD POINTERS
RETURNS: p_deckShuffle - RETURNS TRUE AFTER CARDS ARE MIXED
******************************/
bool Deck::Shuffle(vector<Card*>& deckOfCards)
{
	p_deckShuffled = false;
	int k;

	if(p_deckShuffled == false)
	{
		for(k=0; k < p_numOfCards-1; k++)
		{
			int swapIndex = rand()%52;						//CHOOSES A REMAINDER FROM 0-51 AND STORES IT IN swampIndex
			Card* temp = deckOfCards[swapIndex];			//STORES A TEMPORARY CARD TO A RANDOM CARD FROM THE DECK
			deckOfCards[swapIndex] = deckOfCards[k];		//HAS THE RANDOM POSITION EQUAL THE CURRENT POSITION
			deckOfCards[k] = temp;							//HAS THE CURRENT POSITION EQUAL TEMPORARY CARD THAT WAS POINTING AT THE RANDOM CARD
		}
		p_deckShuffled = true;								//STORES THAT THE DECK HAS JUST BEEN SHUFFLED
	}
	for(k=0; k < p_numOfCards; k++)
	{
		deckOfCards[k]->setbeenPlayed(false);				//HAS THE CURRENT POSITION EQUAL TEMPORARY CARD THAT WAS POINTING AT THE RANDOM CARD
	}
	return p_deckShuffled;
}
/************************************************************************************/
/*****************************
NAME: getCards
FUNCTION:  TO RETRIEVE THE 52 CARDS
TYPE: VECTOR OF CARD POINTERS
ARGUEMENTS: NONE
RETURNS: deckOfCards - HOLDS AN ADDRESS TO A DECK OF CARDS
******************************/
vector<Card*>& Deck::getCards()
{
	return deckOfCards;
}
/************************************************************************************/
/*****************************
NAME: getCard
FUNCTION:  POINTS TO A SPECIFIC CARD TO SET IF IT'S BEEN PLAYED OR NOT
TYPE: CARD POINTER
ARGUEMENTS: NONE
RETURNS: c - POINTS TO A SPECIFIC CARD
******************************/
Card * Deck::getCard()
{
	return c;
}