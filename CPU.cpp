#include "stdafx.h"
#include ".\CPU.h"

/************************************************************************************************
	Andre Vernon
	Spades Program
	CPU HEADER FILE
************************************************************************************************/
//UC = UNDERCONSTRUCTION OF BEING WRITTEN AND IMPLEMENTED
/* 
	-A check of no face cards and no spades  
	(bool playableHand) 
		[if( suit == 4 or card > 10 or card == 11) playable = true;
	-All players have a turn
	(bool myTurn)
		[if(firstHand == true) user is first  
		 else if( the player that won that hand )

************************************************************************************************
PUBLIC:	
	CPU();														//CONSTRUCTOR
	CPU(int seat);												//CONSTRUCTOR THAT SETS A PLAYERS SEAT POSITION
	~CPU();														//DECONSTRUCTOR

	//------------------------------------------SETTERS---------------------------------------------------------------//
UC-	void setSuitToPlay();										//THIS WILL SELECT THE PROPER SUIT THAT SHOULD BE PLAYED;
UC-	void setCardValueToPlay();									//THIS WILL CYCLE THROUGH THE VALUES OF THAT SUIT;
UC-	void setCardMemory(Card c);									//THIS WILL KEEP TRACK OF THE CARDS THAT HAS NOT BEEN PLAYED THAT ARE HIGHER THAN 

	//------------------------------------------GETTERS---------------------------------------------------------------//
UC-	string getSuitToPlay();										//RETURNS THE SUIT THAT SHOULD BE PLAYED
UC-	string getCardValueToPlay();								//RETURNS THE VALUE OF THE CHOSEN CARD
UC- Card* GetCardToPlay();										//RETURNS A POINTER TO A CARD THAT SHOULD BE PLAYED
	//------------------------------------------VIRTUALS--------------------------------------------------------------//
	//ALL VOID VIRTUAL FUNCTIONS
	virtual void setBid();										//COLLECTS THE BIDS FROM A PLAYER
	virtual void setCollectTrick(vector<Card*>& cardsWon);		//DOUBLE VECTOR, HOLDS THE HANDS THAT WERE WON 
	virtual void setPlayACard();								//GIVES THE NUMBER OF A CARD IN THE GROUP
	virtual void print();										//PRINTS OFF THE CARDS OF A PLAYER
	
	//ALL RETURNING A VALUE VIRTUAL FUNCTIONS
	virtual int getBid();										//RETRIEVES THE BID OF A PLAYER 
	virtual Card* getPlayACard();								//RETRIEVES THE CARD DESIRED TO PLAY
	virtual vector<Card*>& getCollectTrick(int trickNum);		//RETRIEVES THE 4 OF CARDS IN WON HANDS	

PRIVATE:
	int p_BidNum;						//THE BID GIVEN BY A PLAYER
	Card* p_Card2play;					//THE CARD TO BE OR PLAYED BY A PLAYER
	vector<vector<Card*>*> p_CardsWon;	//THE TRICKS WON BY THE PLAYER
	int p_TricksWon;					//USED TO KEEP COUNT OF THE NUMBER OF TRICKS WON
	string suitTo
************************************************************************************************/


/*****************************
NAME: CPU
FUNCTION: CREATES A BOT AND SETS THE PLAYERS VARIABLES TO ZERO
TYPE: CONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
CPU::CPU()
: Player(),
  p_TricksWon(0),
  p_BidNum(0),
  p_PlayerMemoryDeck(52)
{
	p_CardsWon.resize(0);
}

/*****************************
NAME: CPU
FUNCTION: CREATES A BOT PLAYER AND PLACES THEM IN A SEAT
TYPE: CONSTRUCTOR
ARGUEMENTS: seat -- THIS WILL BE PASSED IN THE GAME CONSTRUCTOR TO PLACE
                    A PLAYER THEIR PLAYER NUMBER
RETURNS: NONE
******************************/
CPU::CPU(int seat)
: Player(seat),
  p_TricksWon(0),
  p_BidNum(0),
  p_PlayerMemoryDeck(52)
{
	p_CardsWon.resize(0);
}

