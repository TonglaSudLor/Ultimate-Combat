# ULTIMATE MONSTER BATTLE
### A Turn-Based RPG Game in C++ (Terminal-Based)

---

## GAME OVERVIEW

ป็นเกมต่อสู้ที่มีระบบการต่อสู้คล้ายกับเกมโปเกม่อน emerald ตัวเกมจะรันบน terminal โดยภายในเกมมีตัวละครทั้งหมด 6 ตัว

ทุกตัวละครจะมี HP เท่ากันที่ 100 และมีทั้งหมด 4 ความสามารถซึ่งแต้มขั้นต่ำที่ต้องใช้สำหรับแต่ละความสามารถจะไม่เท่ากัน และแต่ละตัวจะมีธาตุที่ต่างกันเพื่อให้เกิดการได้เปรียบ-เสียเปรียบระหว่างตัวละคร

ผู้เล่น 2 คน  
มอนสเตอร์ 6 แบบ  
ทุกตัวมี HP เท่ากันที่ 100  
คำสั่งในการเล่น: Attack / Switch  

---

## GAME RULES

- ช่วงเตรียมตัว : 
        มีผู้เล่นทั้งหมด 2 ฝั่ง แต่ละฝั่งสามารถเลือกตัวละครได้ 3 ตัว ไม่สามารถเลือกตัวละครซ้ำกับฝ่ายตัวเองได้ แต่สามารถเลือกตัวละครซ้ำกับฝ่ายตรงข้ามได้ โดยตัวละครตัวแรกที่เลือกจะเป็นตัวที่อยู่ในสนามซึ่งจะถูกใช้ต่อสู้ ส่วนตัวที่เหลือจะเป็นตัวสำรอง 


- ช่วงต่อสู้: 
       ระบบจะสุ่มผู้เล่นที่ได้เป็นฝ่ายเริ่มก่อน โดยในการเล่นแต่ละตาผู้เล่นจะสามารถเลือกโจมตี หรือเปลี่ยนตัวละครได้อย่างใดอย่างหนึ่ง หากผู้เล่นเลือกโจมตีระบบจะทอยลูกเต๋าเพื่อกำหนดแต้ม ซึ่งแต้มที่ได้จะเป็นตัวกำหนดความสามารถใช้ได้ โดยจำนวนแต้มที่มาก จะทำให้สามารถใช้ความสามารถที่มีพลังโจมตีเยอะได้ หลังจากเลือกใช้ความสามารถเพื่อโจมตีแล้ว จะถือว่าจบตา 

    แต่หากผู้เล่นเลือกเปลี่ยนตัวละคร จะมีหน้าต่างเลือกตัวละครขึ้นมา หลังจะเลือกตัวเรียบร้อยแล้ว จะถือว่าจบตา ถ้าตัวละครที่อยู่ในสนามถูกโจมตีจน HP เหลือ 0 ผู้เล่นจะต้องเลือกตัวละครสำรองมาเปลี่ยน (หลังจากเปลี่ยนยังสามารถเล่นตานั้นได้อยู่) เกมจะวนอย่างนี้ไปเรื่อยๆจนกระทั่งฝ่ายใดฝ่ายหนึ่งไม่เหลือตัวละครแล้ว จะถือว่าฝ่ายที่ยังมีตัวละครอยู่เป็นผู้ชนะ


- การได้เปรียบ-เสียเปรียบของแต่ละธาตุ

| ธาตุ|ได้เปรียบ | เสียเปรียบ|
|------|---------|-------|
| `Fire `| `Grass`|`Water` `Rock`  |
| `Water`| `Fire` `Rock`|`Grass` `Electric`  |
| `Grass `| `Water` `Rock`|`Fire`  |
| `Electric `| `Water`|`Grass` `Rock`  |
| `Rock `| `Fire` `Electric`|`Water` `Grass`  |
| `Psychic `| `Electri` `Rock`|`Psychic`  |
---

## SOFTWARE REQUIREMENTS

### Functional
- ผู้เล่นสามารถเลือกตัวละครได้ 
- ผู้เล่นสามารถเลือกโจมตีหรือเปลี่ยนตัวละครในตาของตัวเองได้
- ผู้เล่นสามารถเลือกความสามารถที่ต้องการใช้ได้
- ผู้เล่นสามารถเปลี่ยนตัวละครที่อยู่ในสนามได้

### Non-Functional
- ผู้เล่นที่เลือกตัวละครทีหลังต้องไม่สามารถเห็นตัวละครที่ผู้เล่นคนก่อนเลือก
- โปรแกรมต้องสามารถทำงานได้โดยไม่มีปัญหา ไม่ค้าง และไม่มีบัค
- เกมต้องสามารถตอบสนองอย่างรวดเร็ว
- ผู้ใช้ต้องสามารถป้อนข้อมูลต่างๆ ได้อย่างง่ายที่สุด
---

