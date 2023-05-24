//Jakob Balkovec
//lab4.cpp

#include <iostream>
#include <string>
using namespace std;

int nm1 = 0, nm2 = 0;
int temp;

int main()
{
  cout << endl << endl;
  cout << "Please provide two intiger values: ";
  cin >> nm1 >> nm2;
  cout << endl;
  
  if( nm1 < nm2){ // To always divide the higher number with the lower one
    temp = nm2;
    nm2 = nm1;
    nm1 =temp;
  }
  
  if (nm1 % nm2 == 0){
    cout << endl;
      cout << "Yes, " << nm1 << " is a multiple of " << nm2
           << " the other factor is " << (nm1/nm2) << "." << endl;
      cout << endl;
      
  }else{
    cout << nm1 << " is NOT a multiple of " << nm2 << "." << endl;
    cout << endl;
  }
  
  return 0;
}
