/********************************
Author: Luke Brewbaker
Date: 5/28/15
Modified: 6/9/15
File: main.cpp

Overview: This is the final project.  It is a game to traverse though a haunted abandoned house.  The user must complete a task and return the plunger to the graveyard.


Input: User inputs directions to travel and actions to take.


Output: will print the room text to the console and also prompt user for certain interactions in the rooms.


*******************************/

#include <string>
#include <iostream>
#include "character.cpp"

using namespace std;
struct Room{
        Room *north;
        Room *south;
        Room *east;
        Room *west;
        string text;

        Room(Room *n, Room *s, Room *e, Room *w, string t){
                north = n;
                south = s;
                east = e;
                west = w;
                text = t;
        }
};


int moving (int direction){


//ask the user where they want to go.
    cout << "Which direction would you like to go in? " << endl;
    cout << "1. North " << endl;
    cout << "2. South " << endl;
    cout << "3. East " << endl;
    cout << "4. West " << endl;
    cin >> direction;

    //error checking user input
    if(direction < 1 || direction > 4){
        cout << "I'm sorry, but your choice was invalid. Please choose again. ";
        cin >> direction;
    }


    return direction;

}
bool plunger(){

    int pickup;
    cout << "Do you wish to pick up the object? " << endl;
    cout << "1. Yes ";
    cout << "2. No ";
    cin >> pickup;

    if (pickup == 1){
        cout << "You pick up the item, come to find out it is a shiny Golden Plunger with the initials 'B.t.P' ";
        return true;
    }

    else if (pickup == 2){
        return false;
    }
}

void readnote(){

    int letter;
    cout << "There is a letter on the wall.  Do you wish to read it? " << endl;
    cout << "1. Yes ";
    cout << "2. No " ;
    cin >> letter;


    if (letter == 1){
        cout << "Foolhardy Adventurer? Challenge your self in the Gazebo! \n" << endl;
    }

    else if(letter == 2){
        cout << "A whisper reaches out 'fool' \n" << endl;
    }

}

bool gazfight(Character *c1, Character *c2){

    cout << "You've failed to head the warning.  You enter the Gazebo and the Duck of Doom attacks! Prepare yourself! \n " << endl;
    c2->attack(c1, c2);

    //if the player is defeated by the duck of doom.
    if(c2->death()){

    cout << "You've fallen to the Duck of Doom.  Your life has ended. \n" << endl;
        return true;
    }

    else if (!c2->death()){
        cout << "You have slain the Duck!  You may continue to find the exit.\n " << endl;
        return false;
    }

}

bool plungerreturn(bool specialitem){

    cout << "On the headstone you see a name: 'Bill the Plumber'.  There is a carving of a middle aged man with a beer gut and a holy just wide enough for the plunger to fit into it. \n" << endl;


    if (specialitem == true){

        int plungerput;
        cout << "Do you wish to place the plunger inside the hole? " << endl;
        cout << "1. Yes    2. No ";
        cin >> plungerput;

        if (plungerput == 1){
            cout << "You place the plunger in the hole, and the glow disappears and only a whisper remains 'Thank you, please exit East. ";
            return true;
        }

        else if (plungerput == 2){
            cout << "Fool! " << endl;
            return false;
        }


    }

    else if (specialitem == false){

        cout << "You fool!  I need my plunger for my spirit to rest in peace.  How could you be so daft? ";
        cout << "Return to where I have hidden it in the bathroom, bring it back, and you'll be allowed to leave.  But make haste, and don't delay! ";
        cout << "The house does not take kindly to strangers ";
        return false;
    }



}

void exitcheck(bool specialitem){


    if(specialitem){
        cout << "You've carried the golden plunger to Bill the Plumber. As you escape a loud bell tolls and the house you were just trapped in disappears and you find yourself asleep in your own bed.\n" << endl;
    }

    else if(!specialitem){
        cout << "You have not completed your task.  Perhaps if there was something....shiny? " << endl;

    }




}

