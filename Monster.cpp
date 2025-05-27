#include "game.h"
//----------Monster--------
Monster::Monster(std::string name, std::string type, int HP, std::vector<Move> moves , std::vector<std::string> art ) // Constructor
    :  baseObject(name, type), HP(HP), moves(moves), art(art){}

void Monster::takeDamage(int amount){ // subtrac damage from HP
    HP -= amount;
    if (HP < 0) HP = 0;
}
bool Monster::isAlive(){ // Check if monster is alive or not
 return HP>0;
}


std::vector<std::string> FlamoArt = {
    "    \\ ^ ^ /",
    "   (  >w<  )",
    "    \\_^^_/"
};


std::vector<std::string> AquarilArt = {
    "    .-'''-.",
    "   ( o_o )",
    "   /  ~  \\",
    "  (______)"
};


std::vector<std::string> TerraplantArt = {
    "    ( ^w^ )",
    "   (  ___  )",
    "    \\ |_| /",
    "     / | \\"
};


std::vector<std::string> ZappyArt = {
    "    .--.",
    "   ( >_< )",
    "    /VV\\",
    "   /____\\"
};


std::vector<std::string> RockyArt = {
    "   _______",
    "  /  o o  \\",
    " |   ___   |",
    "  \\_______/"
};

std::vector<std::string> MystyArt = {
    "    ( ~.~ )",
    "   --(~~~~)--",
    "     /   \\"
};


 

 //------------- Create monster and assign moves & arts
 Monster Flamo("Flamo", "Fire", 100, { flameBurst, fireSpin, ember, blazeKick } , FlamoArt);
 Monster Aquaril("Aquaril", "Water", 100, { aquaJet, waterGun, bubbleBeam, hydroPump }, AquarilArt );
 Monster Terraplant("Terraplant", "Grass", 100, { vineWhip, leafBlade, razorLeaf, solarBeam },  TerraplantArt);
 Monster Zappy("Zappy", "Electric", 100, { thunderShock, spark, electroBall, thunder }, ZappyArt);
 Monster Rocky("Rocky", "Rock", 100, { rockThrow, rockSlide, stoneEdge, earthquake }, RockyArt);
 Monster Mysty("Mysty", "Psychic", 100, { magicMissile, psychic, futureSight, mysticForce }, MystyArt);

 std::vector<Monster> allMonsters = { Flamo, Aquaril, Terraplant, Zappy, Rocky, Mysty };