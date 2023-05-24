//Jakob Balkovec
//lab2.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
  
  string word;
  int nm1, nm2;
  double dnum1, dnum2;
  
  
  cout << endl << endl;
  cout << endl << endl;
  
  cout <<"Please enter a word: ";
  cin >> word;
  
  cout <<"The word you entered is: " << word << endl;

  cout << "Please provide two whole numbers: ";
  cin >> nm1 >> nm2;
  
  cout <<"Division of " << nm1 << " by " << nm2 << " is " << nm1/nm2
       << endl;
  cout <<"Modulus of " << nm1 << " by " << nm2 << " is " << nm1%nm2
       << endl;
  
  cout << "Please provide two floating point numbers: ";
  cin >> dnum1 >> dnum2;
  
  cout << "Division of" << dnum1 << " by " << dnum2 << " is " << dnum1/dnum2
       <<endl;
  
  return 0;
}
