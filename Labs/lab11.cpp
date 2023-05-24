// Jakob Balkovec
// lab11.cpp

#include <iostream> //cin, cout
#include <fstream> //file
#include <string>  //string headerfile
#include <iomanip> //setw()

using namespace std;

const int ARRAYSIZE = 41;
int numbers[ARRAYSIZE] = {0};
const int COL = 9;
const int ROW = 6;
int multiDArr[ROW][COL] = {0};
const int COL_WIDTH = 4;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

int main()
{
  cout << endl << endl;
    
  int numbers[ARRAYSIZE];
  
  ifstream inputFile(FILENAME);  
  int normalCount = 0;
  int idx = 0;

  if (inputFile.good()) {
    
    int current_number = 0;
    while (inputFile >> current_number){
            numbers[normalCount] = current_number;
            normalCount++;;
    }
    
    inputFile.close();

  }else{ 
    cout << "Error...Cannot open file" << endl;
    cout << endl;
    exit(1);
  }
  
    int size = sizeof(numbers)/sizeof(int);
    int sum = 0;
    
    for(int i = 0; i < ROW-1; i++){ //down
        for(int j = 0; j < COL && idx<size; j++){
          if(j == COL-1){
            multiDArr[i][j] = sum;
          }else {
            multiDArr[i][j] = numbers[idx++];
            sum += multiDArr[i][j];
          }
        }
        sum = 0;
        }
    
    for (int k = 0; k < COL; k++) { //across
      for (int l = 0; l < ROW-1; l++) {
        sum += multiDArr[l][k];
      }
        multiDArr[ROW-1][k] = sum;
        sum = 0;
    }
    
    for(int a = 0; a < ROW; a++){ //cout
      cout << endl;
      for(int b = 0; b < COL; b++){
        cout << setw(COL_WIDTH) << multiDArr[a][b] << " ";
      }
      cout << endl;
    }
    
        cout << endl << "The sum of the array is in the bottom right corner " 
             << "The sum is: " << multiDArr[ROW-1][COL-1] << endl;
        
        
        cout << endl << endl;
        return 0;
}


