/********************************
Author: Luke Brewbaker
Date: 5/1/15
Modified: 5/9/15
File: assignment3.cpp

Overview: Assignment 3 is a console based RPG game.


Input: Stuff


Output: Stuff


*******************************/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;


class Character
    {
        public:
        double attackpower;
        double hitpoints;
        double defensep;
        double armorp;

        Character() {};

        virtual void attack(Character* c1, Character* c2){}
        virtual void defense(){}
        virtual void sethealth(double){}
        virtual void setap(){}
        virtual void setd(){}


        bool death(){
            if(hitpoints <= 0){
                return true;
            }

            else
                return false;
        }

        double health(){
            return hitpoints;
        }

        double getap(){
            return attackpower;
        }

        double getd(){
            return defensep;
        }
        double getarm(){
            return armorp;
        }
    };

/*****************************************************


Barbarian Class

*****************************************************/
    class Barbarian : public Character
    {

    public:
        Barbarian(){

        hitpoints = 12;
        armorp = 0;

        }

        void sethealth(double hp){
            hitpoints = hp;
        }

        void setap(){
            attackpower = ((rand()%6) + (rand()%6));
        }

        void setd(){
            defensep = rand()%6;
        }
        void attack(Character* c1, Character* c2){

            double tdmg, hp, arm, tots; //used in calculating the damage
            c1->setd(); //defense roll
            c2->setap(); //attack rol

            hp = c1->health(); //set health to current health
            tdmg = (c2->getap() - c1->getd()); //set tdmg to attack power - defense
            tots = tdmg - c1->getarm(); //set tots to tdmg - armor

            if (tots <= 0){

                cout << "\n**no damage dealt**\n" << endl;

            }

            else{

                hp -= tots; //suptractors total damage, which is ((attackpower - defense power) - armor)
                cout << "\nYou deal " << tots << "total damage."  <<endl;
                c1->sethealth(hp);

            }

            //enemy will return fire!
            c1->attack(c2, c1);
            cout << "You have " << c2->health() << " health remaining " <<endl;


            //check for death
            if (c1->death() == true) {
                cout << "You have slain the enemy!" << endl;

            }

            else if (c2->death() == true){
                cout << "You have perished in glorious combat!" << endl;

            }

            else if (c1->death() == false){
            cout << "The enemy has " << c1->health() << " health remaining." << endl;


            }
        }

    };

/*****************************************************


Goblin Class

*****************************************************/

    class Goblin : public Character
    {

    public:
        Goblin(){

        hitpoints = 8;
        armorp = 3;


        }

        void sethealth(double hp){
            hitpoints = hp;
        }
        void setap(){
            attackpower = ((rand()%6) + (rand()%6));
        }

        void setd(){
            defensep = rand()%6;
        }

        void attack(Character* c1, Character* c2){


            double tdmg, hp, arm, tots;
            c1->setd(); //defense roll
            c2->setap(); //attack roll


            /***********  Achilles damage  ***************

            because the c2 pointer is the attacker, I set the attack power
            of the defender in half if the goblin rolls a 12


            ********************************************/

            if (c2->getap() == 12){
                double achillesdmg = (c1->getap() / 2);
                hp = c1->health(); //set health to current health
                tdmg = (achillesdmg - c1->getd()); //set tdmg to attack power - defense
                tots = tdmg - c1->getarm(); //set tots to tdmg - armor
            }

            else{

            hp = c1->health(); //set health to current health
            tdmg = (c2->getap() - c1->getd()); //set tdmg to attack power - defense
            tots = tdmg - c1->getarm(); //set tots to tdmg - armor

            }

            if (tots <= 0){

                cout << "\n**no damage dealt**\n" << endl;

            }

            else{

                hp -= tots;
                cout << "\nYou deal " << tots << "total damage."  <<endl;
                c1->sethealth(hp);

            }

            //enemy will return fire!
            c1->attack(c2, c1);
            cout << "You have " << c2->health() << " health remaining " <<endl;


            //check for death
            if (c1->death() == true) {
                cout << "You have slain the enemy!" << endl;

            }

            else if (c2->death() == true){
                cout << "You have perished in glorious combat!" << endl;

            }

            else if (c1->death() == false){
            cout << "The enemy has " << c1->health() << " health remaining." << endl;


            }
        }


    };

