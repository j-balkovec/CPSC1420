// Jakob Balkovec
// lab15.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";
const int SIZE = 75;
const char YES = 'Y';
const string SPACE =  " ";
const int WIDTH = 5;

int lnSearch(string arr[], string target, int numE);

int main()
{
  cout << endl << endl;
  string arr[SIZE];
  string words;
  string target;
  char choice = YES;
  int count = 0;
  int index = 0;
  
  ifstream inFile;
  inFile.open(FILENAME);

  if(inFile.fail()){
    cout << "File error";
    cin.get();
    exit(1);
    
  }else{
    while(inFile >> words){
      arr[count] = words;
      count++;
    }
    inFile.close();
  }

  cout << "Index" << SPACE << "Word" << endl << endl;
    
    for(int i = 0; i < count; i++){
      cout << setw(WIDTH) << i << SPACE << arr[i] << endl;
    }
    cout << endl << endl;

  while (choice == YES){
    cout << "Enter the word you would like to search for: ";
    cin >> target;

    index = lnSearch(arr, target, count);

    if (index == -1){
      cout << "The word you searched for is not in the sentence!" << endl;
      
    }else{
      
      cout << endl << endl;
      cout << "The word you searched for: ("<< target <<  ") was found at the Index [" << index <<  "] ";
      cout << endl << endl;
    }
    
    cout << "Would you like to play again(Y/N): ";
    cin >> choice;
    cout << endl;
  }
  cout << endl << endl;
  return 0;
}

int lnSearch (string arr[], string target, int numE)
{
  int index = 0;
  while((index < numE)  && (arr[index] != target)){
    index++;
  }
  if(index < numE){
    return index;
  }else{
    return -1; // for clarity
  }
}

