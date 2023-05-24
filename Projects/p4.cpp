//p4.cpp
//Jakob Balkovec

//this programe replicates a memory game
//there is 12 cards on the filed in a 6x2 configuration
//each player gets to take a turn and pick 2 random cards
//player with the most card pairs in the end wins the game

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>

/**
 * @note edit and improve on plane
*/
using namespace std;

const char YES = 'Y';
const int COL = 3;
const int ROW = 4;
const string FILE1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
const string FILE2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";
const string SPACE = "   ";
const int SIZE = 12;
const int SCREEN = 35;
const int MIN = 1;
const int MAX = 2;
const int BEG = 5;
const int PRO = 2;
const int COL_WIDTH = 4;


void welcome();
void goodbye();
void wait(int SECONDS);
void readFile(int fileChoice, char board[][COL]);
void clearScreen();
void display (const char board[][COL], int c1Row = -1, int c1Col = -1, int c2Row = -1, int c2Col = -1);
void getFirstCard(char board[][COL], int &c1Row, int &c1Col);
void getSecondCard(char board[][COL], int &c1Row, int &c1Col, int &c2Row, int &c2Col);
int randomFile(int &fileChoice);
bool checkBoard(char board[][COL]);

int main()
{
  int c1Row;
  int c1Col;
  int c2Row;
  int c2Col;
  int fileChoice;
  char choice;  

  char board[ROW][COL];
  
  cout << endl << endl;
  srand(time(NULL)); //seed for random file
  char level;  
  welcome();
  do{
    ///game
    cout << "Select [B] for beginner or [I] for expert: ";
    cin >> level;
    
    int randomski = randomFile(fileChoice); //gets a file turns it into a board
    readFile(randomski, board);
    
    cout << endl << endl; 
    display(board);
    
    while(checkBoard(board) == false){
      getFirstCard(board, c1Row, c1Col);
      while((c1Row > ROW-2 || c1Row < 0) || (c1Col > COL || c1Col < 0)){
        cout << endl;
        cout << "Invalid input, try again!" << endl;
        getFirstCard(board, c1Row, c1Col);
      }
      display(board, c1Row, c1Col);
      getSecondCard(board, c1Row, c1Col, c2Row, c2Col);
      while((c2Row > ROW-2) || (c2Col > COL)){
        cout << endl;
        cout << "Invalid input, try again!" << endl;
        getSecondCard(board, c1Row, c1Col, c2Row, c2Col);
      }
      display(board, c1Row, c1Col, c2Row, c2Col);
      if (level == 'B')
        wait(BEG);
      else
        wait(PRO);
      
      clearScreen();
      
      if(board[c1Col][c1Row] == board[c2Col][c2Row]){
        cout << endl << endl;
        cout << "It's a match!" << endl;
        board[c1Col][c1Row] = '_';
        board[c2Col][c2Row] = '_';
        cout << "Press enter to continue... ";
        cout << endl;
      }else{
        cout << "Unfortunatley wasn't a match, try again!" << endl;
        cout << "Press enter to continue...";
        cout << endl;
      }
      
      display(board);
    }
    cout << endl << endl;
    cout << "You cleared the board and won!" << endl;
    cout << "Congratualtions!" << endl;
    cout << endl << endl;
    cout << "Do you want to play again? (Y/N): ";
    cin >> choice;
    cout << endl << endl;
  }while(choice == YES);
  
  if (choice != YES){
    goodbye();
  }
  ///game
  cout << endl << endl;
  return 0;
}

void wait(const int SECONDS)
{
  clock_t endwait;
  endwait = clock() + SECONDS * CLOCKS_PER_SEC;
  while (clock() < endwait) {}    
}

void welcome()
{
  cout << "WELCOME TO THE MEMORY GAME!\n\n";
  cout << "* * *  * * *  * * *  * * * RULES * * *  * * *  * * *  * * *" << endl;
  cout << "\n-> Players start with 0 cards, ";
  cout << "the one with the most cards in the end wins." << endl;
  cout << "-> A player must always pick 2 cards" << endl;
  cout << "-> If a player gets 6 pairs he wins the game" << endl;
  cout << "-> A player cannot pick the same card that was already picked" << endl;
  cout << "-> If a palyer does not draw a pair, ";
  cout << "both of the cards are returned to the board" << endl;
  cout << endl;
  
  cout << endl << "Press enter to continue...";
  cin.get();
}

