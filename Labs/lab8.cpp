//lab8.cpp
//Jakob Balkovec

#include <iostream>
#include <string>

using namespace std;

void welcome();
void goodbye();
int input();
int summation (int nm1);

const int maxNum = 25;
const int minNum = 5;
const char YES = 'Y';

int main()
{
  welcome ();
  char choice;
  do{
    
    int nm1;
    nm1 = input();
    summation(nm1);
    
    cout << endl;
    cout << "Do you want to play again? (y/n) ";
    cin >> choice;
    cout << endl;
  }while (choice == YES);
  
  goodbye();

  cout << endl << endl;
  return 0;
}

void welcome()
{
  cout << endl << endl;
  cout <<  "Welcome to Lab 8! ";
  cout << endl << endl;

}

void goodbye()
{
  cout << "Goodbye, thank you for playing! ";
  cout << endl;
}

int input()
{
    int nm1;
    cout << "Please enter a number from 5 to 25: ";
    cin >> nm1;
    
    while(nm1 < minNum || nm1 > maxNum){
      cout << "Please enter a value in-between 5 and 25: ";
      cin >> nm1;
      cout << endl;
    }
    
    return nm1;
}

int summation (int nm1)
{
  int sum = 0;
  for(int i = 1; i <= nm1; i++){
    sum += i;
  }
  cout << endl;
  cout << "The sum from 1 to "<< nm1 << " is " << sum << endl;
  
  return sum;
}
