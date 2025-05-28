#include "game.h"
#include "game.cpp"
// #include <iostream>
#include <vector>


 int main(){
    Game myGame;
    myGame.start();

    while (true) {
        myGame.turnswitch();
    }

    return 0;
 }