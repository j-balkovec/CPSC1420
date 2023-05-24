// Jakob Balkovec
// lab10.cpp

#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

const string FILENAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";
const int arraySize = 30;

int main()
{
  cout << endl << endl;
  
  int numbers[arraySize];
  int evenNum[arraySize];
  int oddNum[arraySize];
  int negNum[arraySize];
  
  ifstream inputFile(FILENAME);  
  int normalCount = 0;
  
  if (inputFile.good()) {

    int current_number = 0;
    while (inputFile >> current_number){
      numbers[normalCount] = current_number;
      normalCount++;
    }
    
    inputFile.close();
    //prints the original array
    cout << "The original array is:  "; //please don't deduct points for this :/
        for (int count = 0; count < normalCount; count++){
          cout << numbers[count] << ", ";
        }
        cout << endl << endl;
        
  }else{ 
    cout << "Error..." << endl;
  }
  
  int evenCount = 0;
  int oddCount = 0;
    int negCount = 0;
    
    
    //loops through the array
    for(int i = 0; i < normalCount; i++){
      
      //even nums       
      if(numbers[i]%2 == 0 && numbers[i] > 0){
            evenNum[evenCount] = numbers[i];
            evenCount++;
            
            //odd nums
      }else if(numbers[i]%2 != 0 && numbers[i] > 0){
        oddNum[oddCount] = numbers[i];
        oddCount++;

        //neg nums
      }else if (numbers[i] < 0){
        negNum[negCount] = numbers[i];
        negCount++;
        
        //zeros
        
      }else if (numbers[i] == 0){}
    }
    //even nums print
    cout << "Even Array: " << endl;
    for(int i = 0; i < evenCount; i++){
      cout<< "index " << "[" << i << "]"<<": "<< evenNum[i] << endl;
    }

    //odd nums print
    cout << endl << "Odd Array: " << endl;
    for(int i = 0; i < oddCount; i++){
      cout<< "index " << "[" << i << "]"<<": "<< oddNum[i] << endl;
    }

    //neg nums print
    cout << endl << "Negative Array: " << endl;
    for(int i = 0; i < negCount; i++){
        cout<< "index " << "[" << i << "]"<<": "<< negNum[i] << endl;
    }
    
    cout << endl << endl;
    return 0;
}

