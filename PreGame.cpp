#include "stdafx.h"
#include "PreGame.h"

/************************************************************************************************************************
  THIS PREGAME CLASS CONSIST OF:
PUBLIC				 
	PreGame();							//CONSTRUCTOR
	~PreGame();							//DECONSTRUCTOR
	int getPointsToPlayUpTo();			//RETURNS THE GAME POINT LIMIT

PROTECTED:		
	void runPreGame();					//ASKS IF INSTRUCTIONS ARE DESIRED TO BE READ AND SETS GAME POINT LIMIT
	void setThePointsToPlayUpTo();		//TAKES IN A STRING AND MAKES SURE IT'S A VALID NUMBER
	string getInstructions(string read);//GIVES THE USER THE INSTRUCTIONS OF SPADES CREATED BY REXKID
	string getOutsideInstructions(string read);//GIVES THE USER THE INSTRUCTIONS OF SPADES CREATED BY REXKID	

PRIVATE:
	int p_numberOfTimesReadInstructions;//HOLDS COUNT FOR AMOUNT OF TIMES INSTRUCTIONS ARE READ
	int p_PlayUpTo;						//HOLDS THE VALUE FOR THE DESIRED WINNING SCORE 		
};
****************************************************************************************************************************/


/*****************************
NAME: PreGame()
FUNCTION: SETS INTEGER VALUES STARTS PROGRAM
TYPE: CONSTRUCTOR
ARGUEMENTS: VOID
RETURNS: NONE
******************************/
PreGame::PreGame(void)
{
	PreGame::p_numberOfTimesReadInstructions = 0;
	PreGame::p_PlayUpTo = 100;
	runPreGame();
}

/*****************************
NAME: PreGame()
FUNCTION: NONE
TYPE: DECONSTRUCTOR
ARGUEMENTS: VOID
RETURNS: NONE
******************************/
PreGame::~PreGame(void)
{
}

/*****************************
NAME: runPreGame()
FUNCTION: RUNS THE PROGRAM
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void PreGame::runPreGame()
{
	string read = "I love Andre Vernon.";
	string PlayUpToInput = "0";
	
	while((read != "N" && read != "NO"))
	{
		cout << "Hello and Welcome to Andre's version of spades." << endl << "Would you like to read the instructions? y-YES/n-NO" << endl;
		getline(cin, read);
		strupr((char *) read.c_str());	//MAKES USER INPUT ALL UPPERCASE
		getInstructions(read);			//GIVE THE RULES IF THE USER CHOSE "YES" 
	}
	system("cls");
	
	setThePointsToPlayUpTo();			//SETS THE GAME POINT LIMIT
	
	cout << "Good so you would like to play up to :" << p_PlayUpTo << endl;
	system("pause");
}

/*****************************
NAME: setThePointsToPlayUpTo()
FUNCTION: PROMPTS THE USER TO FIND AT HOW MANY POINTS WILL THE GAME END
TYPE: VOID
ARGUEMENTS: NONE
RETURNS: NONE
******************************/
void PreGame::setThePointsToPlayUpTo()
{
	string PlayUpToInput = "I love Andre.";
	
	cout << "What would you like to play up to? (100-500)" << endl;
	while(true)									//LOOP CONTINUES UNTIL IT HAS A NUMBER VALUE
	{		 
		getline(cin, PlayUpToInput);			//STORES USER INPUT INTO "PlayUpToInput"
		
		stringstream myStream(PlayUpToInput);	//SETS "string PlayUpToInput" EQUAL TO THE "int PlayUpTo"
		if(myStream >> p_PlayUpTo)				//THIS PASSES THE "stringstream mystream"
		{
			if(p_PlayUpTo > 99 && p_PlayUpTo < 501)
			{
				break;
			}
			else
			{
				cout << "Sorry that is an invalid number.  Please try again." << endl;
				system("pause");
				system("cls");
				cout << "What would you like to play up to? (100-500)" << endl;
			}
		}
	}
}

/*****************************
NAME: getInstructions
FUNCTION: RETRIEVES THE INSTRUCTIONS TO THE GAME
TYPE: STRING
ARGUEMENTS: STRING READ --HOLDS THE INPUT OF IF THE USER DESIRES TO READ THE INSTRUCTIONS 
RETURNS: READ --"NO" RETURNED THE USER WILL NOT BE ASKED TO VIEW THE INSTRUCTIONS
			 ---OTHER ANSWER WILL PROMPT USER IF THEY WANT THE INSTRUCTIONS AGAIN 
******************************/
string PreGame::getInstructions(string read)
{
	system("cls");									//CLEARS THE SCREEN
	if(read == "Y" || read == "YES")
	{
		if(p_numberOfTimesReadInstructions < 1)
		{
			cout << "Let Andre win.  That's it." << endl;	//----******SOME DAY HAVE THIS READ THE INSTRUCTION MANUAL REXKID(ME)CREATED*******
			p_numberOfTimesReadInstructions++;
		}
		else if(p_numberOfTimesReadInstructions == 1)
		{
			cout << "No really that's it.  Just let Andre win.  Seriously that's it." << endl;
		}
	}
	else if((read == "N" || read == "NO"))				//THE USER DECLINED TO READ THE INSTRUCTIONS
	{
		cout << "Well okay then. Just type EXIT twice when you want to quit.  Good Luck!" << endl;	
	}
	else		//THE USER TYPED SOMETHING ASIDE FROM Y OR N
	{
		cerr << "You input an improper answer.  Please select Y for Yes and N for No\n" << endl; 		
	}
	system("pause");
	system("cls");
	return read;
}
/*****************************
NAME: getOutsideInstructions
FUNCTION: RETRIEVES THE INSTRUCTIONS TO THE GAME
TYPE: STRING
ARGUEMENTS: STRING READ --HOLDS THE INPUT OF IF THE USER DESIRES TO READ THE INSTRUCTIONS 
RETURNS: READ --"NO" RETURNED THE USER WILL NOT BE ASKED TO VIEW THE INSTRUCTIONS
			 ---OTHER ANSWER WILL PROMPT USER IF THEY WANT THE INSTRUCTIONS AGAIN 
******************************/
string getOutsideInstructions(string read)//GIVES THE USER THE INSTRUCTIONS OF SPADES CREATED BY REXKID	
{
	string i = "0";
	return i;
}

/*****************************
NAME: getPointsToPlayUpTo
FUNCTION: RETURNS THE NEEDED POINTS TO WIN
TYPE: INT
ARGUEMENTS: NONE
RETURNS: p_PlayUpTo --RETURNS THE NUMBER THAT IS NEEDED TO WIN
******************************/
int PreGame::getPointsToPlayUpTo(){return p_PlayUpTo;}

