//Jakob Balkovec
//lab3.cpp

#include <iostream>
#include <string>
using namespace std;

int nm1, nm2, temp; //nm1 is int1, nm2 is int2 and temp is a temporary variable

int main()
{
    cout << endl << endl;
    cout << "Please provide two intiger values: ";
    cin >> nm1 >> nm2;
    cout << endl;

    while(nm1 == 0 || nm2 == 0) //To avoid floating point exception
    {
        cout << "Cannot divide by zero!";
        cout << endl;
        cout << "Please provide two new intigers: ";
        cin >> nm1 >> nm2;
        }
    
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
        cout << nm1 << " is not a multiple of " << nm2 << ".";
        cout << endl;
    }

return 0;
}
