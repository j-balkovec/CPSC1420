// Jakob Balkovec
// lab6.cpp

#include <iostream>
#include <string>
using namespace std;

const char YES = 'Y';
char choice;
int nm1 = 0, nm2 = 0, temp;

int main()
{
  cout << endl << endl;
  do{
    
    cout << "Please provide two intiger values, that are a multiple of one another: ";
    cin >> nm1 >> nm2;  

    while(nm1 % nm2 != 0){ // rules for multiples
      cout << "Please provide two different intiger values, that are a multiple of one another: ";
      cin >> nm1 >> nm2;
      
    if( nm1 < nm2){ // To always divide the higher number with the lower one
      temp = nm2;
      nm2 = nm1;
      nm1 =temp;
    }
    }
    

    if (nm1 % nm2 == 0){
      cout << endl;
      cout << nm1 << " is a multiple of " << nm2
           << " the other factor is " << (nm1/nm2) << "." << endl;
      cout << endl;
    }
    
    
    cout << "Wish to play again? (Y/N): ";
    cin >> choice;
    cout << endl;
    
    
    
  }while(choice == YES);

  cout << "Goodbye, thanks for playing!" << endl;
  cout << endl << endl;
  
  
  
  return 0;
}