int main(){

//setup player and enemy class
Player player;
Duck duck;
Character *c2 = &player;
Character *c1 = &duck;


//set up the links to the rooms and create the entry text
	Room *Foyer, *LivingRoom, *Bedroom, *Dungeon, *DiningRoom, *Garden, *Gazebo, *Cemetery, *Closet, *Bathroom, *Exit;
	string foy = "You are currently in the foyer.\n ";
	string living = "You are currently in the living room. There is an entrance to the garden to the south, or the dining room straight ahead to the east. \n";
	string bedr = "You are currently in the bedroom. There is an unmade bed and a bathroom on the far wall.\n ";
	string dung = "You are currently in the dungeon. Chose your next step carefully! \n";
	string dining = "You are currently in the dining room. \n";
	string gard = "You are currently in the garden. It is full of bright and vibrant flowers, and the stench of death coming from the south.  \n";
	string gaz = "You enter the Gazebo. QUACK!!!!!!! \n";
	string bath = "You are in the bathroom, there is a shiny object on the floor near the toilet.  It is enthralling you. You see now other exit but where you just came, or is there? \n";
	string c = "You enter the cemetery. See a gravestone emanating a golden glow.  The exit is to the east. \n";
	string ex = "You have found the exit. ";
	string coatc = "You've entered the coat closet. There seems to be a breeze coming from behind the coats.  Dare investigate? Head South\n";


//create the rooms
	Foyer = new Room(NULL, NULL, NULL, NULL, foy);
    Exit = new Room(NULL, NULL, NULL, NULL, ex);
	LivingRoom = new Room(Foyer, Garden, DiningRoom, Dungeon, living);
    DiningRoom = new Room(Bedroom, Gazebo, LivingRoom, NULL, dining);
    Garden = new Room(LivingRoom, Cemetery, NULL, Gazebo, gard);
    Bedroom = new Room(Bathroom, NULL, NULL, NULL, bedr);
	Bathroom = new Room(Dungeon, Bedroom, NULL, NULL, bath);
    Dungeon = new Room(NULL, NULL, LivingRoom,  NULL, dung);
    Closet = new Room(NULL, Dungeon, Foyer, NULL, coatc);
    Gazebo = new Room(DiningRoom, NULL, NULL, Garden, gaz);
	Cemetery = new Room(Garden, Dungeon, Exit, NULL, c);



    //add pointers to rooms
	Foyer->south = LivingRoom;//EXIT
	Foyer->east = Closet;

    LivingRoom->east = DiningRoom; //PLUNGER
    LivingRoom->west = Dungeon;
    LivingRoom->south = Garden;  //EXIT

    DiningRoom->south = Gazebo;
    DiningRoom->north = Bedroom; //PLUNGER
    DiningRoom->west = LivingRoom;

	Bedroom->north = Bathroom;
    Bedroom->south = DiningRoom; //PLUNGER

	Bathroom->south = Bedroom;
	Bathroom->north = Dungeon;

    Gazebo->east = Garden;
    Gazebo->north = DiningRoom;

    Garden->east = Gazebo;
	Garden->south = Cemetery; //EXIT

	Cemetery->east = Exit; //EXIT
	Cemetery->north = Garden;
	Cemetery->south = Dungeon;

	Closet->south = Dungeon;
	Closet->east = Foyer;

    Dungeon->south = Foyer;



        //set the current room to the foyer and initialize the number of doors the user has tried to 0, initialize other variables.
        Room *current;
        Room *next = Foyer;
        int doorsTried = 0;
        bool specialitem = false;
        bool specialreturn = false;
        int noteread = 0;
        int play;

        //prompt user to start game
        cout << "You come across a small abandoned house.  You are captivated by the shed, and have an overwhelming desire to admire and explore it.  Do you give in to your undying urge? " << endl;
        cout << "1. Yes ";
        cout << "2. No " << endl;
        cin >> play;

        if (play == 1){

                cout << "Upon entering the house there is a sign on the wall.  The sign reads: 'Find the shiny tool of plumbing, and return it to the rightful owner and be relieved of this curse.'.  ";
                cout << "You take time to ponder the meaning, and begin your search.  As you step forward, the door behind you is sealed shut. \n" << endl;

            while(next != Exit){


                    current = next; //change the pointer for the current room.
                    int direction;

                    //displays the room text with potential hints.
                    string roomtext = current->text;
                    cout << roomtext << endl;

                    /********** Secret Object pick-up in the Bathroom *************/
                    if (current == Bathroom){

                            //should prevent additional dialogues from popping up once user has the secret item
                            if (specialitem == false){
                                specialitem = plunger();
                            }

                    }

                    /*********** Read the note on the wall *******/
                    if (current == LivingRoom){
                            if (noteread == 0){
                                readnote();
                                noteread++;
                            }
                    }

                    /********* Gazebo Fight ******************/
                    if (current == Gazebo){
                        bool death = false;
                        death = gazfight(c1, c2);

                        //ends program if character dies.
                        if(death == true){
                            return 0;
                        }
                    }

                    /********* Plunger Return ******************/
                    if (current == Cemetery){

                        specialreturn = plungerreturn(specialitem);

                    }

                    /******* Move Function **********/
                    direction = moving(direction);
                    //move nodes with the directions
                    if(direction == 1)
                            next = current->north;
                    if(direction == 2)
                            next = current->south;
                    if(direction == 3)
                            next = current->east;
                    if(direction == 4)
                            next = current->east;

                    //if there is no door where user chooses
                    if(next == NULL){
                            cout << "There is no door there.\n";
                            next = current;
                    }

                    doorsTried++;
                    if (doorsTried > 17){
                        cout << "You have run out of time. A poison arrow darts out from the wall and enters your chest.  You have died." << endl;
                        break;
                    }

            }

        if (next == Exit){
            cout << Exit->text << endl;
            exitcheck(specialreturn);
        }


    }


       return 0;

}

