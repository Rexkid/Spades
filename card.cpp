
/************************
	Andre Vernon
	Spades Program
	Card SOURCE FILE
	
************************/

/************************************************************************************************************************
  THIS CLASS CONSIST OF:
  
PUBLIC:
	enum Suit {Diamonds, Hearts, Clubs, Spades};	//DECLARES THE DIFFERENT NAMES OF A SUIT										
	Card();											//CARD CONSTRUCTOR
	Card(int suitOfcard, int cardValue);			//CARD CONSTRUCTOR THAT TAKES IN THE RANK AND SUIT OF THE CARD
	~Card();										//CARD DECONSTRUCTOR	
	string getSuitOfCard();							//RETRIEVES THE SUIT OF A CARD
	string getValueOfCard();						//RETRIEVES THE VALUE OF A CARD	
	void setbeenPlayed(bool beenPlayed);			//DETERMINES WEATHER OR NOT THE CARD HAS BEEN PLAYED OR NOT
	void print();									//OUTPUTS SUIT AND CARD VALUE
	bool getBeenPlayed();							//RETRIEVES THE VALUE OF THE BOOL BEEN PLAYED
	
PRIVATE:	
	void setSuitOfCard(int cardSuit);		//GOES THROUGH A FOR LOOP AND SETS THE SUIT OF THE CARD
	void setValueOfCard(int cardValue);		//GOES THROUGH AND SETS THE VALUE OF EACH CARD AND RETRIEVES THE VALUE OF A CARD
	int p_cardSuit;							//HOLDS THE VALUE OF THE SUITS
	string p_suitOfCard;					//HOLDS A STRING OF THE BEGINNING LETTER OF A SUIT
	string p_cardValue;						//HOLDS A Card VALUE	
	bool p_BeenPlayed;						//VERIFIER IF CARD HAS BEEN PLAYED 
************************************************************************************************************************/

#include ".\Card.h"

Card::Card()				//Card CONSTRUCTOR
{
	setSuitOfCard(3);
	setCardNumValue(1);
	setValueOfCard();
	setbeenPlayed(false);
}

/************************************************************************************/
/*****************************
NAME: Card
FUNCTION: SETS CREATES EACH CARD
TYPE: CONSTRUCTOR
ARGUEMENTS: cSuit     --SETS THE SUIT OF EACH CARD
			cardValue --SETS THE VALUE OF EACH CARD
RETURNS: NONE
******************************/
Card::Card(int cSuit, int cardValue)
{
	setSuitOfCard(cSuit);
	setCardNumValue(cardValue);
	setValueOfCard();
	setbeenPlayed(false);
}

/************************************************************************************/
/*****************************
NAME: Card
FUNCTION: CLOSES THE CONSTRUCTOR
TYPE: DECONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Card::~Card()								//Card DECONSTRUCTOR
{}

/************************************************************************************/
/*****************************
NAME: setSuitOfCard
FUNCTION: GOES THROUGH A FOR LOOP AND SETS THE SUIT OF THE CARD 
TYPE: VOID
ARGUEMENTS: cardSuit  --SETS THE SUIT OF THE CARD
RETURNS: NONE
******************************/
void Card::setSuitOfCard(int cardSuit)		
{
	if(cardSuit == Card::Spades)
	{
		p_suitOfCard = "S";
	}
	else if(cardSuit == Card::Diamonds)
	{
		p_suitOfCard =  "D";
	}
	else if(cardSuit == Card::Clubs)
	{
		p_suitOfCard =  "C";
	}
	else if(cardSuit == Card::Hearts)
	{
		p_suitOfCard =  "H";
	}
	else
	{
		cout << ">>>ERROR WITHIN setSuitOfCard()<<<" << endl;
	}	
}

/*****************************
NAME: setbeenPlayed
FUNCTION: DETERMINES WIETHER OR NOT THE CARD HAS BEEN PLAYED OR NOT 
TYPE: void
ARGUEMENTS: beenPlayed  --IS FALSE UNTIL A USER PLAYS THE CARD
RETURNS: N/A
******************************/
void Card::setbeenPlayed(bool beenPlayed)			//
{
	p_BeenPlayed = beenPlayed;
}

/*****************************
NAME: setCardNumValue
FUNCTION: SETS THE CARD VALUE 
TYPE: void
ARGUEMENTS: cardValue  --SETS THE VALUE OF THE CARD WHEN THE DECK IS CREATED 
RETURNS: NONE
******************************/

void Card::setCardNumValue(int cardValue)
{
	p_cardNumValue = cardValue;
}
	
