//Jakob Balkovec
//lab13.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ROWS = 5;
const int COLS = 8;
const int WIDTH = 5;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

void readFile(const string FILENAME, int arr [][COLS]);
void display(int arr [][COLS]);
int getTotal(int arr[][COLS]);

int main()
{
  int arr[ROWS][COLS] = {0};
  
  readFile(FILENAME, arr);
  display(arr);
  cout << setw(WIDTH) << getTotal(arr);
  
  cout << endl << endl;
  return 0;
}
void readFile(const string FILENAME, int arr[][COLS]){
  ifstream inputFile(FILENAME);
  
  if (inputFile.good()){
    for(int i = 0; i < ROWS; i++){
      for(int j = 0; j < COLS; j++){
        inputFile>>arr[i][j];
      }
    }
    cout << arr[i][j];
    inputFile.close();
  }else{
    cout << "Error...Cannot open file" << endl;
    cin.ignore();
    cout << endl;
    exit(1);
  }
}

void display(int arr[][COLS]){
  int rowTotal;
  int colTotal;
  
  for (int i = 0; i < (COLS * 5); i++){
    cout << " ";
  }
  cout << "Total" << endl;
  cout << endl;
  for (int i = 0; i < ROWS; i++){
    rowTotal = 0;
    for (int j = 0; j < COLS; j++){
      rowTotal += arr[i][j];
      cout << setw(WIDTH) << arr[i][j];
    }
    cout << setw(WIDTH) << rowTotal << endl;
  }
  
  for (int k = 0; k < COLS; k++){
    colTotal = 0;
    for (int l = 0; l < ROWS; l++){
      colTotal += arr[l][k];
    }
    cout << setw(WIDTH) << colTotal;
  }
}

int getTotal(int arr [][COLS]){
  int total = 0;
  for (int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLS; j++){
      total += arr[i][j];
    }
  }
  return total;
}
