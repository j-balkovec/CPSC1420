//Jakob balkovec
//p1x.cpp
//The purpose of this programme is similar to the p1
//but it let's the user continue playing

#include <iostream>
#include <string>
using namespace std;

const char YES = 'Y'; //used for re-playing the game

int main()
{
  string yourName, place, profession, university, animal, petName;
  int age;
  char choice;
  
  cout << endl << endl;
  cout << "Welcome to The Word Game" << endl;
    cout << "You will be asked to input some words!" << endl;
    
    do{
      cout << endl;
      cout << "Think of a name:  ";
      cin >> yourName;
      cin.ignore(); // to fix the output if the user decides to play again
      
      cout << "Think of a place (could be anywhere): ";
      getline(cin, place);

      cout << "Think of a university: ";
      getline(cin, university);
      
      cout << "Think of a profession: ";
      getline(cin, profession);
      
      cout << "Think of an animal: ";
      getline(cin, animal);
      
      cout << "Think of a pet name: ";
      getline(cin, petName);
      
      cout << "Think of a number: ";
      cin >> age;
      
      cout << endl <<endl;
      cout << "There once was a person named ";
      cout << yourName;
      cout << " who lived in ";
      cout << place << ".";
      cout << endl;
      cout << "At the age of ";
      cout << age;
      cout << ", ";
      cout << yourName;
      cout << " went to ";
      cout << university << ".";
      cout << endl;
      cout << yourName;
      cout << " graduated and went to work as a(n) ";
      cout << profession << ".";
      cout << endl;
      cout << "Then ";
      cout << yourName;
      cout << " adopted a(n) ";
      cout << animal;
      cout << " named ";
      cout << petName << ".";
      cout << endl;
      cout << "They both lived happpily ever after.";
      cout << endl << endl;
      
      cout << endl;
      cout << "Do you want to play again? (Y/N): ";
      cin >> choice;

      
      
    } while (choice == YES);
    cout << "Goodbye, thanks for playing!" << endl;
    
    return 0;
}
