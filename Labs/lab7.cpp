//Jakob Balkovec
//lab7.cpp

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const int COL_WIDTH = 3;
const int MIN = 1;
const int MAX = 100;

int main(){
  
  int nm1 = 0;
  
  cout << "Please enter a number (number from 1 to 100): ";
  cin >> nm1;

  while(nm1 < MIN || nm1 > MAX){
    cout << "Nuber from 1 to 100: ";
    cin >> nm1;
  }
  /////////////////////////////////////////////////////////
  cout << endl << endl;
  cout << "Pattern #1" << endl;
  cout << endl;
 
  for(int i = 0; i < nm1; i++){
   cout << nm1;
  }
  cout << endl << endl;
///////////////////////////////////////////////////////// 
  cout << endl;
  cout << "Pattern #2" << endl;
  cout << endl;   
  for(int i = 0; i < nm1; i++){
    cout << "1" << endl;
  }
  /////////////////////////////////////////////////////////
  cout << endl;
  cout << "Pattern #3" << endl;
  cout << endl; 
  
  cout << "  ";
  for (int i = 1; i <= nm1; i++){ // down
    cout << setw(COL_WIDTH) << i << "  ";
  }
  cout << endl;
  
  for (int j = 1; j <= nm1; j++){
    cout << j;
    for(int i = 1; i <= nm1; i++){ // across
      cout << " " << setw(COL_WIDTH) << i*j << " ";
    }
    cout << endl;
  }
  /////////////////////////////////////////////////////////
  cout << endl;
  cout << "Pattern #4" << endl;
  cout << endl; 
  
  for(int i = 1; i <= nm1; i++){
    for(int j = 0; j < i; j++){
      cout << i;
    }
    cout << endl;
  }
  
  cout << endl;
  /////////////////////////////////////////////////////////
  cout << endl;
  cout << "Pattern #5" << endl;
  cout << endl; 
  
  for(int i = 1; i <= nm1; i++){
    for(int j = 1; j < i; j++){
      cout << " ";
    }
    cout << i << endl;
  }

  for(int i = nm1 -1; i >= 1; i--){
    for(int j = 1; j < i; j++){
      cout << " ";
    }
    cout << i << endl;
  }
  ///////////////////////////////////////////////////////// 
  cout << endl;
  cout << "Pattern #6" << endl;
  cout << endl;
  
  //top left
  for (int i = nm1; i >= 2; i--){ // not slanted
    for(int j = 2; j <= i; j++){
      cout << " ";
    }
    cout << i << endl;
  }
  // top right
  for(int i = 1; i <= nm1; i++){
    for(int j = 1; j < i; j++){
      cout << " ";
    }
    cout << i << endl;
  }
  // bottom right
  for(int i = nm1-1; i >= 1; i--){
    for(int j = 2; j <= i; j++){
      cout << " ";
    }
    cout << i << endl;
}
  //bottom left
  for(int i = 2; i <= nm1-1; i++){ //doesnt work
    for(int j = 1; j < i; j++){
      cout << " ";
    }
    cout << i << endl;
  }
  
  
  return 0;
}