/*****************************
NAME: setBidToZero
FUNCTION: RETURNS THE BID COUNT TO ZERO
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void CPU::setBidToZero()
{
	p_BidNum = 0;					
}

/*****************************
NAME: setBid
FUNCTION: THE BOT WILL LOOK AT THEIR CARDS AND SELECT CERTAIN CARDS
          THAT IT BELIEVES IT CAN WIN.  THUS INCREASING BOT'S BID COUNT
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void CPU::setBid()
{
	int low_spadeCount = 0;
	for(int i = 0; i < 13; i++)
	{
		//ACE AND KING ARE A HIGH CHANCE OF A WIN SO COUNTS THEM AS SUCH
		if(((getHand()[i]->getValueOfCard()) == "Ace") || 
			((getHand()[i]->getValueOfCard()) == "King"))
		{
			p_BidNum++;
		}
		else if(getHand()[i]->getSuitOfCard() == "S")
		{
			//FOR EVERY 2 SPADES BOT BELIEVES IT CAN WIN WITH ATLEAST ONE
			if(low_spadeCount == 0)
			{
				low_spadeCount = 1;
			}
			else
			{
				low_spadeCount = 0;
				p_BidNum++;
			}
		}
/*		else					
		{
			//PRINTS WHICH CARDS THE BOT DIDN'T WANT TO BID ON
			cout << "Not worth a bid: ";
			getHand()[i]->print();
		}
		*/
	}
}

/*****************************
NAME: setCollectTrick
FUNCTION: TAKES THE CARDS THAT THIS BOT HAS WON ON THE TABLE 
          AND PUTS THEM IN THE BACK OF THEIR VECTOR (VERY SIMILAR
		  TO REAL PEOPLES' PERSONAL COLLECTION OF THEIR WINNINGS)
TYPE: VOID
ARGUEMENTS: cardsWon  --HOLDS FOUR POINTERS TWO THE CARDS IT HAS 
                        JUST WON  
RETURNS: NONE
******************************/
void CPU::setCollectTrick(vector<Card*>& cardsWon)	
{
	p_CardsWon.push_back(&cardsWon);
}

/*****************************
NAME: setTrickCountToZero
FUNCTION: WHEN STARTING A NEW GAME THIS SETS THE NUMBER OF 
          TIMES THE PLAYER HAS WON TO ZERO
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void CPU::setTrickCountToZero()
{
	p_CardsWon.resize(0);
}

/*****************************
NAME: print
FUNCTION: LETS CREATER KNOW THAT THE BOT HAS BEEN PROPERLY CREATED
          ASIDE FROM THAT SERVES NO REAL PURPOSE
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void CPU::print()					
{
	cout << "FINALLY... I AM A LIVING CPU." << endl;
}


/*****************************
NAME: getBid
FUNCTION: RETRIEVES THE BID NUMBER WHEN ASKED
TYPE: INT
ARGUEMENTS: NONE
RETURNS: p_BidNum --HOLDS THE BID COUNT OF THIS BOT
******************************/
int CPU::getBid()					
{
	return p_BidNum;
}

