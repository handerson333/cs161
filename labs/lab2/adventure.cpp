#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ogre_donkey();
int leave_stay_swamp();
int castle_farfaraway(); 
int fightdrag_runaway();
int eat_pillage();
int death_live();
int stay_saveprincess();
int chokedie_livehappy();
int fight_befriend_ogre();



int main(){
	cout << "Welcome to your adventure!" << endl << endl;
	ogre_donkey();

	cout << "\n\nThank you for playing!" << endl;
	return 0;
}

//do you want to be an ogre or donkey?
int ogre_donkey(){
	int input;
	cout << "Are you an Ogre(1) or a Donkey?(2)" << endl;
	cin >> input;//get user input
	if (input == 1)
	{
		cout << "\nYou're an Ogre!" << endl;
		leave_stay_swamp();
	}
	else if (input == 2)
	{
		cout << "\nYou're a Donkey!" << endl;
		fight_befriend_ogre();
	}
	else
	{
		cout << "you have died of indecision" << endl;
	}

	return 0;
}
//OGRE
//leave or stay in the swamp?
int leave_stay_swamp(){
	int input;
	cout << "You live in a swamp! Would you like to leave(1) or stay here?(2)" << endl;
	cin >> input;//get user input
	if (input == 1)
	{
		cout << "\nWell then let's go already!\n" << endl;
		castle_farfaraway();
	}
	else if (input == 2)
	{
		cout << "\nYou're right, why go far away when we can stay home?\n" << endl;
		eat_pillage();
	}
	else
	{
		cout << "\nyou have died of indecision" << endl;
	}

	return 0;
}

//go to a castle far far away or princess castle
int castle_farfaraway(){
	int input;
	cout << "Shall we go to a castle we hear has a lovely princess(1)? or go to a land far far away(2)?" << endl;	
	cin >> input;//get user input
	if (input == 1)
	{
		cout << "\nPrincesses are pretty bomb, let's go!\n" << endl;
		fightdrag_runaway();
	}
	else if (input == 2)
	{
		cout << "\nWho needs a princess anyways, road trip!" << endl;
		cout << "\nYou enjoyed a nice trip and decided to stay in far far away, despite the rude neighbors.\n" << endl;
	}
	else
	{
		cout << "you have died of indecision" << endl;
	}

	return 0;
}
//fight dragon 30%chance you defeat, 70% chance you die.
int fightdrag_runaway(){
	int input;
	cout << "You've made it to the castle and as soon as you enter its vast gates you are attacked by a dragon.\n Will you bravely fight this beast? (1) or run with your tail between your legs? (2)" << endl;
	srand(time(NULL));//seed time for rng
	int rng = rand() % 100;//rng = 0-99
	cin >> input;//get user input
	if (input == 1){

		if (rng >= 70){
			cout << "\nyou've defeated the mighty dragon! Your name will forever be sung in legends across the land! rng = " << rng << "\n" << endl;
		}
		else{
			cout << "\nUnfortunately you dodged right when you should have parried left, the dragon swallows you in one chomp. rng = " << rng << " \n" << endl;
		}
	}
	else if (input == 2){
		if (rng >= 50){
			cout << "\nYou managed to survive with your life, Better just go home then! rng = " << rng << "\n" << endl;
		}
		else{
			cout << "\nUnfortunately you dodged right when you should have parried left, the dragon swallows you in one chomp. \n" << endl;
		}
	}
	else
	{
		cout << "you have died of indecision" << endl;
	}


	return 0;
}
//eat leftovers or go pillage nearby? eating has a 30% death rate, pillaging is a 50-50 death rate
int eat_pillage(){
	int input;
	cout << "What do you want to do while here at home? eat leftovers (1), or go pillage some nearby villagers (2)?" << endl;
	cin >> input;//get user input
	srand(time(NULL));//seed time for rng
	int rng = rand() % 100;//rng = 0-99
	if (input == 1){
		cout << "\nYou eat your leftover bird and start choking on the bones!!" << endl;
		if (rng >= 70){
			cout << "\nunfortunately you have choked and suffocated to death, maybe you should have gone out :( rng = " << rng << "\n" << endl;
		}
		else{
			cout << "\nYou cough up the dastardly bones and live another day... rng = " << rng << " \n" << endl;
		}
	}
	else if (input == 2){
		if (rng >= 50){
			cout << "\nunfortunately pillaging is tough work and you are pitchforked to death. rng = " << rng << "\n" << endl;
		}
		else{
			cout << "\nYou defeat all the pesky villagers and despite a couple scrapes and bruises make it out with plenty of spoils! rng = " << rng << "\n" << endl;
		}

	}
	else
	{
		cout << "you have died of indecision" << endl;
	}


	return 0;
}
//DONKEY
//fight or befriend the ogre? fight is a 90% death rate, befriend is a 50-50 death rate
int fight_befriend_ogre(){
	int input;
	cout << "you happen upon a swamp where there is a dreadful ogre. fight (1) or befriend (2) the ogre?" << endl;
	cin >> input; //get user input
	srand(time(NULL)); // seed time for rng
	int rng = rand() % 100;// turn rng into 0-99
	if (input == 1){
		if (rng > 90){
			cout << "\nyou have defeated the dreadful ogre!  Your name will live on in the legends and are decorated as the best donkey the world has ever seen. rng = "<< rng << endl << endl;
		}
		else{
			cout << "\nyou died... what did you expect? you're a donkey and he was an OGRE!!! rng = " << rng << endl << endl;
		}

	}
	else if (input == 2){

		if (rng > 50){
			cout << "\nyou have befriended the dreadful ogre! He may be mean but he is the most loyal friend you will ever have. You two live your days together causing trouble. rng = "<< rng << endl << endl;
		}
		else{
			cout << "\nyou died... what did you expect? you're a donkey and he was an OGRE, it's not like he enjoys company!!! rng = " << rng << endl << endl;
		}
	}
	return 0;
}