/*****************************************************


Reptile Class

*****************************************************/

    class Reptile : public Character
    {

    public:
        Reptile(){

        hitpoints = 18;
        armorp = 7;

        }

        void sethealth(double hp){
            hitpoints = hp;
        }

        void setap(){
            attackpower = ((rand()%6) + (rand()%6) + (rand()%6));
        }

        void setd(){
            defensep = rand()%6;
        }

        void attack(Character* c1, Character* c2){
            double tdmg, hp, arm, tots;
            c1->setd(); //defense roll
            c2->setap(); //attack rol

            hp = c1->health(); //set health to current health
            tdmg = (c2->getap() - c1->getd()); //set tdmg to attack power - defense
            tots = tdmg - c1->getarm(); //set tots to tdmg - armor

            if (tots <= 0){

                cout << "\n**no damage dealt**\n" << endl;

            }

            else{

                hp -= tots;
                cout << "\nYou deal " << tots << "total damage."  <<endl;
                c1->sethealth(hp);

            }

            //enemy will return fire!
            c1->attack(c2, c1);
            cout << "You have " << c2->health() << " health remaining " <<endl;


        //check for death
            if (c1->death() == true) {
                cout << "You have slain the enemy!" << endl;

            }

            else if (c2->death() == true){
                cout << "You have perished in glorious combat!" << endl;

            }

            else if (c1->death() == false){
            cout << "The enemy has " << c1->health() << " health remaining." << endl;


            }
        }
    };

/*****************************************************


Shadow Class

*****************************************************/

    class Shadow : public Character
    {

    public:
        Shadow(){

        hitpoints = 12;
        armorp = 3;

        }

        void sethealth(double hp){
            hitpoints = hp;
        }

        void setap(){
            attackpower = ((rand()%10) + (rand()%10));
        }

        void setd(){
            int miss;
            srand (time(NULL));
            miss = rand()% 10;


            if (miss <= 5){
                cout << "\nThe shadow evades! " << endl;
                defensep = 100000;  //simply sets defense way too high to even hit.  50% chance to evade.
            }

            //otherwise its a normal defense roll
            else{
                defensep = (rand()%6);
            }


        }
        void attack(Character* c1, Character* c2){
            double tdmg, hp, arm, tots;
            c1->setd(); //defense roll
            c2->setap(); //attack rol

            hp = c1->health(); //set health to current health
            tdmg = (c2->getap() - c1->getd()); //set tdmg to attack power - defense
            tots = tdmg - c1->getarm(); //set tots to tdmg - armor

            if (tots <= 0){

                cout << "\n**no damage dealt**\n" << endl;

            }

            else{

                hp -= tots;
                cout << "\nYou deal " << tots << "total damage."  <<endl;
                c1->sethealth(hp);

            }


            //enemy will return fire!
            c1->attack(c2, c1);
            cout << "You have " << c2->health() << " health remaining " <<endl;


            //check for death
            if (c1->death() == true) {
                cout << "You have slain the enemy!" << endl;

            }

            else if (c2->death() == true){
                cout << "You have perished in glorious combat!" << endl;

            }

            else if (c1->death() == false){
            cout << "The enemy has " << c1->health() << " health remaining." << endl;


            }
        }


    };