/*****************************
NAME: setPlayACard
FUNCTION: WHEN LEADING THIS IS THE A.I. OF A BOT WHEN IT
          CHOOSES A CARD 
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void CPU::setPlayACard()
{
	bool HaveCard = false;			//DETERMINES IF BOT HAS THE CARD
	string suitOfcard;				//HOLDS SUIT THAT THE BOT IS GOING TO PLAY
	
	int NumOfSpades = 0;			//SETS ALL SUITS EQUAL TO ZERO EVERYTIME IT GETS READY TO COUNT HOW MANY IT HAS
	int NumOfHearts = 0;
	int NumOfDiamonds = 0;			
	int NumOfClubs = 0;
	int LowSuitNum = 13;			//IS SET AT 13 BECAUSE IT IS THE HIGHEST NUMBER FOR A CARD
	int CardDesiredToPlay = 0;		//PASSED THE POSITION IN THE CARDS DESIRED TO PLAY

	if(Player::getWinnerOfCard())	//IF THE BOT IS LEADING 
	{
		for(unsigned int i = 0; i < getHand().size(); i++)	//LOOP USED TO COUNT THE AMOUNT OF CARDS IN EACH SUIT
		{
			if(getHand()[i]->getSuitOfCard() == "H" && !getHand()[i]->getBeenPlayed())
			{
				NumOfHearts++;				
			}
			else if(getHand()[i]->getSuitOfCard() == "D" && !getHand()[i]->getBeenPlayed())
			{
				NumOfDiamonds++;
			}
			else if(getHand()[i]->getSuitOfCard() == "C" && !getHand()[i]->getBeenPlayed())
			{
				NumOfClubs++;
			}
			else if(getHand()[i]->getSuitOfCard() != "S" && !getHand()[i]->getBeenPlayed())
			{
				cout << ">>>>> ERROR IN setPlayACard FOR CPU with getLeading Condition <<<<<" << endl;
			}
		}
		
		if(NumOfClubs < LowSuitNum && NumOfClubs > 0)
		{
			suitOfcard = "C";							//SELECTS CLUBS AS ITS SUIT IF FOLLOWING CONDITIONS ARE FALSE
			LowSuitNum = NumOfClubs;					//SETS THE LOWESTS AMOUNT OF CARDS IN A SUIT IS CLUBS
		}
		if(NumOfHearts < LowSuitNum && NumOfHearts > 0)
		{
			suitOfcard = "H";							//SELECTS HEARTS AS ITS SUIT
			LowSuitNum = NumOfHearts;					//SETS THE LOWESTS AMOUNT OF CARDS IN A SUIT IS HEARTS
		}
		if(NumOfDiamonds < LowSuitNum && NumOfDiamonds > 0)
		{
			suitOfcard = "D";							//SELECTS DIAMONDS AS ITS SUIT
			LowSuitNum = NumOfDiamonds;					//SETS THE LOWESTS AMOUNT OF CARDS IN A SUIT IS DIAMONDS
		}
		if(NumOfDiamonds == 0 && NumOfHearts == 0 && NumOfClubs == 0)
		{
			suitOfcard = "S";							//SELECTS SPADES AS ITS SUIT		
		}

		for(unsigned int i = 0; i < getHand().size();i++)			// NOTE:MAKE THIS RECURSIVE
		{
			if(getHand()[i]->getSuitOfCard() == suitOfcard)	//THIS CARD EQUALS A CARD OF THE LOWEST SUIT
			{			
				if(getHand()[i]->getValueOfCard() == "2" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;
				}
				if(getHand()[i]->getValueOfCard() == "3" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "4" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "5" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "6" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "7" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "8" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "9" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "10" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "Jack" && !getHand()[i]->getBeenPlayed())
				{
						CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "Queen" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "King" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
				if(getHand()[i]->getValueOfCard() == "Ace" && !getHand()[i]->getBeenPlayed())
				{
					CardDesiredToPlay = i;		
					break;				}
			}
			else if(getHand()[i]->getSuitOfCard() != suitOfcard)
			{
				//LETS ME KNOW THAT THE CARD CHECKED IS NOT OF THE LOWEST SUIT
				//cout << "Not of Lowest Suit" << endl;
			}
			else 
			{ 
				//ERROR CHECKS FOR IF THE A.I. HAS PROBLEMS
				cout << ">>>>> ERROR IN setPlayACard FOR CPU with SELECTING A CARDE IN getLeading Condition <<<<<" << endl;	
			}	
		}
	}
	else
	{
		cout << ">>>>>>>>>>ERROR::CPUsetPlayACard CPU THOUGHT IT WAS LEADING<<<<<<<<<<<<<" << endl;
	}

	/*if(!HaveCard) //IF AFTER GOING THROUGH THE HAND DOESN'T FIND A CARD TO LEAD WITH
	{
		//cout << ">>>>>>ERROR::Card does not exist in current hand<<<<<<" << endl;
	}
	else		//FINDS A PLAYABLE CARD TO LEAD WITH
	{
	//	cout << "Card Playable\n" << endl;
	}*/
	HaveCard = true;
	getHand()[CardDesiredToPlay]->setbeenPlayed(HaveCard);
	p_Card2play = getHand()[CardDesiredToPlay]; //HAVE THIS CARD EQUAL THE CARD THAT IS DESIRED TO PLAY	
}

