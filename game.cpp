#pragma once
#include "game.h"
#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for srand(time(0))
#include "game-settings.h"
#include "Display.cpp"
#include "Player.cpp"
#include "Monster.cpp"
// #include "Move.cpp"





// ============ Game ============
Game::Game()
    : Player1("Player1", {},0 ), Player2("Player2", {},0),currentTurn(nullptr){} // Constructor

int Game::rollDice() {
    return (rand() % 6) + 1; // resulting 1-6
}


void Game::start() {
    srand(time(0)); //  random seed
    std::cout << "Game started!\n";

    
    clearConsole();
    //------------------------Start of choose mosters of Player 1---- 
    std::vector<Monster> player1Team;
    std::vector<nameDisplay> leftMonster;
    for(Monster a : allMonsters){
        nameDisplay b;
        b.name =a.getName();
        b.type = a.getType();
        leftMonster.push_back(b);
    }
    //--------------Choose 3 monster--------
    while (player1Team.size()<max_team)
    {
        std::cout << "Choose " << max_team- player1Team.size() << " monsters for your team:"<< std::endl;
        for (int i = 0; i < leftMonster.size(); i++) {
            std::cout << i+1 << ". " << leftMonster[i].name << " (" << leftMonster[i].type << ")"<<std::endl;
        } 

        int choosen;
        std::cout << "Enter the number of the monster you want to have in your team: ";
        std::cin>>choosen;
        choosen--;
        if (choosen>=0&& choosen < leftMonster.size()){
            if(leftMonster[choosen].name != "_Choosen_"){
                for(Monster a: allMonsters){
                    if(leftMonster[choosen].name== a.getName()){
                        player1Team.push_back(a);
                        leftMonster[choosen].name = "_Choosen_";
                    }
                }
            }
            else if (leftMonster[choosen].name == "_Choosen_"){
                std::cout<< "This monster is choosen.";
            }
        }
    clearConsole();
    }

    //------------------end of choose monster of Player 1--------
    //------------------start of choose monster of player 2------
    std::vector<Monster> player2Team;
    leftMonster = {};
    for(Monster a : allMonsters){
        nameDisplay b;
        b.name =a.getName();
        b.type = a.getType();
        leftMonster.push_back(b);
    }
    //--------------Choose 3 monster--------
    while (player2Team.size()<max_team)
    {
        std::cout<< std::endl;
        std::cout << "Choose " << max_team- player2Team.size() << " monsters for your team:"<< std::endl;
        for (int i = 0; i < leftMonster.size(); i++) {
            std::cout << i+1 << ". " << leftMonster[i].name << " (" << leftMonster[i].type << ")"<<std::endl;
        } 
        int choosen;
        std::cout << "Enter the number of the monster you want to have in your team: ";
        std::cin>>choosen;
        choosen--;
        if (choosen>=0&& choosen < leftMonster.size()){
            if(leftMonster[choosen].name != "_Choosen_"){
                for(Monster a: allMonsters){
                    if(leftMonster[choosen].name== a.getName()){
                        player2Team.push_back(a);
                        leftMonster[choosen].name = "_Choosen_";
                    }
                }
            }
            else if (leftMonster[choosen].name == "_Choosen_"){
                std::cout<< "This monster is choosen.";
            }
        }
    clearConsole();
    }
    //------------------end of choose monster of Player 2--------
    //-----------Create player----------
    Player1 = Player("Player 1", player1Team, 0);
    Player2 = Player("Player 2", player2Team, 0);

    // random for the first turn
    if (rand() % 2 == 0)
        currentTurn = &Player1;
    else
        currentTurn = &Player2;

    std::cout << currentTurn->getName() << " will start first!"<< std::endl;
}

void Game::turnswitch() {
    clearConsole();
    BattleScreen screen;
    Player* opponent = (currentTurn == &Player1) ? &Player2 : &Player1; // assign the opponent 
    
        screen.updateBattleScreen(
        opponent->getName(), opponent->getTeam()[opponent->getCurrent()].getart()
        ,opponent->getTeam()[opponent->getCurrent()].getName()
        , opponent->getTeam()[opponent->getCurrent()].getHp(),  //oponent
        
        currentTurn->getName(), currentTurn->getTeam()[currentTurn->getCurrent()].getart()
        ,currentTurn->getTeam()[currentTurn->getCurrent()].getName()
        , currentTurn->getTeam()[currentTurn->getCurrent()].getHp() //current player
    );
    std::string choose;
    std::cout << currentTurn->getName() << " and " 
                                        <<currentTurn->getTeam()[currentTurn->getCurrent()].getName() 
                                        <<"'s Turn!"<<std::endl;


    //--------------------Action choosing---------
    std::cout << "Choose 1 action:"<<std::endl;
    std::cout << "1. Attack"<<std::endl;
    std::cout << "2. Switch"<<std::endl;
    std::cin >> choose;
    
    if (choose == "1" || choose == "Attack" || choose == "attack") { // attack
        int Dice = rollDice();
        Player* opponent = (currentTurn == &Player1) ? &Player2 : &Player1;
        currentTurn->chooseAttack(Dice, *opponent);

    } else if (choose == "2" || choose == "Switch" || choose == "switch") { // switch monster
        std::cout << currentTurn->getName() << " choose to Switch!\n";
        currentTurn->switchMonster();
    }
    //--------------------Turn changing--------
    if (currentTurn == &Player1) {
        currentTurn = &Player2;
    } else {
        currentTurn = &Player1;
    }
    clearConsole();
    checkWin();
}


//--------------------Check winning condition
void Game::checkWin() {
    //----------check if any monsters is alive or not
    bool player1Alive = false;
    int temp1 =0;
    for (auto& mon : Player1.getTeam()) {
        if (mon.isAlive()) player1Alive = true;
    }
    bool player2Alive = false;
    for (auto& mon : Player2.getTeam()) {
        if (mon.isAlive()) player2Alive = true;
    }

    if (!player1Alive) {
        std::cout <<"Player 1 runs out of monsters. " <<"Player 2 wins!\n";
        exit(0);
    } else if (!player2Alive) {
        std::cout<<"Player 2 runs out of monsters. " << "Player 1 wins!\n";
        exit(0);
    }
}




//  int main(){
//  }