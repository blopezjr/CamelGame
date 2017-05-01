/*******************************************************************************
* Author: Baltazar Lopez Jr.                                                   *
* Created: 30 April 2017                                                       *
* Class: ITSE 2421 - Object Oriented Programming                               *
* Instructor: Prof Welch William                                               *
* Problem description:                                                         *
* Camel Game                                                                   *
* This program is a game where you ride a camel across the desert while being  *
* chased. You need to manage your thirst, how tired the camel is, and how far  *
* ahaead of the natives you are.                                               *
*                                                                              *
* Todo - Summary of Modifications:                                             *
* 04/30/2017 Analysis and algorithm                                            *
* 04/30/2017-Code baseline - complete main() and all input validation functions*
* 04/30/2017-Simplification, Style, & Review                                   *
* 04/30/2017-Testing                                                           *
* 04/30/2017-Testing & Screenshots                                             *
*                                                                              *
* Lessons learned:                                                             *
* (1) To create a back up. Back up! Back up!                                   *
* (2) Menu's are awesome. It made it simple to place all commands and functions*
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;
/*******************************************************************************
*                                Function prototype                            *
*******************************************************************************/
void mainMenu(char& choice);
void nativeRandom(int& native);
void fullRandom(int& travel);
void moderateRandom(int& travel);
bool checkThirst(bool done, int thirst);
bool checkCamel(bool done, int camel);
bool checkNative(bool done, int travel, int native);
int oasis(int thirst, int camel, int drink);
/*******************************************************************************
*                                     Main                                     *
*******************************************************************************/
int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);
	char choice;
	bool done = false;
	int travel = 0;
	int thirst = 0;
	int camel = 0;
	int native = -20;
	int drink = 10;

	cout << " Welcome to Camel!" << endl;
	cout << "You have stolen a camel to make your way across the great Mobi desert." << endl;
	cout << "The natives want their camel back and are chasing you down! Survive your" << endl;
	cout << " desert trek and out run the natives." << endl;

	while(done == false)
	{
		mainMenu(choice);
		choice = toupper(choice);
		switch (choice)
		{
		case 'A'://Drink from your canteen
			if (drink >= 0)
			{
				--drink;
				thirst = 0;
			}
			else if (drink < 0)
			{
				cout << "You have no water" << endl;
			}

			break;
		case 'B'://Ahead moderate speed
			moderateRandom(travel);
			done = checkThirst(done, thirst);
			done = checkCamel(done, camel);
			done = checkNative(done, travel, native);
			oasis(thirst, camel, drink);
			++thirst;
			++camel;
			nativeRandom(native);
			cout << "Miles traveled: " << travel << endl;
			break;
		case 'C'://Ahead full speed.
			fullRandom(travel);
			done = checkThirst(done, thirst);
			done = checkCamel(done, camel);
			done = checkNative(done, travel, native);
			oasis(thirst, camel, drink);
			++thirst;
			++camel;
			nativeRandom(native);
			cout << "Miles traveled: " << travel << endl;
			break;
		case 'D'://Stop for the night
			done = checkThirst(done, thirst);
			done = checkNative(done, travel, native);
			camel = 0; 
			cout << "Camel is happy." << endl;
			nativeRandom(native);
			cout << "The natives are " << travel - native << " miles behind you." << endl;
			break;
		case 'E': //Check status
			cout << "Miles traveled: " << travel << endl;
			cout << "Drinks in canteen: " << drink << endl;
			cout << "The natives are " << travel - native << " miles behind you." << endl;
			break;
		case 'Q': 
			done = true;
			break;
		}
	}

    return 0;
}
/******************************************************************************
*                                void mainMenu                                *
* This function performs a menu for the user to select the different choices  *
* that are avalable.                                                          *
******************************************************************************/
	void mainMenu(char& choice)
	{
		cout << "---------------------------" << endl;
		cout << "A. Drink from your canteen." << endl;
		cout << "B. Ahead moderate speed." << endl;
		cout << "C. Ahead full speed." << endl;
		cout << "D. Stop for the night." << endl;
		cout << "E. Status check." << endl;
		cout << "Q. Quit" << endl << endl;
		cin >> choice;
	}
	/******************************************************************************
	*                                void nativeRandom                            *
	* This function performs a random number for native speed between 7-14.       *
	******************************************************************************/
	void nativeRandom(int& native)
	{
		int maxValue = 14;
		int minValue = 7;
		int nR = 0;
		nR = rand() % maxValue + minValue;
		native += nR;
	}
	/******************************************************************************
	*                                void fullRandom                              *
	* This function performs a random number travel at full speed between 10-20.  *
	******************************************************************************/
	void fullRandom(int& travel)
	{
		int maxValue = 20;
		int minValue = 10;
		int fS = 0;
		fS = rand() % maxValue + minValue;
		travel += fS;
	}
	/******************************************************************************
	*                                void moderateRandom                          *
	* This function performs a random number travel at moderate speed between 5-12*
	******************************************************************************/
	void moderateRandom(int& travel)
	{
		int maxValue = 12;
		int minValue = 5;
		int mS = 0;
		mS = rand() % maxValue + minValue;
		travel += mS;
	}
	/******************************************************************************
	*                                bool checkThirst                             *
	* This function performs a check thirst level. Warning 4-6 and Fatal above 6. *
	******************************************************************************/
	bool checkThirst(bool done, int thirst)
	{
		if ((thirst == 4) || (thirst == 5) || (thirst == 6))
		{
			cout << "You are thirsty." << endl;
			done = false;
		}
		if (thirst > 6)
		{
			cout << "You died of thirst." << endl;
			done = true;
		}
		return done;
	}
	/******************************************************************************
	*                                bool checkCamel                              *
	* This function performs check on camel. Warning 5-7. Fatal above 8.          *
	******************************************************************************/
	bool checkCamel(bool done, int camel)
	{
		if ((camel == 5) || (camel == 6) || (camel == 7))
		{
			cout << "Your camel is tired." << endl;
			done = false;
		}
		if (camel == 8)
		{
			cout << "Your camel is dead." << endl;
			done = true;
		}
		return done;
	}
	/******************************************************************************
	*                                bool checkNative                             *
	* This function performs distance. Warning less than 15. Fatal at 0. Also     *
	* check for the win.                                                          *
	******************************************************************************/
	bool checkNative(bool done, int travel, int native)
	{
		int distance;	
			distance = travel - native;
			
			if (native >= travel)
			{
				cout << "Game over, Natives has caught you." << endl;
				done = true;
			}
			else if (distance <= 15)
			{
				cout << "The natives are getting close!" << endl;
				done = false;
			}
			if (travel >= 200)
			{
				cout << "You cross the desert, You won!" << endl;
				done = true;
			}
		return done;
	}
	/******************************************************************************
	*                                   int oasis                                 *
	* This function performs integer oasis. If user gets lucky drink, thirst, and *
	* camel tiredness resets.                                                     *
	******************************************************************************/
	int oasis(int thirst, int camel, int drink)
	{
		int maxValue = 20;
		int minValue = 1;
		int lO = 0;
		lO = rand() % maxValue + minValue;
		if (lO == 10)
		{
			cout << "You found an oasis." << endl;
			drink = 10;
			thirst = 0;
			camel = 0;
		}
		return false;
	}
