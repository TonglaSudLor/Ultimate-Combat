#pragma once
// #include "base_class.h"
#include <vector>
#include <string>
#include <conio.h>
#include <iostream>
struct nameDisplay
{  
    std::string name;
    std::string type;
};

void clearConsole() {
    #ifdef _WIN32
        std::system("cls"); // For Windows
    #else
        std::system("clear"); // For Unix-like systems
    #endif
    }
void waitForAnyKey() { // func for wait for the user type anything to the terminal (for texts readability)
    _getch(); 
}

class baseObject {
private:
    std::string name;
    std::string type;
    
public:
    baseObject(std::string name, std::string type): name(name), type(type) {}

    std::string getName() { 
        return name; 
    }
    std::string getType() { 
        return type; 
    }
};



class Move : public baseObject{ // first inheritance
public:
    Move(std::string name, std::string type, int cost, int damage); // Constructor
    void use(std::string attacker, std::string target);
    int getcost(){
        return cost;
    }
    int getdamage(){
        return damage;
    }

private:
    // std::string name;        //inherit from baseObject
    // std::string type;        //inherit from baseObject
    int cost;
    int damage;
};


class Monster :public baseObject{   // second inheritance
public:
    Monster(std::string name, std::string type, int HP, std::vector<Move> moves , std::vector<std::string> art); // Constructor
    void takeDamage(int amount);
    //---------------------------------------------------------
    bool isAlive();
    //---------------------------------------------------------
    int getHp(){
        return HP;
    }
    std::vector<Move> getmoves(){
        return(moves);
    }
    std::vector<std::string> getart(){
        return(art);
    }

private:
    // std::string name;      //inherit from baseObject
    // std::string type;       //inherit from baseObject
    int HP;
    std::vector<Move> moves ;
    std::vector<std::string> art;
};




class Player{
public:
    Player(std::string name, std::vector<Monster> team, int currentMonster); // Constructor
    void chooseAttack(int Dice, Player& opponent );
    
    void switchMonster();

    std::string getName(){
        return name;
    }

    std::vector<Monster>& getTeam(){
        return team;
    }
    int getCurrent(){
        return currentMonster;
    }
    
private:
    std::string name;
    std::vector<Monster> team;
    int currentMonster;
};


class Game {

public:
    Game();
    void start();
    void turnswitch();
    void checkWin();
    int rollDice();
    // bool tossCoin();
private:
    Player Player1;
    Player Player2;
    Player* currentTurn;
};


