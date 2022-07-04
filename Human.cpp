#include "stdafx.h"
#include ".\human.h"

/************************
	Andre Vernon
	Spades Program
	HUMAN HEADER FILE
************************/
/* 
	-A check of no face cards and no spades  
	(bool playableHand) 
		[if( suit == 4 or card > 10 or card == 11) playable = true;
	-All players have a turn
	(bool myTurn)
		[if(firstHand == true) user is first  
		 else if( the player that won that hand 

public:
	
	Human();
	Human(int seat);											
	~Human();
	
	//------------------------------------------VIRTUALS--------------------------------------------------------------//
	//ALL VOID VIRTUAL FUNCTIONS
	virtual void setBid();										
	virtual void setCollectTrick(vector<Card*>& cardsWon);		 
	virtual void setPlayACard();								
	Virtual void setPlayACard(Card* c)							
	virtual void print();										
	
	//ALL RETURNING A VALUE VIRTUAL FUNCTIONS
	virtual int getBid();										 
	virtual void getPlayACard();								
	virtual vector<Card*>& getCollectTrick(int trickNum);			

private:
	int p_BidNum;						
	Card* p_Card2play;					
	vector<vector<Card*>*> p_CardsWon;	
	int p_TricksWon;					
*/
/************************************************************************************/
/*****************************
NAME: Human
FUNCTION:  CONSTRUCTOR 
TYPE: HUMAN CONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Human::Human()
: Player(),
  p_TricksWon(0),
  p_BidNum(0)
{}
/************************************************************************************/
/*****************************
NAME: Human
FUNCTION:  CONSTRUCTOR WITH SEAT
TYPE: HUMAN CONSTRUCTOR
ARGUEMENTS: seat -HOLDS PLAYER POSITION AT GAME TABLE
RETURNS: NONE
******************************/
Human::Human(int seat)
: Player(seat),
  p_TricksWon(0),
  p_BidNum(0)
{}
/************************************************************************************/
/*****************************
NAME: ~Human
FUNCTION:  DECONSTRUCTS
TYPE: HUMAN DECONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Human::~Human()
{};
/************************************************************************************/
/*****************************
NAME: setBidToZero
FUNCTION:  SETS BIDS TO ZERO
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Human::setBidToZero()
{
	p_BidNum = 0;					//SETS BID AT DESIRED NUMBER
}
/************************************************************************************/
/*****************************
NAME: setBid
FUNCTION:  SETS BID EQUAL TO A NUMBER
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Human::setBid()
{
	string BidInput = "400";

	cout << "What is your bid (*maximum is 13*): ";
	
	while(true)
	{
		getline(cin, BidInput);
		stringstream mystream(BidInput);

		//cout << "Enter exit"; 
		//cin >> mystream; //2021/05/12 CAUSES AN OPPERATOR ERROR
		if(BidInput == "exit")//mystream == "exit" || mystream == "EXIT")			//IF THE PLAYER TYPES "EXIT" THEN THE PROGRAM WILL CLOSE
		{
			exit(1);
		}
		else if(mystream >> p_BidNum)
		{
			if(p_BidNum < 14)
			{
				break;
			}
			else 
			{
				cout << "Sorry you have input an invalid number for your bid." << endl;
				cout << "Please try again." << endl;
				system("pause");
				system("cls");
			}
		}
		
	}
}
/************************************************************************************/
/*****************************
NAME: setCollectTrick
FUNCTION: COLLECTS CARDS THAT USER HAS WON
TYPE: VOID
ARGUEMENTS: cardWon - HOLDS ADDRESS OF 4 CARD POINTERS
RETURNS: NONE
******************************/
void Human::setCollectTrick(vector<Card*>& cardsWon)
{
	p_CardsWon.push_back(&cardsWon);
	p_TricksWon++;
}
/************************************************************************************/
/*****************************
NAME: setTrickCountToZero
FUNCTION:  CLEARS THE VECTOR OF CARD POINTERS
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Human::setTrickCountToZero()
{
	p_CardsWon.resize(0);
}
/************************************************************************************/
/*****************************
NAME: print
FUNCTION:  DISPLAYS ON SCREEN USER HAS BEEN CREATED
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Human::print()
{
	cout << "I AM HUMAN... BORN TO DESTROY ALL SENTINAL BEINGS IN SPADES." << endl;
}
/************************************************************************************/
/*****************************
NAME: getBid
FUNCTION:  RETRIEVES THE BID OF A PLAYER
TYPE: INT
ARGUEMENTS: NONE
RETURNS: p_BidNum	-RETRIEVES THE BID OF A PLAYER
******************************/
int Human::getBid()
{
	return p_BidNum;
}
/************************************************************************************/
/*****************************
NAME: setPlayACard
FUNCTION:  FUNCTION CALLED WHEN LEADING TO PLAY A CARD
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Human::setPlayACard()					
{
	bool HaveCard = false;
	string suitOfcard = "love";
	string cardValue;	
	cout << "Which card would you lead with to play: ";
	cin >> suitOfcard >> cardValue;
	_strupr_s((char*)suitOfcard.c_str(), suitOfcard.size()+1);	//TAKES THE STRING OF suitOfcard AND MAKES IT UPPERCASE
	
	if(suitOfcard == "EXIT")				//IF THE PLAYER TYPES "EXIT" THEN THE PROGRAM WILL CLOSE
	{
		exit(1);
	}
	if(cardValue == "exit")
	{
		exit(1);
	}
	else if(cardValue == "ace" || cardValue == "ACE")
	{
		cardValue = "Ace";
	}
	else if(cardValue == "king" || cardValue == "KING")
	{
		cardValue = "King";
	}
	else if(cardValue == "queen" || cardValue == "QUEEN")
	{
		cardValue = "Queen";
	}
	else if(cardValue == "jack" || cardValue == "JACK")
	{ 
		cardValue = "Jack";
	}

	for(unsigned int i = 0; i < getHand().size(); i++)
	{	
		if(getHand()[i]->getSuitOfCard() == suitOfcard &&	//IF THIS HAND HAS ANY IN THAT SUIT
			getHand()[i]->getValueOfCard() == cardValue &&	//IF SUIT HAS ANY OF THAT VALUE
			!getHand()[i]->getBeenPlayed())					//IF THE CARD HASN'T BEEN PLAYED
		{
			HaveCard = true;
			getHand()[i]->setbeenPlayed(HaveCard);
			p_Card2play = getHand()[i];						//HAVE THIS CARD EQUAL THE CARD THAT IS DESIRED TO PLAY			
			break;
		}
	}

	if(!HaveCard)
	{
		cout << ">>>> Could not locate card <<<<\n Card could've been played or is not in this hand.\n Please lead with a different card. d(^_^o)\n" << endl;
		setPlayACard();
	}
}
/************************************************************************************/
/*****************************
NAME: setPlayACard
FUNCTION:  GIVES THE NUMBER OF A CARD IN THE GROUP-USED 
			WHEN NOT LEADING TO PLAY A CARD
TYPE: VOID
ARGUEMENTS: c	-POINTER TO SET'S LEADING PLAYER'S CARD
RETURNS: NONE
******************************/
void Human::setPlayACard(Card* c)			
{
	bool HaveCard = false;
	string suitOfcard;
	string cardValue;
	cout << "Choose a card: ";
	cin >> suitOfcard >> cardValue;	
	strupr((char *) suitOfcard.c_str());
	
	if(suitOfcard == "EXIT")
	{
		exit(1);
	}
	if(cardValue == "exit")
	{
		exit(1);
	}
	else if(cardValue == "ace" || cardValue == "ACE")
	{
		cardValue = "Ace";
	}
	else if(cardValue == "king" || cardValue == "KING")
	{
		cardValue = "King";
	}
	else if(cardValue == "queen" || cardValue == "QUEEN")
	{
		cardValue = "Queen";
	}
	else if(cardValue == "jack" || cardValue == "JACK")
	{ 
		cardValue = "Jack";
	}

	for(unsigned int i = 0; i < getHand().size(); i++)
	{	
		if(getHand()[i]->getSuitOfCard() == suitOfcard &&	//IF THIS HAND HAS ANY IN THAT SUIT
			getHand()[i]->getValueOfCard() == cardValue &&	//IF SUIT HAS ANY OF THAT VALUE
			!getHand()[i]->getBeenPlayed())					//IF THE CARD HASN'T BEEN PLAYED
		{
			HaveCard = true;
			getHand()[i]->setbeenPlayed(HaveCard);
			p_Card2play = getHand()[i]; //HAVE THIS CARD EQUAL THE CARD THAT IS DESIRED TO PLAY			
			break;
		}
	}

	if(!HaveCard)
	{
		cout << ">>>> Could not locate card <<<<\n Card could've been played or is not in this hand.\n Please select again. d(^_^o)\n" << endl;
		setPlayACard(c);
	}	
}
/************************************************************************************/
/*****************************
NAME: getCollectTrick
FUNCTION:  THIS IS A POINTER TO THE COLLECTION
			OF CARDS THE PLAYER HAS WON
TYPE: VECTOR POINTER OF A VECTOR OF CARD POINTERS
ARGUEMENTS: NONE
RETURNS: p_CardsWon - RETURNS THE A DOUBLE VECTOR
******************************/
vector< vector<Card*> *> Human::getCollectTrick()
{
	return p_CardsWon;	
}
/************************************************************************************/
/*****************************
NAME: getPlayACard
FUNCTION:  RETURNS THE CARD CHOSEN BY THE USER
TYPE: CARD POINTER
ARGUEMENTS: NONE
RETURNS: p_Card2play - RETURNS A POINTER OF A CARD
******************************/
Card* Human::getPlayACard()
{
	return p_Card2play;
}