/*****************************
NAME: setPlayACard
FUNCTION: WHEN NOT LEADING THIS IS THE A.I. OF A BOT WHEN 
          IT CHOOSES A CARD
TYPE: VOID
ARGUEMENTS: c -- c POINTS TO THE LEADING CARD TO FIND OUT 
                 WHICH SUIT IS LEADING THIS SET
RETURNS: NONE
******************************/
void CPU::setPlayACard(Card* c)
{
	bool HaveCard = false;
	string suitOfcard;
	
//	cout << "Player: " << Player::getSeat()+1 << endl;		//OUTPUTS THE BOT'S SEAT

	if(Player::getWinnerOfCard())		//IF THE BOT SHOULD BE LEADING
	{
		setPlayACard();
	}
	else if(!Player::getWinnerOfCard())	//IF THE BOT IS NOT LEADING
	{
		for(unsigned int i = 0; i < getHand().size();i++)	//IF THE CARD IS OF THE SUIT LEAD & IT HASN'T BEEN PLAYED & LEADING CARD IS NOT A SPADE
		{
			if(getHand()[i]->getSuitOfCard() == c->getSuitOfCard() && !getHand()[i]->getBeenPlayed() && c->getSuitOfCard() != "S")
			{ 
				HaveCard = true;
				getHand()[i]->setbeenPlayed(HaveCard);
				p_Card2play = getHand()[i];				
				break;
			}
		}
		if(!HaveCard)	//IF THE BOT DOESN'T HAVE A CARD OF THAT SUIT THAT HAS NOT BEEN PLAYED OR LEADING CARD IS A SPADE
		{
			for(unsigned int i = 0; i < getHand().size();i++)
			{
				if(getHand()[i]->getSuitOfCard() == "S" && !getHand()[i]->getBeenPlayed())
				{ 
					HaveCard = true;
					getHand()[i]->setbeenPlayed(HaveCard);
					p_Card2play = getHand()[i];				
					break;
				}
			}
		}
		if(!HaveCard)	//IF BOT DON'T HAVE ANY SPADES OR LEADING CARD, IT JUST PLAYS NEXT CARD IN HAND
		{
			for(unsigned int i = 0; i < getHand().size();i++)
			{
				if(!getHand()[i]->getBeenPlayed())
				{
					HaveCard = true;
					getHand()[i]->setbeenPlayed(HaveCard);
					p_Card2play = getHand()[i];	
					break;
				}
			}
		}
	}

	if(!HaveCard) //IF AFTER GOING THROUGH THE HAND DOESN'T FIND A CARD TO LEAD WITH
	{
		cout << ">>>>>>ERROR::Card does not exist in current hand<<<<<<" << endl;
	}
	else		//FINDS A PLAYABLE CARD TO LEAD WITH
	{
	//	cout << "Card Playable\n" << endl;
	}
}

/*****************************
NAME: getCollectTrick
FUNCTION: RETRIEVES THE TRICK THE BOT JUST WON 
TYPE: DOUBLE VECTOR OF CARD POINTERS
ARGUEMENTS: NONE
RETURNS: p_CardsWon --VECTORS SIZE DETERMINES HOW
                      MANY TRICKS IT HAS WON
******************************/
vector< vector<Card*> *> CPU::getCollectTrick()		 
{
	return p_CardsWon;	
}

/*****************************
NAME: getPlayACard
FUNCTION: RETRIEVES THE MOST RECENT CARD DESIRED TO PLAY
TYPE: CARD*
ARGUEMENTS: NONE
RETURNS: p_Card2play --CALLS A POINTER TO CARD          
******************************/
Card* CPU::getPlayACard()			
{
	return p_Card2play;
}