#pragma once

/************************
	Andre Vernon
	Spades Program
	GAME HEADER FILE
************************/

#ifndef _GAME_H
#define _GAME_H

#include "Deck.h"
#include "cpu.h"
#include "Human.h"
#include "Player.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Game
{
public:
	Game();											//DEFAULT CONSTRUCTOR
	Game(int WinningScore);							//TAKES IN AMOUNT OF PLAYERS INVOLVED AND WHAT GAME ENDS AT
	~Game();										//DECONSTRUCTOR

	bool GameOver();								//HOLDS THE CONDITION IF SCORE IS REACH 
	bool PlayableCardCheck();						//RETURNS TRUE IF CARDS NEED TO BE REDEALT	
	bool getBlind();								//RETURNS TRUE IF ABLE TO BID BLIND
	bool getCanPlayOutOfSuit(Player* p, Card* cardPlayed);	//RETURNS IF THE PLAYER IS ALLOWED TO NOT PLAY LEADING SUIT	
	bool getSpadePlayedThisHand();					//RETURNS TRUE IF SOMEONE HAS CUT WITH A SPADE


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
};
#endif