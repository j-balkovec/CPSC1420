//Jakob Balkovec
//lab12.cpp

#include <iostream> 
#include <fstream> 
#include <string>  

using namespace std;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";
const int SIZE = 50;
double arr[SIZE] = {0};
const int DECIMAL = 3;

int readFile(string FILENAME, double arr[]);
void printArr(double arr[], int counter);
double total(double arr[], int counter);

int main()
{
  cout << endl << endl;

  int counter = 0;
  
  counter = readFile(FILENAME, arr);
  printArr(arr, counter);
  cout << endl;
  cout << "Total is:  " << total(arr, counter);
  
  cout << endl << endl;
  return 0;
}

int readFile(string FILENAME, double arr[])
{
  ifstream inputFile;  
  double number;
  int i = 0;
    inputFile.open(FILENAME);
    
    if (inputFile.good()) {
      
      while (inputFile >> number){
        arr[i] = number;
            i++;
      }
      inputFile.close();
      
    }else{ 
      cout << "Error...Cannot open file" << endl;
      cout << endl;
      exit(1);
    } 
    return i;
}

double total(double arr[], int counter)
{
  
  double total = 0;
  for (int counter = 0; counter < SIZE; counter++){
    total += arr[counter];
}
  
  return total;
}

void printArr(double arr[], int counter)
{
  for(int k = 0; k < counter; k++){
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(DECIMAL);
    cout << "Index [" << k << "]: " << arr[k] << endl;
  }
}

