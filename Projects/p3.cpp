A//Jakob Balkovec
//p3.cpp

//this programe replicates a game of chutes&ladders
//where both players roll the dice and move up the board
//if a player reaches a chute he drops a couple of fields
//if a player reaches a ladder he gains a couple of fields

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcome();
void goodbye();
int spin();
bool player();
string orderPlay();
void CheckChutes(int &newPos);
void CheckLadders(int &newPos);

const char YES = 'Y';
const int MAX = 6;
const int MIN = 1;
int dice, newPos1, newPos2;
const int END = 100;
char ans;
string playerName1, playerName2;


int main()
{ 
  cout << endl << endl;
  welcome();
  
  do{
    srand(time(0));
    newPos1 = 0;
    newPos2 = 0;
    string playerTurn = orderPlay();
    
    while (newPos1 < END && newPos2 < END){
      
      if (playerTurn == "p1" || playerTurn == "P1"){
        cout << endl;
        cout << playerName1 << "'s turn" << endl;
        cout << endl;
        
        cout << "Press enter to spin...";
        cin.get();
        cout << endl;
        spin();
        cout << "You threw/spun " << dice << ".";
        cout << endl;
        
        if((newPos1 + dice) > END){
          cout << "Unfortunatey passed a 100...can't do that " << endl;
          cout << "You need to throw" << END - newPos1 << endl;
        }else{
          newPos1 += dice;
          CheckChutes(newPos1);
          CheckLadders(newPos1);
        }
        cout << endl;
        cout << playerName1 << ", your new location is: " << newPos1 << endl; 
        playerTurn = "p2";
        cout << endl << "Press enter to continue... ";
        cin.ignore();
        
        
      }else{
        cout << endl;
        cout << playerName2 << "'s turn" << endl;
        cout << endl;
        
        cout << "Press enter to spin...";
        cin.get();
        spin();
        cout << endl;
        cout << "You threw/spun " << dice << ".";
        cout << endl;
        
        if((newPos2 + dice) > END){
          cout << "Unfortunatey passed a 100...can't do that" << endl;
          cout << "You need to throw" << END - newPos2 << endl;
        }else{
          newPos2 += dice;
          CheckChutes(newPos2);
          CheckLadders(newPos2);
        }  
        cout << playerName2 << ", your new location is: " << newPos2 << endl;
        playerTurn = "p1";
        cout << endl << "Press enter to continue... ";
        cin.ignore();
        
      }
    }
    
    if(newPos1 == END){
      cout << endl;
      cout << playerName1 << " reached a hundred and won!"
           << endl << "Congratulations";
    }else if(newPos2 == END){
      cout << endl;
      cout << playerName2 << " reached a hunderd and won!" 
           << endl << "Congratulations";
    }
    cout << endl << endl;
    cout << "Do you want to play again? (Y/N) ";
    cin >> ans;
    cout << endl;
  }while (ans == YES);
  
  if(ans != YES)
    goodbye();
  
  return 0;
}

void welcome(){
  
  cout << "Welcome to the chutes and ladders game. Both " << endl;
  cout << "players start at 0, and the first one to 100 " << endl;
  cout << "wins the game. However, if you land on a chute," << endl;
  cout << "your player will move down, but a ladder " << endl;
  cout << "will move you up." << endl;
  cout << endl << "Press enter to continue...";
  cin.get();
  cout << endl;
}
void goodbye(){
  
  cout << endl;
  cout << "Thank you for playing, I hope you enjoyed it!";
  cout << endl << endl;
}
int spin(){
  
  dice = rand() % ((MAX - MIN) + 1) + MIN;
}    //better way to get random numbers in c++
//     while(time.srand(NULL) == dice && time.srand(NULL) > dice){
//         time.srand(NULL){
//             dice = rand() % ((MAX - MIN) + 1) + MIN
//     } else{ 

//     }
//     }
//     return dice;
// }

// bool player(){
//     while((time.srand(NULL) == dice && time.srand(NULL) > dice) == true){
//         return true;
//     }else{
//         return false;
//     }
// }return bool player(T/F)

string orderPlay(){
  string playerTurn;
  cout << "Please initiate which player is going first (P1/P2): ";
  cin >> playerTurn;
  cout << endl;
  
  if (playerTurn == "P1" || playerTurn == "p1"){
    cout << "Player 1 enter your name: ";
    cin >> playerName1;
    cout << endl;
    cout << endl;
    
    
    cout << "Player 2 enter your name: ";
    cin >> playerName2;
    cout << endl;
    cout << endl;

  }else{
    cout << "Player 2 enter your name: ";
    cin >> playerName2;
    cout << endl;
    cout << endl;

    
    cout << "Player 1 enter your name: ";
    cin >> playerName1;
    cout << endl;
    cout << endl;
}
  
  
  return playerTurn;
}

void CheckChutes (int &NewPos)
{
    //checks for chutes
  
  if (NewPos == 98){
    NewPos = 78;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 95){
    NewPos = 75;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 93){
    NewPos = 73;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 87){
    NewPos = 24;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 64){
    NewPos = 60;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 62){
    NewPos = 19;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 56){
    NewPos = 53;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 49){
    NewPos = 11;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 48){
    NewPos = 26;
    cout << "You landed on a chute, and have to move down" << endl;
  }else if (NewPos == 16){
    NewPos = 6;
    cout << "You landed on a chute, and have to move down" << endl;
  }else
    NewPos = NewPos;
  
}

void CheckLadders (int &NewPos)
{
  //checks for ladders
  
  if (NewPos == 1){
    NewPos = 38;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 4){
    NewPos = 14;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 9){
    NewPos = 21;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 23){
    NewPos = 44;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 28){
    NewPos = 84;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 36){
    NewPos = 44;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 51){
    NewPos = 66;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 71){
    NewPos = 90;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else if (NewPos == 80){
    NewPos = END;
    cout << "You landed on a ladder, and get to move up the board!" << endl;
  }else
    NewPos = NewPos;
  
}