/*****************************
NAME: setValueOfCard
FUNCTION: THIS IS LIKE A CHART OF AVAILABLE CARD VALUES
TYPE: void
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Card::setValueOfCard()  
{
	if(p_cardNumValue == 1)
	{
		p_cardValue = "Ace";
	}
	else if(p_cardNumValue == 2)
	{
		p_cardValue = "2";
	}
	else if(p_cardNumValue == 3)
	{
		p_cardValue = "3";
	}
	else if(p_cardNumValue == 4)
	{
		p_cardValue = "4";
	}
	else if(p_cardNumValue == 5)
	{
		p_cardValue = "5";
	}
	else if(p_cardNumValue == 6)
	{
		p_cardValue = "6";
	}
	else if(p_cardNumValue == 7)
	{
		p_cardValue = "7";
	}
	else if(p_cardNumValue == 8)
	{
		p_cardValue = "8";
	}
	else if(p_cardNumValue == 9)
	{
		p_cardValue = "9";
	}
	else if(p_cardNumValue == 10)
	{
		p_cardValue = "10";
	}
	else if(p_cardNumValue == 11)
	{
		p_cardValue = "Jack";
	}
	else if(p_cardNumValue == 12)
	{
		p_cardValue = "Queen";
	}
	else if(p_cardNumValue == 13)
	{
		p_cardValue = "King";
	}
	else
	{
		cout << ">>>ERROR WITHIN setValueOfCard()<<<" << endl;
	}
}

/*****************************
NAME: print
FUNCTION: THIS WILL PRINT OUT THE SUIT AND VALUE OF EACH CARD 
TYPE: void
ARGUEMENTS: NONE
RETURNS: NONE
******************************/

void Card::print() 
{
	char symbol = '*';
	if(getSuitOfCard() == "S")
	{
		symbol = 6;
		cout  << symbol << ": " << getValueOfCard() << "       : " << "Card Num Value: " << getCardNumValue() << endl;
	}
	else if(getSuitOfCard() == "H")
	{
		symbol = 3;
		cout  << symbol << ": " << getValueOfCard() << "       : " << "Card Num Value: " << getCardNumValue() << endl;
	}
	else if(getSuitOfCard() == "D")
	{
		symbol = 4;
		cout  << symbol << ": " << getValueOfCard() << "       : " << "Card Num Value: " << getCardNumValue() << endl;
	}
	else if(getSuitOfCard() == "C")
	{
		symbol = 5;
		cout  << symbol << ": " << getValueOfCard() << "       : " << "Card Num Value: " << getCardNumValue() << endl;
	}
	else
	{
		cout << ">>> ERROR IN CARD PRINT <<<" << endl;
	}
}

/*****************************
NAME: getCardNumValue
FUNCTION: THIS GETS THE INTEGER VALUE OF A CARD TO COMPARE NUMERICALLY 
		  IF THE VALUE OF A CARD IS HIGHER THAN ANOTHER
TYPE: int
ARGUEMENTS: NONE
RETURNS: p_carNumValue --HOLDS NUMBERICAL CARD VALUE
******************************/
int Card::getCardNumValue()
{
	return p_cardNumValue;
}

/*****************************
NAME: getValueOfCard
FUNCTION: GETS THE WORD VALUE OF A CARD FOR THE USER TO SEE 
TYPE: string
ARGUEMENTS: NONE
RETURNS: p_cardValue  --THIS WILL BE USED FOR PRINTING TO THE SCREEN
                        ALSO COMPARING WITH THE CARD SELECTION
******************************/
string Card::getValueOfCard()
{
	return p_cardValue;
}

/*****************************
NAME: getSuitOfCard
FUNCTION: WILL RETRIEVE THE SUIT OF A CARD, IS HELPFUL WHEN KNOWING WHICH
          SUIT IS LEADING
TYPE: string
ARGUEMENTS: N/A
RETURNS: getSuitOfCard  --RETURNS THE STRING FORM OF THE CARD'S SUIT
******************************/
string Card::getSuitOfCard()
{
	return p_suitOfCard;
}

/*****************************
NAME: getBeenPlayed
FUNCTION: THIS IS USE TO FIND OUT HOW MANY CARDS ARE STILL IN THE 
          USER'S HAND
TYPE: bool
ARGUEMENTS: NONE
RETURNS: p_BeenPlayed  --THIS WILL ONLY BE CHANGED AFTER A USER PICKS A CARD
******************************/
bool Card::getBeenPlayed()							
{
	return p_BeenPlayed;
}