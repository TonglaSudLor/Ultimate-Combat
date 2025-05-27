
#include "game.h"
#include "Move.cpp"
#include "game.cpp"
#include <iostream>






//------------Player----------
Player::Player(std::string name, std::vector<Monster> team,int currentMonster) // Constructor
    : name(name), team(team), currentMonster(currentMonster) {}

void Player::chooseAttack(int Dice, Player& opponent ) {  // choose attack
    // int Dice=0;
    Monster& attackerMon = team[currentMonster];
    Monster& defenderMon = opponent.team[opponent.currentMonster];

    std::cout << getTeam()[getCurrent()].getName() << " choose to Attack!\n\n";
    // std::cout <<"rolling Dice.. "<< std::endl;
    std::cout<< "your point is "<< Dice<<" Here're move(s) you can use \n" ;
    std::vector<Move> moves = getTeam()[getCurrent()].getmoves();

    //---------------------------------Display alvailable move
    int index =1;
    std::vector<Move> availableMoves = {};
    for (auto a : moves){
        if(a.getcost()<=Dice){
            std::cout<< index<< ". "<< a.getName()<< "type : "
                                    << a.getType()<< "damage : " 
                                    << a.getdamage()<< std::endl;
            availableMoves.push_back(a);
            index++;
        }
    }
    if(availableMoves.empty()){
        std::cout<<"\nThere's no move(s) that can be use. Passing the turn";
        waitForAnyKey();
        return;
    }
    //-------------------------------Choose one of the move-----------
    int choosen;
    std::cout <<std::endl <<"\nEnter the number of the move you want to use: ";
    std::cin>> choosen;
    choosen--;
    if(choosen>= 0 && choosen< availableMoves.size()){
        Move selectedMove = availableMoves[choosen];
        std::cout<< getName()<<"'s "<< getTeam()[getCurrent()].getName()<< " use " << selectedMove.getName() << "!" <<std::endl;
        
        int damage = selectedMove.getdamage();
        Monster& targetMonster = opponent.getTeam()[opponent.getCurrent()];
        double multiplier = getTypeEffectiveness(selectedMove.getType(), targetMonster.getType()); //check the type
        damage = static_cast<int>(damage * multiplier);

        if (multiplier > 1.0) {
            std::cout << "It's super effective!\n";
            waitForAnyKey();
        } else if (multiplier < 1.0) {
            std::cout << "It's not very effective...\n";
            waitForAnyKey();
        }

        int critical = rand() % 10; //10% chance of get a critical hit 
        if (critical == 0) {
            damage=damage*2;
            std::cout << "Critical Hit! \n";
            waitForAnyKey();
        }

        targetMonster.takeDamage(damage);
        
        if (!targetMonster.isAlive()) {  // check if target still allive or not
            std::cout << targetMonster.getName() << " fainted!\n";
            waitForAnyKey();
            opponent.switchMonster();  // switch monster
        }
    }

}


void Player::switchMonster() {
    // checkWin();
    clearConsole();
    std::cout << "Choose a monster to switch to: "<< std::endl;
    int index =1;
    for (auto a : team) {
        std::cout<<index<<". "<<a.getName()<<" type : " << a.getType() << " "<< a.getHp()<< (!a.isAlive()? " - Fainted " : "")<<std::endl;
        index++;
    }
    int alive = 0;
    for (auto a : team){
        if (a.isAlive()) alive++;
    }

    int choose;
    while (alive>0) {
        std::cout << "Enter the number of the monster you want to switch to: ";
        std::cin >> choose;

        
        if (std::cin.fail() || choose< 1 || choose > (int)team.size()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again.\n";
            continue;
        }
        
        if (!team[choose - 1].isAlive()) {
            std::cout << team[choose - 1].getName() << " has fainted! Choose another.\n";
            continue;
        }
        break; 
    }
    currentMonster= choose - 1;
    // std::cout << "Switched to " << team[currentMonster].getName() << "!\n";
}

