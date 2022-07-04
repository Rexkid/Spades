#include "stdafx.h"
#include ".\game.h"

/***********************
	Andre D. Vernon
	Artificial Intelligence
	GAME SOURCE FILEb
***********************/

/*
public:
	Game();											//DEFAULT CONSTRUCTOR
	Game(int WinningScore);							//TAKES IN AMOUNT OF PLAYERS INVOLVED AND WHAT GAME ENDS AT
	~Game();										//DECONSTRUCTOR

	bool GameOver();								//HOLDS THE CONDITION IF SCORE IS REACH 
	bool PlayableCardCheck();						//RETURNS TRUE IF CARDS NEED TO BE REDEALT	
	bool getBlind();								//RETURNS TRUE IF ABLE TO BID BLIND
	bool getCanPlayOutOfSuit(Player* p, Card* cardPlayed);	//RETURNS IF THE PLAYER IS ALLOWED TO NOT PLAY LEADING SUIT	
	bool getSpadePlayedThisHand();					//RETURNS TRUE IF A SOMEONE HAS CUT WITH A SPADE


	void MainProgram();								//RUNS WHOLE PROGRAM

	void setPlayerTurn(int Seat);					//SETS THE ORDER OF WHO'S TURN IT IS 
	void setWofSet();								//SETS THE WINNER OF THE HAND ON THE TABLE
	void setTableHand(Player* p, Card* cardPlayed);	//SETS THE CARDS OF EACH PLAYER PLAYED ON THE TABLE
	void setCreatePlayers();						//CREATES EACH PLAYER FOR THE GAME
	void setSuperiorSuit(string firstCardPlayed);	//SETS THE LEADING SUIT
	void setPlayerPointer(int playerSeatPointedAt);	//SETS A PLAYER POINTER
	void setScore();								//THIS IS TO SET THE SCORE OF EACH TEAM
	void setSpadePlayedThisHand(bool SpadePlayed);	//CHECKS SO NO ONE LEADS WITH SPADES UNTIL SPADES HAS CUT 	
	void printMyHand();								//PRINTS OFF MY CARDS

	string GetSuperiorSuit();						//GETS THE LEADING SUIT

	vector<Player*> getCreatedPlayers();			//RETRIEVES THE PLAYERS CREATED
	vector<int> getScore(int team);					//RETRIEVES THE SCORE OF A TEAM
	
	Player* getPlayerTurn();						//RETURNS A PLAYER OF WHO TURN IT IS
	Player* getWofSet();							//RETURNS THE WINNER OF THE HAND
	Player* getPlayerPointer();						//RETURNS A PLAYER POINTER THAT IS SELECTED

private:
	vector<Card*> p_TableCards;				//CARDS PLAYED IN ONE HAND 
	vector<int> p_teamScore;				//HOLDS THE SCORE OF THE TWO TEAMS
	vector<Player*> p_Players;				//IS JUST A POINTER TO THE PLAYERS
	vector< vector<Card*> > p_PlayersHands;	//HOLDS A POINTER TO EACH PLAYERS HAND

	int p_WinningScore;						//HOLDS WHAT THE GAME IS UP TO
	
	string p_superiorSuit;					//HOLDS THE LEADING SUIT 

	bool p_PlayableCardCheck;				//A CHECKING VARIABLE TO SEE IF EVERY PLAYER HAS AT LEAST A SPADE AND A FACE CARD
	bool p_WinnerOfHand;					//A VARIABLE THAT IS SET TRUE IF A PLAYER HAS THE HIGHEST CARD
	bool p_SpadePlayedThisHand;				//TRUE IF SOMEONE HAS CUT WITH A SPADE IN A GAME
	bool p_GameOver;						//IS SET TRUE WHEN A SCORE HAS OR EXCEEDS p_WinningScore

	Player* p_Player;						//WILL BE USED TO PASS OR PASS BACK A PLAYER
	Deck d;									//THIS IS A TEMPORARY DECK OF CARDS

	int p_seat;								//THIS IS AN INT FOR THE SEAT OF A PLAYER
*/

/*********************CONSTRUCTORS AND DESTRUCTOR*****************************************/