## HOW TO PLAY (USER GUIDE)

1. ติดตั้ง g++ หรือใช้ผ่าน Compiler ออนไลน์ก็ได้
2. คอมไพล์:
```
g++ main.cpp game.cpp Player.cpp Monster.cpp Move.cpp Display.cpp -o monster_game
```
3. เริ่มเล่น:
```
./monster_game
```
4. เลือกคำสั่ง แล้วต่อสู้จนชนะมอนสเตอร์ทั้งหมด!

---


## FILE STRUCTURE

| ไฟล์ | หน้าที่ |
|------|---------|
| `main.cpp` | ไฟล์หลักของเกมที่เอาไว้รัน |
| `game.cpp` | ประกาศ class ที่เกี่ยวกับระบบของเกม |
| `game.h` | Define ฟังก์ชั่นของระบบเกม |
| `Player.cpp` | Define ฟังก์ชั่นที่รับข้อมูลจากผู้เล่น |
| `Monster.cpp` | ประกาศคุณลักษณะต่างๆ ของ monsters ทั้ง 6 ตัว |
| `Move.cpp` | การสลับฝั่งตัว onsters |
| `Display.cpp` | ฟังก์ชั่นทั้งหมดที่เกี่ยวกับกราฟฟิก ascii  |
| `game-settings.h` |การตั้งค่าต่างๆ ของเกม เช่น จำนวนทีม เป็นต้น  |

---
## HOW THE CODE WORKS (With OOP)
- struct nameDisplay
```
nameDisplay[name,type] // struct for name display
```
- void clearConsole()
```
clearConsole() // clear terminal screen
```
- void waitForAnyKey()
```
waitForAnyKey() // wait for any input from user (Only for Windows)
```
- class baseObject
```
//baseclass for inheitance
getName() // return a name of the object

getType() // return a type of the object

```
- class Move 
```
Move(std::string name, std::string type, int cost, int damage); // Constructor

getName() // return a name of the object(inherit from baseobject)

getType() // return a type of the object(inherit from baseobject)

getcost() // return a cost of the move

getdamage() // return a damage of the move
```
- class Monster
```
Monster(std::string name, std::string type, int HP, std::vector<Move> moves , std::vector<std::string> art); // Constructor

getName() // return a name of the object(inherit from baseobject)

getType() // return a type of the object(inherit from baseobject)

void takeDamage(int amount) // subtract damage from the monster by "amount"

bool isAlive() // return a status of monsters if it alive or not

int getHp() // return HP of the monster

std::vector<Move> getmoves() // return all moves of the monster

std::vector<std::string> getart() // return an art of the monster
```
- class Player
```
Player(std::string name, std::vector<Monster> team, int currentMonster); // Constructor

void chooseAttack(int Dice, Player& opponent ); // function to display a alviable moves by "Dice" cost and subtract damages from "oponents "

void switchMonster() // function to display alive monster and let the player choose to switch

std::string getName() // return name of the player

std::vector<Monster>& getTeam() // return member of the player's team

int getCurrent() // return the current monster in the battle field
```

- class Game
```
Game()  // constructor

void start() // function to start the game by let players choosing their monster into their team

void turnswitch() // main function to keep the game continuing by let the player choose to attack or switch monster in their turn and switch to another's after ended

void checkWin() // function to check for the condition to win and stop the loop

int rollDice() // function to simulate a dice rolling by random number of 1 - 6
```
- class BattleScreen
```
BattleScreen() {screen = std::vector<std::string>(HEIGHT, std::string(WIDTH, ' ')); } // constructor

clearScreen() // function to clear graphic screen

drawFrame(int x, int y, int boxWidth, int boxHeight) // draw a frame of the graphic screen.

drawMonsterBox(int x, int y, std::string playerName, std::string monsterName, int currentHP, int maxHP) // draw a monster box that contain "playerName" , "monsterName", and a bar that show "currentHP" and "maxHP"

void drawMonster(int x, int y, const std::vector<std::string>& art) // Draw monster at the "x", "y" position of the display

void render() // print out every graphic on the terminal

void updateBattleScreen(std::string Player1,std::vector<std::string> Player1Art, std::string Player1Monster, int Player1HP,
                             std::string Player2,std::vector<std::string> Player2Art, std::string Player2Monster, int Player2HP)
                             // update the graphic screen by gotten parameters

```
- game-settings.h
```
int max_team =1;   // max number of each player's team

int criticalMultiply =2; // the multiply number of damage if it get a critical

double effectivenessMultiply =1.5; // the multiply number of damage if it is an effective move (by type)

double ineffectivenessMultiply =0.5; // the multiply number of damage if it is not an effective move (by type)


```
---