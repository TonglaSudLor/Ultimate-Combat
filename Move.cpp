#include "game.h"
#include <iostream>
//-----------Move--------
Move::Move(std::string name, std::string type, int cost, int damage) // Constructor
    : baseObject(name, type), cost(cost), damage(damage) {}

void Move::use(std::string attacker, std::string target) {
    std::cout << attacker << " uses " << getName() << " on " << target << "!\n";
}



//-----------------------------each monster's moves
// Move(std::string name, std::string type, int cost, int damage);
//--------Flamo--------------//
Move ember("Ember", "Fire", 2, 15);
 Move flameBurst("Flame Burst", "Fire", 3, 20);
 Move fireSpin("Fire Spin", "Fire", 4, 25);
 Move blazeKick("Blaze Kick", "Fire", 5, 30);

//----------Aquaril---------//
Move waterGun("Water Gun", "Water", 2, 15);
 Move aquaJet("Aqua Jet", "Water", 3, 20);
 Move bubbleBeam("Bubble Beam", "Water", 4, 25);
 Move hydroPump("Hydro Pump", "Water", 5, 30);

//----------Terraplant--------//
 Move vineWhip("Vine Whip", "Grass", 2, 15);
 Move leafBlade("Leaf Blade", "Grass", 3, 20);
 Move razorLeaf("Razor Leaf", "Grass", 4, 25);
 Move solarBeam("Solar Beam", "Grass", 5, 30);

//-------------Zappy------------//
 Move thunderShock("Thunder Shock", "Electric", 2, 15);
 Move spark("Spark", "Electric", 3, 20);
 Move electroBall("Electro Ball", "Electric", 4, 25);
 Move thunder("Thunder", "Electric", 5, 30);

//------------Rocky-----------------//
 Move rockThrow("Rock Throw", "Rock", 2, 15);
 Move rockSlide("Rock Slide", "Rock", 3, 20);
 Move stoneEdge("Stone Edge", "Rock", 4, 25);
 Move earthquake("Earthquake", "Rock", 5, 30);

//----------Mysty-----------------//
 Move magicMissile("Magic Missile", "Psychic", 2, 15);
 Move psychic("Psychic", "Psychic", 3, 20);
 Move futureSight("Future Sight", "Psychic", 4, 25);
 Move mysticForce("Mystic Force", "Psychic", 5, 30);


 
double getTypeEffectiveness(const std::string& attackType, const std::string& targetType) {
    if (attackType == "Fire") {
        if (targetType == "Grass") return effectivenessMultiply;
        if (targetType == "Water" || targetType == "Rock") return ineffectivenessMultiply;
    }
    if (attackType == "Water") {
        if (targetType == "Fire" || targetType == "Rock") return effectivenessMultiply;
        if (targetType == "Grass" || targetType == "Electric") return ineffectivenessMultiply;
    }
    if (attackType == "Grass") {
        if (targetType == "Water" || targetType == "Rock") return effectivenessMultiply;
        if (targetType == "Fire") return ineffectivenessMultiply;
    }
    if (attackType == "Electric") {
        if (targetType == "Water") return effectivenessMultiply;
        if (targetType == "Grass" || targetType == "Rock") return ineffectivenessMultiply;
    }
    if (attackType == "Rock") {
        if (targetType == "Fire" || targetType == "Electric") return effectivenessMultiply;
        if (targetType == "Water" || targetType == "Grass") return ineffectivenessMultiply;
    }
    if (attackType == "Psychic") {
        if (targetType == "Electric" || targetType == "Rock") return effectivenessMultiply;
        if (targetType == "Psychic") return ineffectivenessMultiply;
    }

    return 1.0; // Default ไม่มีผลแพ้ชนะ
}
