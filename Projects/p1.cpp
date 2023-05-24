// Jakob Balkovec
// p1.cpp
/* The purpose of this programme is to create a short,
   funny story based on the users input*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string yourName, place, profession, university, animal, petname;
  int age;
  
  cout << endl << endl;
  cout << "Welcome to The Word Game";
  cout << endl;
  cout << "You will be asked to input some words!";
  cout << endl;
  
  cout << endl;
  cout << "Think of a name:  ";
  getline (cin, yourName);
  
  cout << "Think of a place (could be anywhere): ";
  getline(cin, place);
  
  cout << "Think of a university: ";
  getline (cin, university);
  
  cout << "Think of a profession: ";
  getline (cin, profession);
  
  cout << "Think of an animal: ";
  getline (cin, animal);
  
  cout << "Think of a petname: ";
  getline (cin, petname);
  
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
  cout << petname << ".";
  cout << endl;
  cout << "They both lived happpily ever after.";
  cout << endl << endl;
  
  return 0;
}
