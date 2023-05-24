//Jakob Balkovec
//p5.cpp
//The following program is a simplified replica
//of a simple game called Monopoly with an SU twist

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>


using namespace std;

struct GameBoard{
string name;
int owner;
int purchaseCost;
int purchaseRent;
int playerTag;
};

struct Player{
string pName;
int money;
int position;
int playerTag;
int goCount;
};

const int MAX_PLAYERS = 6; 
const int MIN_PLAYERS = 2;
const int CHANCE_ROLL_MIN = 1;
const int CHANCE_ROLL_MAX = 3;
const int BOARD_SIZE = 45;
const int AFIELD = 5;
const int MAX_ROLL = 6;
const int MIN_ROLL = 1;
const int CASH = 1500;
const int GAME_OVER_CASH = 0;
const int GO_CASH = 200;
const int CHANCE_CASH = 50;
const int INCOME_TAX = 200; //pay
const int FEE_CASH = 200; //pay
const char YES = 'Y';
const int START = 0;
const int UNOWNABLE = -1;
const string SPACE = " ";
const string CHANCE = "Chance";
const string GO = "Go";
const string FEE = "Fees";
const string DOSO = "Dean of Students Office";
const string CHAPEL = "Chapel of St. Ignatius";
const string TAX = "Income Tax";

const string FILE_NAME = "/home/fac/sreeder/class/cs1420/p5input.dat"; // p5input.dat

void welcome(); //[1]//
//welcomes message

void goodbye(); //[1]//
//goodbye message

int dice(); //[1]//
//returns a random numbers between 1 and 6

int people(Player players[]); //[1]//
//takes in numPlayers and their names

int fillBoard(GameBoard boardInfo[]); //[1]//
//reads the file and creates a board, returns the number of places filled
//post: board will be updated

int winner (Player players[], int numPlayers); //[0.5]//
//returns index of winner

void checkLocation(Player players[], int playerTag, GameBoard boardInfo[]); //add player num in player function
//checks the location of the players to see what plays can be made
//gets current location


void takeTurn(Player players[], int playerTag, GameBoard boardInfo[]);
//takes turn for playerNum, calling dice & checkLocation
//updates player information
//returns wheter or not the game is over

void property(Player players[], int playerTag, GameBoard current, GameBoard boardInfo[]);
//called by checkLocation to deal with property (buy or pay rent)
//post: players(array) and boardInfo(array) are modified

int main()
{
  cout << endl << endl;
  
  char ans;
  GameBoard boardInfo[BOARD_SIZE];
  Player players[MAX_PLAYERS];
  int numPlayers;
  int turnCount = 0;
  srand(time(NULL));
  fillBoard(boardInfo);
  
  welcome();
  
  do{
    numPlayers = people(players);
    cout << endl << endl;
    cout << "Press enter to START";
    cin.ignore();
    cout << endl << endl;

    while(winner(players, numPlayers) == -1){
      takeTurn(players, turnCount, boardInfo);
      checkLocation(players, turnCount, boardInfo);
      if(turnCount == numPlayers - 1){
        turnCount = 0;
      }else{
        turnCount++;
      }
    }
    
    cout << "Play again? (Y/N): ";
    cin >> ans;
  }while(ans == YES);
  
  if (ans != YES){
        goodbye();
  }
  
  
  cout << endl << endl;
  return 0;    
}

int fillBoard(GameBoard boardInfo[])
{
  ifstream inFile;

  inFile.open(FILE_NAME);
  if(inFile.fail()){
    cout << "File error, exiting the program";
    cin.get();
    return false;
  }else{
    int count = 0;
    while(count < BOARD_SIZE && getline(inFile, boardInfo[count].name)){
      inFile >> boardInfo[count].owner
             >> boardInfo[count].purchaseCost
             >> boardInfo[count].purchaseRent;
      boardInfo[count].playerTag = 1;
      inFile.ignore();
      count++;
    }
  }
  return true;
}


int dice()
{
  int roll = 0;
  roll = rand() % ((MAX_ROLL - MIN_ROLL) + 1) + MIN_ROLL;
  return roll;
}   

void goodbye()
{
  cout << "Thank you for playing, I hope you enjoyed it! " << endl;
  cout << "Press enter to continue... ";
  cin.ignore();
}

void welcome()
{
  cout << "WELCOME TO SU MONOPOLY!" << endl << endl;
  cout << "///////////////////* * * RULES * * *///////////////////" << endl;    
  cout << endl << "Players move by roling a set of dice (2 six-sided die),";
  cout << " moving from 2 to 12 spaces around the board. " << endl;
  cout << "If player passes 'Go' they collect $200" << endl;
  cout << "If a player lands on an unowned building, they can purchase it.";
  cout << endl << "If a player lands on 'Chance' he/she gets to roll a dice, ";
  cout << ", if it lands on 1, 2 or 3 they get $50" << endl;
  cout << "If the player lands on a building owned by another player,";
  cout << " they pay the other player the appropriate amount of rent." << endl;
  cout << "If a player lands on Income Tax, they pay $200 to the bank." << endl;
  cout << endl << endl;
}

int people(Player players[]){
  int numPlayers;
  int i = 0;
  
  cout << "Enter Number of Players: ";
  cin >> numPlayers;
  while(numPlayers > MAX_PLAYERS|| numPlayers < MIN_PLAYERS){
    cout << "2 to 6 players only!" << endl;
    cout << "Enter Number of Players: ";
    cin >> numPlayers;
  }
  cout << endl;
  
  while (i < numPlayers){
    cout << "Player" << SPACE << i+1 << SPACE << " name: ";
    cin >> players[i].pName;
    players[i].money = CASH;
    players[i].position = START;
    players[i].playerTag = i+1;
    i++;
  }
  return numPlayers;
}

