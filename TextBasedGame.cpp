// TextBasedGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
//Below are all the functions used in this program some are called inside of fucntions like hp and attack  while others are called in the main function for efficeny.
int showFriezaHp(int Friezahp, int Playerattack);
int showPlayerHp(int Playerhp, int FriezaAttack);
int FriezaAttack = 15;
int Playerhp = 100;
int Playerattack = 20;
int Friezahp = 90;
int FriezaHp;
int special();


int FriezaBattle() {
	int Playerhp = 100, Friezayhp = 90, Playerattack = 20, FirezaAttack = 15;
	int hitFrieza;
	//while FriezaBattle is true prompt the player with choice to attack or not 
	while (true) {
		cout << "Hit Frieza?\n(1) Yes\n(2) No" << endl;
		cin >> hitFrieza; // takes input player chose after being presented with choices above

		if (hitFrieza == 1) { //checks if player has input option 1 to hit fireza
			Friezahp = showFriezaHp(Friezahp, Playerattack); // if player has hit frieza displays friezas hp by using the values already set up and using a method in ShowFriezaHP
			Playerhp = showPlayerHp(Playerhp, FirezaAttack); //same as above
			cout << "You hit Frieza with a special attack! "  << endl;
			cout << "Frieza now has " << Friezahp << "HP left." << endl; // displays friezas hp after attack by grabbing value returned in FriezaHP
			if (Friezahp <= 0) {
				cout << "You've killed the Frieza! Nice Job!" << endl; //If Friezas Hp hits 0 or less than 0 displays victory message and breaks loops
				break;
			}
			else if (Friezahp > 0) {
				cout << "Frieza hit you back look out!." << endl;  // If Friezahp is more than 0 displays warning message and updates players hp using value returned from ShowPlayerHP
				cout << "You now have " << Playerhp << "HP left." << endl;
			}
		}
		else if (hitFrieza == 2) { //Checks if player has inputed option 2 to not hit frieza
			FriezaHp = showFriezaHp(Friezahp, Playerattack); //shows frieza hp after not being attack showing value stored at beging of program
			Playerhp = showPlayerHp(Playerhp, FriezaAttack); //updates players hp using new value returned by ShowPlayerHP
			cout << "You have chosen not to hit Frieza?Why?" << endl;
			cout << "Frieza hit you after you chose not to fight!" << endl;
			cout << "You now have " << Playerhp << "HP left." << endl; // Displays new value returned from ShowPlayerHP
		}
		else { 
			cout << "Thats not option. Sorry!" << endl;  
			// used to return back to first if statment if player selects an input that is not a option.
			return FriezaBattle();
		}
	}
	while (Playerhp > 0 && Friezahp > 0); //Lets program know fight can only happen and continue if both health values are greater than 0, continuing to loop while health is above 0
}


int showPlayerHp(int Playerhp, int FriezaAttack) { //grabs the values from Playerhp and Friezaattack to use in function
	Playerhp = Playerhp - FriezaAttack; // updates Playerhp after being attacked by subtracting friezaattack from PlayerHp
	return Playerhp; //returns new value calculated by fucntion and assigns it as players new health
}
int showFriezaHp(int Friezahp, int Playerattack) { //grabs the values from Friezahp and Playerattack
	Friezahp = Friezahp - Playerattack; //updates Friezahp after being attacked by subtracting Playerattack from FriezaHp
	return Friezahp; //returns new value calculated by function and assigns it as players new health
}

int main()
{
	string Race; //Declares race as a string to be used

	bool success; // sets up bool to dertimine if race entered is successful using a true or false

	cout << "Welcome to the Game!";
	do
	{
		cout << "\nWhat is your race? Sayian or Human?";
		cin >> Race; // asks player what race they are and displays 2 options and then lets player input race and will hold the input as new string value

		if (Race == "Sayian") //checks if race equals the word Sayian
		{
			cout << "\nWoah you're a " +  Race;
			cout << "\nYou're the same as Goku!";
			success = true; // lets program know that this string is the right string and is the succesful choice/value

		}

		else if (Race == "Human") //checks if race is human instead of sayian using an else if to set human as a second option
		{
			cout << "Woah you're a " + Race;
			success = true; // lets program know that this string is the right string and is the succesful choice/value
		}

		else
		{
			cout << "\nThat Sounds made up lets try again!";
			success = false; //else is used to check if player enters any word other than the two stated above, if so then updates program to know success is fals and can not progress till picking the two options
		}

	} while (!success); //loops until player enters word that is true to success

	{
		int PowerLevel; //stores powerlevel value as a whole number using a integer
		cout << "Enter your power level: ";
		cin >> PowerLevel; // player inputs PowerLevel and number inputed is stored as the value for PowerLevel

		if (PowerLevel >= 9001) // Checks if powerlevel value is greater than or equal too 9001 using the value the player entered 
		{
			cout << "ITS OVER 9000!!!\n";
			
		}
		else if (PowerLevel >= 5000) // uses else if to check if powerlevel is less than or equal too 5000 prompting a second dialouge option for the player.
		{
			cout << "Hey your pretty powerful!\n";
			
		}
		else
		{
			cout << "Wow even Yamcha is stronger than that. Maybe this game isn't for you\n"; // uses else to check if players powerlevel is below 5000 ending the game if so as they are to weak to progress.
			
		}
		
	}
	int special();
	cout << "Choose a special attack\n\n";  //presents the player with options for a speical attack using whole numbers as the way to choose
	cout << "1 - Kamehameha\n";
	cout << "2 - Galick Gun\n";
	cout << "3 - Special Beam Cannon\n\n";

	int choice; //stores the choice as a integer
	cout << "Choice: ";
	cin >> choice; //lets the player input there choice and stores the value of the number entered.

	switch (choice) //uses a switch to 
	{
	case 1:
		cout << "Kamehameha! Gokus signature move! Great choice!\n";
		break;
	case 2:
		cout << "Galick Gun hey. Wonder if Vegeta will be happy about you using that?\n";
		break;
	case 3:
		cout << "Speical Beam Cannon! Mr Piccolo taught me that one himself!\n";
		break;
	default:
		cout << "I don't think I've heard of that before? Can't be that good\n";
	}
	

	{
		const int MAX_FIGHT = 3;
		string fight[MAX_FIGHT];

		int numItems = 0;
		fight[numItems++] = "Fight 1";
		fight[numItems++] = "Fight 2";
		fight[numItems++] = "Fight 3";

		cout << "Your fights:\n";
		for (int i = 0; i < numItems; ++i)
		{
			cout << fight[i] << endl;
		}

		cout << "\nLets do fight 1!";
		fight[0] = "fight 1";
		cout << "\n Your Fight choices:\n";
		for (int i = 1; i < numItems; ++i)
		{
			cout << fight[i] << endl;
		}
	}

	int showFriezaHp(int Friezahp, int Playerattack); // function is called down here main using the code written above where the function is defined

	int showPlayerHp(int Playerhp, int FriezaAttack); //function is called down here in main using the code written above where the function is defined

	FriezaBattle(); //function is called in main using code written above.

	return 0; //returns to 0 ending the programm once and for all



}

