#include "stdafx.h"
#include ".\player.h"

/************************
	Andre Vernon
	Spades Program
	PLAYER HEADER FILE
************************/

/*
class Player
{
public:
	Player();									
	Player(int seat);
	~Player();

	void setHand(Card* myCard, int CardNum);	
	void setSeat(int seat);						
	void setWinnerOfHand(bool winnerOfHand);	
	
	bool getWinnerOfCard();						
	int getSeat();								//RETRIEVES THE SEAT OF A PLAYER
	vector<Card*> getHand();					//RETURNS A PLAYERS HAND OF CARDS

//------------------------------------------VIRTUALS--------------------------------------------------------------//
	//ALL VOID VIRTUAL FUNCTIONS
	virtual void setBid() = 0;										//COLLECTS THE BIDS FROM A PLAYER
	virtual void setCollectTrick(vector<Card*>& cardsWon) = 0;		//DOUBLE VECTOR, HOLDS THE HANDS THAT WERE WON 
	virtual void setPlayACard() = 0;								//GIVES THE NUMBER OF A CARD IN THE GROUP
	virtual void print() = 0;										//PRINTS OFF THE CARDS OF A PLAYER
	
	//ALL RETURNING A VALUE VIRTUAL FUNCTIONS
	virtual int getBid() = 0;										//RETRIEVES THE BID OF A PLAYER 
	virtual Card* getPlayACard() = 0;								//RETRIEVES THE CARD DESIRED TO PLAY
	virtual vector<Card*>& getCollectTrick(int trickNum) = 0;		//RETRIEVES THE 4 OF CARDS IN WON HANDS	

private:
	int p_Seat;							//THE SEAT OF A PLAYER
	bool p_winnerOfHand;				//HOLDS WHETHER OR NOT THE PLAYER JUST WON THAT HAND
	vector<Card*> p_hand;				//THE CARDS OF A PLAYER
*/




/**************************************CONSTRUCTORS/DECONSTRUCTORS***************************************/
/************************************************************************************/
/*****************************
NAME: Player
FUNCTION:  CREATES A PLAYER AND PUTS THEM IN A RANDOM SEAT NOT FILLED
TYPE: CONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Player::Player()
:p_Seat(0),
p_hand(13),
p_winnerOfHand(false),
p_ableToBidBlind(false)
{}
/************************************************************************************/
/*****************************
NAME: Player
FUNCTION:  CREATES A PLAYER AND PUTS THEM IN A SEAT
TYPE: CONSTRUCTOR
ARGUEMENTS: seat	-HOLDS PLAYER'S SEAT NUMBER
RETURNS: NONE
******************************/
Player::Player(int seat)
:p_Seat(seat),
p_hand(13),
p_winnerOfHand(false),
p_ableToBidBlind(false)
{}
/************************************************************************************/
/*****************************
NAME: ~PLAYER
FUNCTION:  DECONSTRUCTOR
TYPE: DECONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Player::~Player()
{}
/************************************************SETTERS************************************************/
/************************************************************************************/
/*****************************
NAME: setHand
FUNCTION:	THIS SETS THE HAND OF A PLAYER BY POINTING TO A CARD
			ALL PLAYERS WILL RECEIVE A RANDOM AMOUNT OF 13 CARDS
TYPE: VOID
ARGUEMENTS: myCard	-PASSES THE POINTER OF THE CARD 
			CardNum -PASSES NUMBER OF CARDS IN PLAYER HAND
RETURNS: NONE
******************************/
void Player::setHand(Card* myCard, int CardNum)
{
	p_hand[CardNum] = myCard;
}
/************************************************************************************/
/*****************************
NAME: setSeat
FUNCTION:  SETS A PLAYER IN A SEAT
TYPE: VOID
ARGUEMENTS: seat	-HOLDS A SEAT POSITION
RETURNS: NONE
******************************/
void Player::setSeat(int seat)
{
	p_Seat = seat;
}
/************************************************************************************/
/*****************************
NAME: setWinnerOfHand
FUNCTION:  SETS PLAYER TO WINNER OR NOT
TYPE: VOID
ARGUEMENTS: winnerOfHand	-PASSED TRUE WHEN PLAYER WINS
RETURNS: NONE
******************************/
void Player::setWinnerOfHand(bool winnerOfHand)
{
	p_winnerOfHand = winnerOfHand;
}
/************************************************************************************/
/*****************************
NAME: setBlind
FUNCTION:  SETS IF TEAM CAN BID BLIND
TYPE: VOID
ARGUEMENTS: ableToBidBlind	-CHECKS SCORE TO SEE IF TEAM A PLAYER IS ABLE TO BID BLIND
RETURNS: NONE
******************************/
void Player::setBlind(bool ableToBidBlind)
{
	p_ableToBidBlind = ableToBidBlind;
}
/************************************************GETTERS************************************************/
/************************************************************************************/
/*****************************
NAME: getHand()
FUNCTION:  RETRIEVES A POINTER TO THE PLAYERS CARDS
TYPE: VECTOR<CARD*>
ARGUEMENTS: NONE
RETURNS: p_hand	-RETURNS PLAYERS HAND OF CARDS 
******************************/
vector<Card*> Player::getHand()
{
	return p_hand;
}
/************************************************************************************/
/*****************************
NAME: getSeat
FUNCTION: RETRIEVES PLAYER’S SEAT
TYPE: INT
ARGUEMENTS: NONE
RETURNS: p_Seat	-RETRIEVES PLAYER’S SEAT
******************************/
int Player::getSeat()
{
	return p_Seat;
}
/************************************************************************************/
/*****************************
NAME: getWinnerOfCard
FUNCTION:  RETURNS TRUE IF PLAYER IS WINNER OF PLAYED SET
TYPE: BOOL
ARGUEMENTS: NONE
RETURNS: p_winnerOfHand	-ONLY TRUE IF PLAYER JUST WON SET
******************************/
bool Player::getWinnerOfCard()
{
	return p_winnerOfHand;
}
/************************************************************************************/
/*****************************
NAME: getBlind
FUNCTION:  TRUE IF TEAM IS ABLE TO BID BLIND
TYPE: BOOL
ARGUEMENTS: NONE
RETURNS: p_ableToBidBlind	-TRUE IF TEAM IS LOSING BY MORE THAN 100 POINTS
******************************/
bool Player::getBlind()
{
	return p_ableToBidBlind;
}