/*****************************************************


Blue Class

*****************************************************/
     class Blue : public Character
    {

    public:
        Blue(){

        hitpoints = 12;
        armorp = 3;

        }

        void sethealth(double hp){
            hitpoints = hp;
        }

        void setap(){

            attackpower = ((rand()%10) + (rand()%10));

            int tooblue;
            srand (time(NULL));
            tooblue = rand()% 10;


            if (tooblue <= 5){
                cout << "Two additional blue men enter the battle! " << endl;

                double blue2 =((rand()%10) + (rand()%10)); //
                double blue3 =((rand()%10) + (rand()%10));
                attackpower = attackpower + blue2 + blue3; //will double the attack power of the blue men.  50% chance at having 2 blue men attack.

            }
        }

        void setd(){

                defensep = ((rand()%6) + (rand()%6) + (rand()%6));
            }

        void attack(Character* c1, Character* c2){
            double tdmg, hp, arm, tots;
            c1->setd(); //defense roll
            c2->setap(); //attack rol

            hp = c1->health(); //set health to current health
            tdmg = (c2->getap() - c1->getd()); //set tdmg to attack power - defense
            tots = tdmg - c1->getarm(); //set tots to tdmg - armor

            if (tots <= 0){

                cout << "\n**no damage dealt**\n" << endl;

            }

            else{

                hp -= tots;
                cout << "\nYou deal " << tots << "total damage."  <<endl;
                c1->sethealth(hp);

            }

            //enemy will return fire!
            c1->attack(c2, c1);
            cout << "You have " << c2->health() << " health remaining " <<endl;


    //check for death
            if (c1->death() == true) {
                cout << "You have slain the enemy!" << endl;

            }

            else if (c2->death() == true){
                cout << "You have perished in glorious combat!" << endl;

            }

            else if (c1->death() == false){
            cout << "The enemy has " << c1->health() << " health remaining." << endl;


            }
        }
    };


    int main(){

    //create characters objects
    Barbarian barb;
    Goblin gob;
    Reptile rep;
    Shadow sha;
    Blue blues;
    //create pointers from classes to character attributes.
    Character *barba = &barb;
    Character *gobs = &gob;
    Character *reps = &rep;
    Character *shad = &sha;
    Character *blu = &blues;

    //declare variables
    int f = 0;

    //game menu

    do
        {
            int choice = 0;
            cout << "\nPlease select your class: " << endl;
            cout << "1. Barbarian " << endl;
            cout << "2. Goblin " << endl;
            cout << "3. Reptile People " << endl;
            cout << "4. Blue Men " << endl;
            cout << "5. The Shadow ";
            cin >> choice;

            do
            {
                int select;
                //select target
                cout << "\nWho do you want to attack?" << endl;
                cout << "1. Goblin " << endl;
                cout << "2. Reptile People " << endl;
                cout << "3. Blue Men " << endl;
                cout << "4. The Shadow ";
                cin >> select;

                    //attacking goblins
                    if (select == 1){

                        barba->attack(gobs, barba); //the class in the first position is the attackee, the 2nd is attacker

                    }

                    //attacking the reptiles
                    if (select == 2){
                        barba->attack(reps, barba); //the class in the first position is the attackee, the 2nd is attacke

                    }


                    //attacking the blue men
                    if (select == 3){

                        barba->attack(blu, barba); //the class in the first position is the attackee, the 2nd is attacker
                    }


                    //attacking the  shadow
                    if (select == 4){

                        barba->attack(shad, barba); //the class in the first position is the attackee, the 2nd is attacker

                    }

            } while (choice == 1);


//Goblin attack options
            do{
                int select;
                //select target
                cout << "\nWho do you want to attack?" << endl;
                cout << "1. Barbarian " << endl;
                cout << "2. Reptile People " << endl;
                cout << "3. Blue Men " << endl;
                cout << "4. The Shadow ";
                cin >> select;

                    //attacking goblins
                    if (select == 1){
                        gobs->attack(barba, gobs); //the class in the first position is the attackee, the 2nd is attacker

                    }

                    //attacking the reptiles
                    if (select == 2){

                        gobs->attack(reps, gobs); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the blue men
                    if (select == 3){

                        gobs->attack(blu, gobs); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the blue men
                    if (select == 4){

                        gobs->attack(shad, gobs); //the class in the first position is the attackee, the 2nd is attacker

                    }


            }while(choice == 2);


            //Reptile attack options
            do{
                int select;
                //select target
                cout << "\nWho do you want to attack?" << endl;
                cout << "1. Barbarian " << endl;
                cout << "2. Goblins " << endl;
                cout << "3. Blue Men " << endl;
                cout << "4. The Shadow ";
                cin >> select;

                    //attacking goblins
                    if (select == 1){

                        reps->attack(barba, reps); //the class in the first position is the attackee, the 2nd is attacker

                    }

                    //attacking the goblins
                    if (select == 2){

                        reps->attack(gobs, reps); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the blue men
                    if (select == 3){

                        reps->attack(blu, reps); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the blue men
                    if (select == 4){

                        reps->attack(shad, reps); //the class in the first position is the attackee, the 2nd is attacker

                    }


            }while(choice == 3);


        //Blue attack options
            do{
                int select;
                //select target
                cout << "\nWho do you want to attack?" << endl;
                cout << "1. Barbarian " << endl;
                cout << "2. Goblins " << endl;
                cout << "3. Reptile" << endl;
                cout << "4. The Shadow ";
                cin >> select;

                    //attacking goblins
                    if (select == 1){

                        blu->attack(barba, blu); //the class in the first position is the attackee, the 2nd is attacker

                    }

                    //attacking the goblins
                    if (select == 2){

                        blu->attack(gobs, blu); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the reptiles
                    if (select == 3){

                        blu->attack(reps, blu); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the shadow
                    if (select == 4){

                        blu->attack(shad, blu); //the class in the first position is the attackee, the 2nd is attacker

                    }


            }while(choice == 4);

        //Shadow attack options
            do{
                int select;
                //select target
                cout << "\nWho do you want to attack?" << endl;
                cout << "1. Barbarian " << endl;
                cout << "2. Goblins " << endl;
                cout << "3. Reptile" << endl;
                cout << "4. Blue men ";
                cin >> select;

                    //attacking goblins
                    if (select == 1){

                        shad->attack(barba, shad); //the class in the first position is the attackee, the 2nd is attacker

                    }

                    //attacking the goblins
                    if (select == 2){

                        shad->attack(gobs, shad); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the reptiles
                    if (select == 3){

                        shad->attack(reps, shad); //the class in the first position is the attackee, the 2nd is attacker

                    }


                    //attacking the blue men
                    if (select == 4){

                        shad->attack(blu, shad); //the class in the first position is the attackee, the 2nd is attacker

                    }


            }while(choice == 4);



        }while (f == 0);

    return 0;


}