/************************************************************************************/
/*****************************
NAME: Game
FUNCTION:  CONSTRUCTOR
TYPE: CREATES THE DEFAULTS OF THE GAME
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Game::Game()
: p_Players(4),				//SETS THE SIZE FOR THE NUMBER OF PLAYERS 
 p_TableCards(4),			//SETS THE SIZE FOR HOW MANY CARDS CAN BE PLAYED ON A TABLE PLAYED
 p_PlayersHands(4),			//HOLDS A VECTOR OF VECTORS, THE VECTOR INSIDE IS A HAND OF CARDS 
 p_teamScore(2),			//CREATES TWO TEAMS THAT HOLDS INTs
 p_WinningScore(100),		//AN INT THAT SETS THE SCORE GOAL
 p_PlayableCardCheck(true),	//HAS IT SO THAT IN ORDER FOR THE GAME TO BE PLAYED THE SPADE AND FACE CARD CHECK IS TRUE
 p_GameOver(false),			//HAS THE GAME OVER BE FALSE BECAUSE THE SCORE IS NOT REACHED YET
 p_SpadePlayedThisHand(false),				//A SPADE HASN'T BEEN PLAYED THEREFORE NOONE CAN LEAD WITH A SPADE YET
 p_WinnerOfHand(false)		//A VARIABLE THAT IS SET TRUE IF A PLAYER HAS THE HIGHEST CARD
{
	//cout << "*******************************CREATING LIFE**********************************" << endl;
	CPU* c = new CPU(0);
	p_Players[0] = c;
	CPU* c1 = new CPU(1);
	p_Players[1] = c1;
	CPU* c2 = new CPU(2);
	p_Players[2] = c2;
	CPU* c3 = new CPU(3);
	p_Players[3] = c3;

	d.Shuffle(d.getCards());				//SHUFFLES THE CARDS IN THE DECK
	setCreatePlayers();						//CREATES THE 4 PLAYERS
	p_Player = p_Players[0];				//SETS THE FIRST PERSON TO GO AS THE PLAYER IN SEAT 0
	getPlayerTurn()->setWinnerOfHand(true);	//SETS THIS PLAYER AS THE INNER OF A NULL HAND TO HAVE IT GO FIRST
}
/************************************************************************************/
/*****************************
NAME: Game
FUNCTION:  CONSTRUCTOR
TYPE: SETS THE DEFAULTS OF THE GAME
ARGUEMENTS: WinningScore -INPUT FROM THE USER, SETTING THE END SCORE LIMIT
RETURNS: NONE
******************************/
Game::Game(int WinningScore)
: p_Players(4),								//SETS THE SIZE FOR THE NUMBER OF PLAYERS 
 p_TableCards(4),							//SETS THE SIZE FOR HOW MANY CARDS CAN BE PLAYED ON A TABLE PLAYED
 p_PlayersHands(4),							//HOLDS A VECTOR OF VECTORS, THE VECTOR INSIDE IS A HAND OF CARDS 
 p_teamScore(2),							//CREATES TWO TEAMS THAT HOLDS INTs
 p_WinningScore(WinningScore),				//AN INT THAT SETS THE SCORE GOAL
 p_PlayableCardCheck(true),					//HAS IT SO THAT IN ORDER FOR THE GAME TO BE PLAYED THE SPADE AND FACE CARD CHECK IS TRUE
 p_GameOver(false),							//HAS THE GAME OVER BE FALSE BECAUSE THE SCORE IS NOT REACHED YET
 p_SpadePlayedThisHand(false),				//A SPADE HASN'T BEEN PLAYED THEREFORE NOONE CAN LEAD WITH A SPADE YET
 p_WinnerOfHand(false)						//A VARIABLE THAT IS SET TRUE IF A PLAYER HAS THE HIGHEST CARD
{ 
	//cout << "*******************************CREATING LIFE**********************************" << endl;
	Human* c = new Human(0);
	p_Players[0] = c;
	CPU* c1 = new CPU(1);
	p_Players[1] = c1;
	CPU* c2 = new CPU(2);
	p_Players[2] = c2;
	CPU* c3 = new CPU(3);
	p_Players[3] = c3;

	//setCreatePlayers();						//CREATES THE 4 PLAYERS -- BUT IS ALSO DONE IN MAINPROGRAM
	p_Player = p_Players[0];				//SETS THE FIRST PERSON TO GO AS THE PLAYER IN SEAT 0
	getPlayerTurn()->setWinnerOfHand(true);	//SETS THIS PLAYER AS THE INNER OF A NULL HAND TO HAVE IT GO FIRST
}
/************************************************************************************/
/*****************************
NAME: ~Game
FUNCTION:  DECONSTRUCTOR
TYPE: DECONSTRUCTS THE CONSTRUCTOR
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
Game::~Game()								//DECONSTRUCTOR -: MAY NOT REALLY BE NEEDED
{}
/**********************MAIN PROGRAM********************************************/
/************************************************************************************/
/*****************************
NAME: MainProgram
FUNCTION:  RUNS THE FUNCTIONS OF THE GAME AS A WHOLE
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Game::MainProgram()					//RUNS THE PROGRAM 
{
	while(!GameOver())
	{
		setCreatePlayers();
		for(int hand = 0; hand < 13; hand++)
		{
			cout << "Hand: " << hand+1;
			char spade=6,heart=3,diamond=4,club=5;
			cout  << "           " << spade << "= S || " << heart << "= H || " << diamond << "= D || " << club << "= C\n" << 	
				"                  (Example for 8 of Clubs = C 8)\n" << endl;
		
			if(0==1)// <-- WILL NEVER EQUAL || TRUE COMPARISON ---> !PlayableCardCheck())
			{
				cout << "I am here because someone has no spades and no face cards." << endl;
				MainProgram();
			}
			else
			{	
				setPlayerTurn(getPlayerTurn()->getSeat());				//HAS THE PLAYERS PLAY IN A CERTAIN ORDER
 				getPlayerPointer()->setCollectTrick(p_TableCards);		//LOADS THE HAND INTO THE WINNERS PILE OF WINNING CARDS 
			} 
			cout << "\nPlayer " << getPlayerPointer()->getSeat()+1 << " is the Winner of this Hand." << endl;
 			system("pause");
			system("cls");

			printMyHand();			
		}

		cout << "***************************DISPLAYING THE SCORE********************************" << endl;

		setScore();
		cout << endl;

		for(unsigned int i = 0; i < p_teamScore.size(); i++)
		{		
			cout << "Team " << i+1 <<  " Score: " << p_teamScore[i] << endl;
		}
		system("pause");
	}
} 
/***********************BOOLEAN SETTERS************************************/
/************************************************************************************/
/*****************************
NAME: GameOver
FUNCTION: A CHECKER TO SEE IF THE END SCORE HAS BEEN REACHED TO FINISH THE GAME
TYPE: BOOL
ARGUEMENTS: NONE
RETURNS: p_GameOver - RETURNS TRUE IF A TEAM HAS EXCEEDED OR REACHED THE END SCORE
******************************/
bool Game::GameOver()		//CHECKS TO SEE IF WINNING SCORE WAS REACHED TO END GAME
{
	for(unsigned int i = 0; i < p_teamScore.size();i++)
	{
		if(p_teamScore[i] >= p_WinningScore)		//>>>>FIX LATER<<<<CURRENTLY CHECKS IF EITHER TEAM HAS REACHED TOP SCORE AND FIRST IT CHECKS WITH 500 WINS 
		{											//NOW IF BOTH TEAMS REACH 500 IT DOESNT TAKE THE HIGHEST BUT THE FIRST IT CHECKS :
			if( i != 0 )
			{
				cout << "Team 2 Wins!!" << endl;
			}
			else
			{
				cout << "Team 1 Wins!!" << endl;
			}
			p_GameOver = true;
			exit(0);
		}
	}
	return p_GameOver;
}
/************************************************************************************/
/*****************************
NAME: PlayableCardCheck
FUNCTION:  CHECKER TO SEE IF ALL PLAYERS HAVE AT LEAST ONE SPADE OR A FACE CARD
TYPE: BOOL
ARGUEMENTS: NONE
RETURNS: p_PlayableCardCheck - FALSE IF A PLAYER HAS NO SPADES NOR FACE CARDS
******************************/
bool Game::PlayableCardCheck()				//>>>FIX LATER<<<IS SUPPOSE TO CHECK THE HANDS OF THE PLAYERS AND SEE IF THEY HAVE SPADES OR A FACE CARD, IF NOT DECK WILL RE SHUFFLE AND RE DEAL
{
	for(int i = 0; i < 4; i++)	//p_Players.size() SHOULD EQUAL 4 PLAYERS ()()()()()()()PREVIOUS CODE: for(unsigned int i = 0; i < p_Players.size(); i++)
	{	
		for(int j = 0; j < 13; j++)		//p_Players[i]->getHand().size() SHOULD EQUAL 13 CARDS THEY HOLD ()()()()()()PREVIOUS CODE: for(int j = 0; j < p_Players[i]->getHand().size(); j++)
		{
			if( p_Players[i]->getHand()[j]->getSuitOfCard() != "S" ||
				p_Players[i]->getHand()[j]->getValueOfCard() != "Ace" ||
				p_Players[i]->getHand()[j]->getValueOfCard() != "King" &&
				p_Players[i]->getHand()[j]->getValueOfCard() != "Queen" &&
				p_Players[i]->getHand()[j]->getValueOfCard() != "Jack")
			{
				p_Players[i]->getHand()[j]->print();
				cout << "\nHello!!! " << endl;
				p_PlayableCardCheck = false;
				break;
			}
		}
	}
	return p_PlayableCardCheck;
}
/****************************VOID SETTERS*****************************************************************************/
/************************************************************************************/
/*****************************
NAME: setCreatePlayers
FUNCTION:  SHUFFLES THE DECK, DEALS CARDS, SETS EACH PLAYERS BID
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Game::setCreatePlayers()	
{
	int cardNum = 0;
	int playerSeat = 0;
	vector<Card> OrganizedHand;
	setSpadePlayedThisHand(false);

	d.Shuffle(d.getCards());				//SHUFFLES THE CARDS IN THE DECK
	
	cout << "*******************************SETTING HAND**********************************" << endl;

	for(int j = 0; j < 4; j++)	//THERE ARE ONLY 4 PLAYERS FOR SPADES ()()()()UNIVERSAL UPON INPUT CODE: for(int j = 0; j < p_Players.size(); j++)
	{
		for(int i = 0; i < 13;i++)	//DIVIDES THE 52 CARDS TO 4 PLAYERS = 13 CARDS PER PLAYER ()()()()()UNIVERSAL UPON INPUT CODE: for(int i = 0; i < ((d.getCards().size())/p_Players.size());i++)
		{
			p_Players[j]->setHand(d.getCards()[cardNum++],i);	//SETS EACH PLAYERS HAND
		}
		if( p_Players[j]->getCollectTrick().size() > 0 || p_Players[j]->getBid() > 0 )
		{
			p_Players[j]->setTrickCountToZero();//MAKES SURE EACH PLAYER STARTS OFF WITH 0 TRICKS WON
			p_Players[j]->setBidToZero();		//MAKES SURE EACH PLAYER STARTS OFF WITH A BID OF 0
		}

 		if(j == 0)							//CURRENT CONDITION ONLY PRINTS THE PLAYER ONE (AKA p_Players[0]) CARDS AFTER BEING DEALT.
		{
			printMyHand();
		}		
		p_Players[j]->setBid();				//SETS THE DESIRED NUMBER OF BIDS ACCORDING TO THE HAND
	}

	cout << "*******************************BIDDING**********************************" << endl;
	
	for(int i = 0; i < 4; i++)  //THERE ARE ONLY 4 PLAYERS IN THIS SPADES ()()()()()UNIVERSAL UPON INPUT CODE: for(int i = 0; i < p_Players.size(); i++)
	{		
		cout << "     Player " << i+1 << "'s Bid: " << p_Players[i]->getBid() <<	 "   ||       Player " << i+2 << "'s Bid: " << p_Players[i+1]->getBid() << endl;
		i++;
	}
	
	vector<int> teamWinningBidCount(2);	//HOLDS THE TOTAL AMOUNT OF BOOKS WON BY EACH TEAM
	vector<int> beginningBidCount(2);

	for(int i = 0; i < 2; i++)
	{
		beginningBidCount[i] = p_Players[i]->getBid() + p_Players[i+2]->getBid();
		teamWinningBidCount[i] = p_Players[i]->getCollectTrick().size() + p_Players[i+2]->getCollectTrick().size();		
	}
	cout << "      Team " << playerSeat+1 << "'s Bid: " << beginningBidCount[playerSeat] <<	"    ||        Team " << playerSeat+2 << "'s Bid: " << beginningBidCount[playerSeat+1] << endl;
	cout << " -------------------------------------------------------------- " << endl;
	system("pause");	
}
/************************************************************************************/
/*****************************
NAME: setPlayerTurn
FUNCTION:  HAS THE PLAYER PLAY A CARD DEPENDING UPON IT'S SEATING ORDER
TYPE: VOID
ARGUEMENTS: Seat -LEADING PLAYERS SEAT NUMBER IS PASSED IN
RETURNS: NONE
******************************/
void Game::setPlayerTurn(int Seat)							//SETS THE ROTATION OF TURNS FOR THE GAME OF WHO GOES
{
	
	p_Players[Seat]->setWinnerOfHand(true);					//PLAYER IS SET AS WINNER, SO COMPUTER KNOWS IT HAS TO LEAD
	p_Players[Seat]->setPlayACard();							//PLAYS THE LEADING CARD
	if(Seat!=0)	{cout << "\n      Player " << Seat+1 << " is leading." << endl;}
	else {cout << "\n      Player " << Seat+1 << " is leading. The leading suit is " << p_Players[Seat]->getPlayACard()->getSuitOfCard() << "."<< endl;}

	if(p_Players[Seat]->getWinnerOfCard() == true)
	{
		if(Seat == 0)										//PLAYER IN SEAT 0 IS LEADING
		{
			setTableHand(p_Players[Seat],p_Players[Seat]->getPlayACard());		//0
			setSuperiorSuit(p_Players[Seat]->getPlayACard()->getSuitOfCard());	//AFTER THE FIRST PERSON GOES IT SETS THE SUPERIOR SUIT(LEADING SUIT)
			cout << "P" << Seat+1 << ": ";
						p_Players[Seat]->getPlayACard()->print();							//DISPLAYS THE CARD PLAYED

			if(p_Players[Seat]->getPlayACard()->getSuitOfCard() == "S")
			{
				if(getSpadePlayedThisHand()==false)
				{
					cerr << "Improper move: YOU CAN NOT LEAD WITH A SPADE UNTIL SPADES HAVE BEEN CUT." << endl;
					system("pause");
					p_Players[Seat]->getPlayACard()->setbeenPlayed(false);
					setPlayerTurn(Seat);					
				}
				else
				{
					for(int i = 1; i < 4; i++)
					{
						p_Players[Seat+i]->setPlayACard(p_Players[Seat]->getPlayACard());//HAS EACH PLAYER GO PLAY A CARD
						cout << "P" << Seat+i+1 << ": ";
						p_Players[Seat+i]->getPlayACard()->print();							//DISPLAYS THE CARD PLAYED
						setTableHand(p_Players[Seat+i],p_Players[Seat+i]->getPlayACard());	//PLACES THE CARD CHOSEN ON THE TABLE
					}	
				}
			}
			else
			{
				for(int i = 1; i < 4; i++)
				{
					p_Players[Seat+i]->setPlayACard(p_Players[Seat]->getPlayACard());
					if(p_Players[Seat+i]->getPlayACard()->getSuitOfCard() == "S")
					{
						if(getSpadePlayedThisHand()==false)
						{
							setSpadePlayedThisHand(true);
						}
					}
					cout << "P" << Seat+i+1 << ": ";
					p_Players[Seat+i]->getPlayACard()->print();							
					setTableHand(p_Players[Seat+i],p_Players[Seat+i]->getPlayACard());	
				}	
			}	
		}
		else if(Seat == 1)		//PLAYER IN SEAT 1 IS LEADING
		{
			cout << "P" << Seat+1 << ": ";
			p_Players[Seat]->getPlayACard()->print();							//DISPLAYS THE CARD PLAYED
			setTableHand(p_Players[Seat],p_Players[Seat]->getPlayACard());		//PLAYER PLACES THE CARD CHOSEN ON THE TABLE
			setSuperiorSuit(p_Players[Seat]->getPlayACard()->getSuitOfCard());	//AFTER THE FIRST PERSON GOES IT SETS THE SUPERIOR SUIT(LEADING SUIT)
		
			p_Players[Seat+1]->setPlayACard(p_Players[Seat]->getPlayACard());	//HAS PLAYER 2 PLAY A CARD 
			cout << "P" << Seat+2 << ": ";
			p_Players[Seat+1]->getPlayACard()->print();
			setTableHand(p_Players[Seat+1],p_Players[Seat+1]->getPlayACard());	//PLAYER PLACES THE CARD CHOSEN ON THE TABLE
			p_Players[Seat+2]->setPlayACard(p_Players[Seat]->getPlayACard());	//HAS PLAYER 3 PLAY A CARD 
			cout << "P" << Seat+3 << ": ";
			p_Players[Seat+2]->getPlayACard()->print();
			setTableHand(p_Players[Seat+2],p_Players[Seat+2]->getPlayACard());	//PLAYER PLACES THE CARD CHOSEN ON THE TABLE
			p_Players[Seat-1]->setPlayACard(p_Players[Seat]->getPlayACard());	//HAS PLAYER 0 PLAY A CARD 
			cout << "P" << Seat << ": ";
			p_Players[Seat-1]->getPlayACard()->print();
			setTableHand(p_Players[Seat-1],p_Players[Seat-1]->getPlayACard());	//PLAYER PLACES THE CARD CHOSEN ON THE TABLE
			if(getSpadePlayedThisHand()==false)
			{
				for(int i = 0; i < 4; i++)
				{
					if(p_Players[i]->getPlayACard()->getSuitOfCard() == "S")
					{		
						setSpadePlayedThisHand(true);
					}
				}
			}
		}
		else if(Seat == 2)		//PLAYER IN SEAT 2 IS LEADING
		{
			cout << "P" << Seat+1 << ": ";
			p_Players[Seat]->getPlayACard()->print();							//DISPLAYS THE CARD PLAYED
			setTableHand(p_Players[Seat],p_Players[Seat]->getPlayACard());		//2
			setSuperiorSuit(p_Players[Seat]->getPlayACard()->getSuitOfCard());	//AFTER THE FIRST PERSON GOES IT SETS THE SUPERIOR SUIT
		
			p_Players[Seat+1]->setPlayACard(p_Players[Seat]->getPlayACard());	//HAS PLAYER 3 PLAY A CARD 
			cout << "P" << Seat+2 << ": ";
			p_Players[Seat+1]->getPlayACard()->print();
			setTableHand(p_Players[Seat+1],p_Players[Seat+1]->getPlayACard());	//PLAYER PLACES THE CARD CHOSEN ON THE TABLE
			p_Players[Seat-2]->setPlayACard(p_Players[Seat]->getPlayACard());	//HAS PLAYER 0 PLAY A CARD 
			cout << "P" << Seat-1 << ": ";
			p_Players[Seat-2]->getPlayACard()->print();
			setTableHand(p_Players[Seat-2],p_Players[Seat-2]->getPlayACard());	//PLAYER PLACES THE CARD CHOSEN ON THE TABLE
			p_Players[Seat-1]->setPlayACard(p_Players[Seat]->getPlayACard());	//HAS PLAYER 1 PLAY A CARD 
			cout << "P" << Seat << ": ";
			p_Players[Seat-1]->getPlayACard()->print();
			setTableHand(p_Players[Seat-1],p_Players[Seat-1]->getPlayACard());	//PLAYER PLACES THE CARD CHOSEN ON THE TABLE
			if(getSpadePlayedThisHand()==false)
			{
				for(int i = 0; i < 4; i++)
				{
					if(p_Players[i]->getPlayACard()->getSuitOfCard() == "S")
					{		
						setSpadePlayedThisHand(true);
					}
				}
			}
		}
		else if(Seat == 3 && p_Players[Seat]->getWinnerOfCard() == true)		//PLAYER IN SEAT 3 IS LEADING
		{
			cout << "P" << Seat+1 << ": ";
			p_Players[Seat]->getPlayACard()->print();							//DISPLAYS THE CARD PLAYED
			setTableHand(p_Players[Seat],p_Players[Seat]->getPlayACard());		//PLAYER 3 PLACES THE LEADING CARD CHOSEN ON THE TABLE
			if(p_Players[Seat]->getPlayACard()->getSuitOfCard() == "S")
			{
				if(getSpadePlayedThisHand()==false)
				{
					cerr << "Improper move: YOU CAN NOT LEAD WITH A SPADE UNTIL SPADES HAVE BEEN CUT." << endl;
					system("pause");
					p_Players[Seat]->getPlayACard()->setbeenPlayed(false);
					setPlayerTurn(Seat);					
				}
				else
				{
					setSuperiorSuit(p_Players[Seat]->getPlayACard()->getSuitOfCard());	//AFTER THE FIRST PERSON GOES IT SETS THE SUPERIOR SUIT(LEADING SUIT)
					for(int i = 3; i > 0; i--)
					{
						p_Players[Seat-i]->setPlayACard(p_Players[Seat]->getPlayACard());	//HAS EACH PLAYER GO PLAY A CARD						
						cout << "P" << Seat-i+1 << ": ";
						p_Players[Seat-i]->getPlayACard()->print();							//DISPLAYS THE CARD PLAYED
						setTableHand(p_Players[Seat-i],p_Players[Seat-i]->getPlayACard());	//PLAYERS PLACE THE CARD CHOSEN ON THE TABLE
					}	
				}			
			}
			else
			{
				setSuperiorSuit(p_Players[Seat]->getPlayACard()->getSuitOfCard());	
				for(int i = 3; i > 0; i--)
				{
					p_Players[Seat-i]->setPlayACard(p_Players[Seat]->getPlayACard());	
					if(p_Players[Seat-i]->getPlayACard()->getSuitOfCard() == "S")
					{
						if(getSpadePlayedThisHand()==false)
						{
							setSpadePlayedThisHand(true);
						}
					}
					cout << "P" << Seat-i+1 << ": ";
					p_Players[Seat-i]->getPlayACard()->print();							
					setTableHand(p_Players[Seat-i],p_Players[Seat-i]->getPlayACard());	
				}	
			}				
		}
		else
		{
			cout << "<<<<<<<<<<< ERROR with setPlayerTurn(int Seat) >>>>>>>>>" << endl;
		}
	}
	setWofSet();													//DETERMINES THE WINNER OF THE HAND
}
/************************************************************************************/
/*****************************
NAME: setWofSet
FUNCTION: DECLARES THE WINNER OF A SET PLAYED
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Game::setWofSet()								
{	
	bool SpadePlayedInSet = false;		//RETURNS TRUE WHEN ONE OF THE FOUR CARDS IN THE SET IS A SPADE
	int winningSeat = getPlayerPointer()->getSeat();		//SETS THE DEFAULT PERSON WINNING IS THE PERSON LEADING
	Card* winning_Card = getPlayerPointer()->getPlayACard();//SETS THE DEFAULT WINNING CARD TO THE PERSON LEADING	

	for(int i = 0; i < 4; i++)		//GOES THROUGH THE FOUR CARDS PLAYED ON THE TABLE SO SIZE WILL ALWAYS BE 4()()()()UNIVERSAL INPUT CODE:for(int i = 0; i < p_TableCards.size(); i++)
	{
		p_Players[i]->setWinnerOfHand(false);			//SETS EACH PLAYER AS NOT A WINNER
		
		if(p_TableCards[i]->getSuitOfCard() == GetSuperiorSuit() && !SpadePlayedInSet)	//IF A SPADE HASN'T BEEN PLAYED AND THE CARD IS OF THE LEADING SUIT
		{
			if(p_TableCards[i]->getValueOfCard() == "Ace")	//IF THE CARD IS AN ACE 
			{
				winning_Card = p_TableCards[i];
				setPlayerPointer(i);
			}
			else if(p_TableCards[i]->getCardNumValue() > getPlayerPointer()->getPlayACard()->getCardNumValue() &&
					winning_Card->getValueOfCard() != "Ace")	//THE CARD COMPARED IS BETTER THAN THE CURRENT WINNING CARD WHICH IS NOT AN ACE 
			{
				winning_Card = p_TableCards[i];
				setPlayerPointer(i);
			}			
		}
		else if(p_TableCards[i]->getSuitOfCard() == "S")	//THE CARD COMPARED IS OF THE SUIT OF SPADES
		{
			SpadePlayedInSet = true;
			if(!getSpadePlayedThisHand()){setSpadePlayedThisHand(true);}
			if(p_TableCards[i]->getValueOfCard() == "Ace")	//IF THE CARD IS AN ACED IT IS AUTOMATICALLY THE BEST CARD OF THAT SUIT
			{
				winning_Card = p_TableCards[i];
				setPlayerPointer(i);
			}
			else if(winning_Card->getSuitOfCard() != "S" || p_TableCards[i]->getCardNumValue() > getPlayerPointer()->getPlayACard()->getCardNumValue() &&
					winning_Card->getValueOfCard() != "Ace")//IF THE WINNING CARD IS NOT A SPADE OR THE WINNING CARD IS NOT AN ACE AND LOWER THAN THE CARD COMPARED THEN THIS CARD IS A WINNER
			{
				winning_Card = p_TableCards[i];
				setPlayerPointer(i);
			}
		}
	}	
}
/************************************************************************************/
/*****************************
NAME: setScore
FUNCTION:  THIS IS TO SET THE SCORE OF EACH TEAM
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Game::setScore()
{
	vector<int> teamWinningBidCount(2);	//HOLDS THE TOTAL AMOUNT OF BOOKS WON BY EACH TEAM
	vector<int> beginningBidCount(2);

	for(int i = 0; i < 2; i++)
	{
		beginningBidCount[i] = p_Players[i]->getBid() + p_Players[i+2]->getBid();
		teamWinningBidCount[i] = p_Players[i]->getCollectTrick().size() + p_Players[i+2]->getCollectTrick().size();

		cout << "\nTeam " << i+1 << "\nBid: " << beginningBidCount[i] << "\nTricks Won: " << teamWinningBidCount[i] << endl;

		if(teamWinningBidCount[i] < beginningBidCount[i])
		{
			p_teamScore[i] = p_teamScore[i] - (beginningBidCount[i] * 10);
		}
		else if(teamWinningBidCount[i] >= beginningBidCount[i] && !p_Players[i]->getBlind())
		{
			p_teamScore[i] = p_teamScore[i] + (beginningBidCount[i] * 10);
		}
		else if(teamWinningBidCount[i] >= beginningBidCount[i] && p_Players[i]->getBlind())
		{
			p_teamScore[i] = p_teamScore[i] + (beginningBidCount[i] * 20);		
		}
		else
		{
			cout << ">>>>>ERROR:: WITH INPUTTING OF THE SCORE<<<<<" << endl;
		}
	}
}
/************************************************************************************/
/*****************************
NAME: setTableHand
FUNCTION: HAS A LINK TO A PLAYER AND THE CARD DESIRED TO PLAY 
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Game::setTableHand(Player* p, Card* cardPlayed)		
{
	p_TableCards[p->getSeat()] = cardPlayed;				//THIS LINKS IT TO THAT PLAYERS SEAT THAT THEY PLAYED THAT CARD
}
/************************************************************************************/
/*****************************
NAME: setSuperiorSuit
FUNCTION:  SETS THE SUPERIOR SUIT
TYPE: VOID
ARGUEMENTS: firstCardPlayed - SETS THE SUPERIOR SUIT OF THE SET
RETURNS: NONE
******************************/
void Game::setSuperiorSuit(string firstCardPlayed)			
{
	p_superiorSuit = firstCardPlayed;						
}
/************************************************************************************/
/*****************************
NAME: setPlayerPointer
FUNCTION:  SETS A PLAYER POINTER
TYPE: VOID
ARGUEMENTS: playerSeatPointedAt - HOLDS A PLAYERS SEAT POSITION
RETURNS: NONE
******************************/
void Game::setPlayerPointer(int playerSeatPointedAt)		
{
	p_Player = p_Players[playerSeatPointedAt];
}
/************************************************************************************/
/*****************************
NAME: setSpadePlayedThisSet
FUNCTION: HOLDS A TRUE OR FALSE STATEMENT OF IF A SPADE HAS BEEN PLAYED OR NOT IN A SET
TYPE: VOID
ARGUEMENTS: SpadePlayed - TRUE WHEN A PLAYER PLAYS A SPADE IN A SET
RETURNS: NONE
******************************
void Game::setSpadePlayedThisSet(bool SpadePlayed)			
{
	p_SpadePlayedThisSet = SpadePlayed;
}
/************************************************************************************/
/*****************************
NAME: setSpadePlayedThisHand
FUNCTION: HOLDS A TRUE OR FALSE STATEMENT OF IF A SPADE HAS BEEN PLAYED OR NOT IN A HAND
TYPE: VOID
ARGUEMENTS: SpadePlayed - TRUE WHEN A PLAYER PLAYS A SPADE IN A HAND
RETURNS: NONE
******************************/
void Game::setSpadePlayedThisHand(bool SpadePlayed)
{
	p_SpadePlayedThisHand = SpadePlayed;
}
/************************************************************************************/
/*****************************
NAME: printMyHand()
FUNCTION:  PRINTS THE CARDS OF A PLAYERS HAND
TYPE: BOOL
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void Game::printMyHand()
{
	cout << "*******************************PRINTING HAND**********************************" << endl;
	
			cout << "\nPlayer: " << 1 << " \nCards: " << endl;
			for(unsigned int k = 0; k < p_Players[0]->getHand().size();k++)
			{
				if(!p_Players[0]->getHand()[k]->getBeenPlayed() && p_Players[0]->getHand()[k]->getSuitOfCard() == "S")
				{
					p_Players[0]->getHand()[k]->print();				//PRINTS EACH PLAYERS HAND
				}
			}
			for(unsigned int k = 0; k < p_Players[0]->getHand().size();k++)
			{
				if(!p_Players[0]->getHand()[k]->getBeenPlayed() && p_Players[0]->getHand()[k]->getSuitOfCard() == "D")
				{
					p_Players[0]->getHand()[k]->print();				//PRINTS EACH PLAYERS HAND
				}
			}
			for(unsigned int k = 0; k < p_Players[0]->getHand().size();k++)
			{
				if(!p_Players[0]->getHand()[k]->getBeenPlayed() && p_Players[0]->getHand()[k]->getSuitOfCard() == "C")
				{
					p_Players[0]->getHand()[k]->print();				//PRINTS EACH PLAYERS HAND
				}
			}
			for(unsigned int k = 0; k < p_Players[0]->getHand().size();k++)
			{
				if(!p_Players[0]->getHand()[k]->getBeenPlayed() && p_Players[0]->getHand()[k]->getSuitOfCard() == "H")
				{
					p_Players[0]->getHand()[k]->print();				//PRINTS EACH PLAYERS HAND
				}
			}
			cout << "-----------------------------------------------------------------" << endl;
}
/*********************GETTERS FOR VARIABLES**************************************/
/************************************************************************************/
/*****************************
NAME: GetSuperiorSuit
FUNCTION:  RETURNS SUPERIOR SUIT IN A SET
TYPE: STRING
ARGUEMENTS: NONE
RETURNS: p_superiorSuit - HOLDS THE SUPERIOR SUIT OF A SET
******************************/
string Game::GetSuperiorSuit()
{
	return p_superiorSuit;
}
/************************************************************************************/
/*****************************
NAME: getPlayerTurn
FUNCTION:  RETURNS A PLAYER POINTER
TYPE: PLAYER*
ARGUEMENTS: NONE
RETURNS: p_Player - HOLDS A POINTER TO A PLAYER
******************************/
Player* Game::getPlayerTurn()
{
	return p_Player;
}
/************************************************************************************/
/*****************************
NAME: getWofSet
FUNCTION:  POINTS TO THE PLAYER WHO HAS WON THAT SET
TYPE: Player*
ARGUEMENTS: NONE
RETURNS: p_Player - POINTS TO A PLAYER THAT IS THE WINNER OF A SET PLAYED
******************************/
Player* Game::getWofSet()
{
	return p_Player;
}
/************************************************************************************/
/*****************************
NAME: getPlayerPointer
FUNCTION:  THIS WILL POINT TO A SPECIFIC PLAYER
TYPE: Player*
ARGUEMENTS: NONE
RETURNS: p_Player - ONE OF THE FOUR PLAYING PLAYERS SEATED
******************************/
Player* Game::getPlayerPointer()
{
	return p_Player;
}
/************************************************************************************/
/*****************************
NAME: getSpadePlayedThisSet
FUNCTION:  IF THIS IS TRUE A PLAYER CAN LEAD WITH A SPADE
TYPE: BOOL
ARGUEMENTS: NONE
RETURNS: p_SpadePlayed -	SET TRUE AFTER A PLAYER CUTS WITH A SPADE
******************************
bool Game::getSpadePlayedThisSet()
{
	return p_SpadePlayedThisSet;
}
************************************************************************************/
/*****************************
NAME: getSpadePlayed
FUNCTION:  IF THIS IS TRUE A PLAYER CAN LEAD WITH A SPADE
TYPE: BOOL
ARGUEMENTS: NONE
RETURNS: p_SpadePlayed -	SET TRUE AFTER A PLAYER CUTS WITH A SPADE
******************************/
bool Game::getSpadePlayedThisHand()
{
	return p_SpadePlayedThisHand;
}