void goodbye()
{
  cout << endl;
  cout << "Thank you for playing, I hope you enjoyed it!";
  cout << endl << endl;
}

void readFile(int fileChoice, char board[][COL])
{
  
  ifstream inputFile;  
  int idx = 0;
  int idy = 0;
  
  if (fileChoice == 1){
    inputFile.open(FILE1);
    if (inputFile.good()){
      for(int k = 0; k < ROW; k++){
        for(int l = 0; l < COL && idx < SIZE; l++){
          inputFile >> board[k][l];
        }
      }
      inputFile.close();
      
    }else{ 
      cout << "Error...Cannot open file #1" << endl;
      cout << endl;
      exit(1);
    }
    
    }else{
    inputFile.open(FILE2);
    if (inputFile.good()){   
      for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL && idy < SIZE; j++){
          inputFile >> board[i][j];
        }
      }
      inputFile.close();
      
    }else{ 
      cout << "Error...Cannot open file #2" << endl;
      cout << endl;
      exit(1);
    }
  }
}


void clearScreen(){
  system("clear");
}

int randomFile(int &fileChoice){
  fileChoice = rand() % ((MAX - MIN) + 1) + MIN;
  return fileChoice;
}

void display (const char board[][COL], int c1Row, int c1Col, int c2Row, int c2Col) // user input for row and col
{
  cout << endl;    
  cout << SPACE; 
  for (int l = 0; l < COL; l++){
    cout << setw(COL_WIDTH + 2) << l;
  }
  cout << endl;
  for(int i = 0; i < ROW; i++){
    cout << endl;
    cout << setw(COL_WIDTH) << i << setw(COL_WIDTH);
    for (int k = 0; k < COL; k++){
      if(i == c1Col && k == c1Row){
        cout << setw(COL_WIDTH) << "[" << board[i][k] << "]";
      }else if(i == c2Col && k == c2Row){
        cout << setw(COL_WIDTH) << "[" << board[i][k] << "]";
      }else if(board[i][k] == '_'){
        cout << setw(COL_WIDTH) << "[" << "_" << "]";
      }else{
        cout << setw(COL_WIDTH) << "[" << "*" << "]";

      }
    }
    cout << endl;
  }
}

void getFirstCard(char board[][COL], int &c1Row, int &c1Col) //need to cout numbers for rows and cols
{
  cout << endl;
  cout << "Please pick the first card." << endl;
  cout << endl;
  cout << "ROW: ";
  cin >> c1Row;
  cout << "COL: ";
  cin >> c1Col;

  while(board[c1Col][c1Row] == '_'){
    cout << "This card has been already picked or turned over!" << endl;
    cout << "Please pick another card." << endl;
    cout << endl;
    cout << "ROW:";
    cin >> c1Row;
    cout << "COL:";
    cin >> c1Col;
  }
}

void getSecondCard(char board[][COL], int &c1Row, int &c1Col, int &c2Row, int &c2Col)
{
  cout << endl;
  cout << "Please pick the second card." << endl;
  cout << endl;
  cout << "ROW: ";
  cin >> c2Row;
  cout << "COL: ";
  cin >> c2Col;
  
  while((board[c2Col][c2Row] == '_')||((c1Row == c2Row) && (c1Col == c2Col))){
    cout << "This card has already picked or turned over!" << endl;
    cout << "Pick another card." << endl;
    cout << endl;
    cout << "ROW: ";
    cin >> c2Row;
    cout << "COL: ";
    cin >> c2Col;
    
  }
}

bool checkBoard(char board[][COL]){
  for (int i = 0; i < COL; i++){
    for(int j = 0; j < ROW; j++){
      if(board[i][j] != '_'){
        return false;
      }
    }
  }
  return true;
}