void checkLocation(Player players[], int playerTag, GameBoard boardInfo[])
{
  int sumRoll;
  GameBoard current = boardInfo[players[playerTag].position];
  
  if(current.owner == 0)
    property(players, playerTag, current, boardInfo);    
  
  if(current.owner > 0)
    property(players, playerTag, current, boardInfo);  
  
  
  if(current.owner == UNOWNABLE){
    if(current.name == GO){
      players[playerTag].money += GO_CASH;
      cout << players[playerTag].pName << SPACE << "You now have:" << SPACE << "$"
           << players[playerTag].money << endl;
      
    }else if(current.name == CHANCE){
      cout << "You landed on CHANCE, you get to roll a single dice!"<< endl;
      cout << "Press enter to roll...";
      cin.get();
      sumRoll = dice();
      cout << "You rolled" << SPACE << sumRoll << endl;
      cin.ignore();
      if(sumRoll >= CHANCE_ROLL_MIN && sumRoll <= CHANCE_ROLL_MAX){
        players[playerTag].money += CHANCE_CASH;
        cout << "Because you rolled" << SPACE << sumRoll << SPACE << "you recived $"<< CHANCE_CASH << ", ";
        cout << "you now have:" << SPACE << "$" << players[playerTag].money << endl;
        cout << endl;
      }else if(sumRoll > CHANCE_ROLL_MAX){
        players[playerTag].money = players[playerTag].money;
        cout << "Your roll was higher than" << SPACE << CHANCE_ROLL_MAX << SPACE;
        cout << ", you do NOT get $" << CHANCE_CASH << endl;
        cout << endl;
      }
      
    }else if(current.name == CHAPEL){
      boardInfo[playerTag].name = CHAPEL;
      cout << endl;
      cout << "You get to visit the Chapel of St. Ignatius for free LOL!" << endl;
      cout << "You now have:" << SPACE << "$" << players[playerTag].money << endl;
      cout << endl;
      
    }else if(current.name == TAX){
      players[playerTag].money -= INCOME_TAX;
      cout << endl;
      cout << "You landed on INCOME TAX and need to pay 200$ to the bank" << endl;
      cout << "You now have:" << SPACE << "$" << players[playerTag].money << endl;
      cout << endl;
      
    }else if(current.name == FEE){
      players[playerTag].money -= FEE_CASH;
      cout << endl;
      cout << "You landed on FEES and need to pay 200$ to the bank" << endl;
      cout << "You now have:" << SPACE << "$" << players[playerTag].money << endl;
      cout << endl;
      
    }else if(current.name == DOSO){
      cout << endl;
      cout << "You landed on Dean of Students Office and you got a free pass!" << endl;
      cout << "You now have:" << SPACE << "$" << players[playerTag].money << endl;
      cout << endl;
    } 
  }
}


int winner (Player players[], int numPlayers)
{
  int index; 
  int winnerCash = 0;
  bool gameOver = false;
  //linear search to see who won
  for(int i = 0; i < numPlayers; i++){
    if(players[i].money == 0){
      gameOver = true;
    }
  }
  
  if(gameOver != false){
    for(int j = 0; j < numPlayers; j++){
      if(players[j].money > winnerCash){
        winnerCash = players[j].money;
        index = j;
        cout << "Player " << index << " has won the game!";
        return index;
      }
    }
  }
  return -1; //for clarity
}

void takeTurn(Player players[], int playerTag, GameBoard boardInfo[])
{
  int firstRoll = 0;
  int secondRoll = 0;
  int sumRoll = 0;
  
  cout << players[playerTag].pName << "'s turn" << endl;
  cout << "You currenly have:" << SPACE << "$" << players[playerTag].money << endl;
  cout << "Press enter to roll the first dice...";
  cin.ignore();
  firstRoll = dice();
  cout << endl;
  cout << "Your first roll is: [" << firstRoll << "]";
  cout << endl << endl;
  cout << "Press enter to roll the second dice...";
  cin.ignore();
  secondRoll = dice();
  cout << endl;
  cout << "Your second roll is: [" <<  secondRoll << "]";
  cin.ignore();
  sumRoll = firstRoll + secondRoll;
  players[playerTag].position += sumRoll;
  cout << "Total: [" << firstRoll <<" + " << secondRoll << "]" << endl;
  cout << "You move for" << SPACE << sumRoll << SPACE << "places" << endl;
}

void property(Player players[], int playerTag, GameBoard current, GameBoard boardInfo[])
{
  char purchaseChoice;
  
  if((current.purchaseCost) < (players[playerTag].money)){
    cout << endl << "You landed on" << SPACE << current.name << endl;
    cout << "Wish to purchase this property for " 
         << current.purchaseCost << "[Y/N]:" << SPACE;
    cin >> purchaseChoice;
    cin.ignore();
    cout << endl;
    if(purchaseChoice == YES){
      current.owner = players[playerTag].playerTag;
      players[playerTag].money -= current.purchaseCost;
      cout << "You are the new owner of this property!" << endl << endl;
    }else{
      cout << "You chose not to purchase this property" << endl;
      cout << endl;
    }
  }else {
    cout << endl << "You landed on" << SPACE << current.name << endl;
    cout<<"Can't purchase this property because you do not have enough money"<<endl;
    players[playerTag].money = players[playerTag].money;
  }
  
  if(current.owner != 0 && current.owner != players[playerTag].playerTag){
    cout << endl << "You landed on" << SPACE << current.name << endl;
    cout << "you need to pay rent of" << SPACE << current.purchaseRent << endl;
    players[playerTag].money -= current.purchaseRent; 
    players[current.owner].money += current.purchaseRent; 
  }
}


