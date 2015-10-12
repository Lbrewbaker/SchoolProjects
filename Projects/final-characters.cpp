/********************************
Author: Luke Brewbaker
Date: 6/1/15
Modified: 6/9/15
File: character.cpp

Overview: Creates the character classes used in Main.cpp


Input: character pointers created in main.cpp


Output: The only output will be the bool value into main.  kept it simple.


*******************************/

#include <iostream>
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

Player

*****************************************************/
    class Player : public Character
    {

    public:
        Player(){

        hitpoints = 10;
        armorp = 0;

        }

        void sethealth(double hp){
            hitpoints = hp;
        }

        void setap(){
            attackpower =  5;
        }

        void setd(){
            defensep =  5;
        }

        void attack(Character* c1, Character* c2){

            double tdmg, hp, arm, tots; //used in calculating the damage
            c1->setd(); //defense roll
            c2->setap(); //attack rol

            hp = c1->health(); //set health to current health
            tdmg = (c2->getap() - c1->getd()); //set tdmg to attack power - defense
            tots = tdmg - c1->getarm(); //set tots to tdmg - armor

            if (tots <= 0){
                cout << "\n*No damage dealt*\n" << endl;
            }

            else{

                hp -= tots; //subtracts total damage, which is ((attackpower - defense power) - armor)
                c1->sethealth(hp);
            }

            //return attack
            c1->attack(c2, c1);
        }


    };

/*****************************************************

Duck of Doom

*****************************************************/
    class Duck : public Character
    {

    public:
        Duck(){

        hitpoints = 30;
        armorp = 0;

        }

        void sethealth(double hp){
            hitpoints = hp;
        }

        void setap(){
            attackpower = (3 * (rand()% 6  +1));
        }

        void setd(){
            defensep = 0;
        }

        void attack(Character* c1, Character* c2){

            double tdmg, hp, arm, tots; //used in calculating the damage
            c1->setd(); //defense roll
            c2->setap(); //attack rol

            hp = c1->health(); //set health to current health
            tdmg = (c2->getap() - c1->getd()); //set tdmg to attack power - defense
            tots = tdmg - c1->getarm(); //set tots to tdmg - armor

            if (tots <= 0){
                cout << "\n*No damage dealt*\n" << endl;
            }

            else{

                hp -= tots; //subtracts total damage, which is ((attackpower - defense power) - armor)
                c1->sethealth(hp);
            }

            if(!c1->death()){
                c1->attack(c2, c1);

            }

            //return attack

        }


    };




