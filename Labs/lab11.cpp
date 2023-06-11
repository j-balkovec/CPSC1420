// {
//Jakob Balkovec
//lab11.cpp
//Driver Code
// }

#include <iostream>
#include <fstream> 
#include <string>  
#include <iomanip> 

const int ARRAYSIZE = 41;

const int COL = 9;
const int ROW = 6;

const int COL_WIDTH = 4;
const std::string FILENAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";

// {
// Reads the file and stores the integers in an array
// }
static inline int read_file(int numbers[ARRAYSIZE]) {
  std::ifstream input_file(FILENAME);  
  int normalCount = 0;
  int idx = 0;
  
  try{ 
    if (input_file.good()) {
      
      int current_number = 0;
      while (input_file >> current_number){
	numbers[normalCount] = current_number;
	normalCount++;;
      }
      
      input_file.close();
      
    }else{ 
      throw std::runtime_error("[cannot open file]");
    }
  }catch(std::exception &e) {
    std::cout << "[error]: " <<e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
  return idx;
}

// {
// Computes the sums in the array
// }
static inline void get_sum(int &idx, int size, int twod_arr[ROW][COL], int numbers[ARRAYSIZE])  {
  int sum = 0;
  
  for(int i = 0; i < ROW-1; i++){ //down
    for(int j = 0; j < COL && idx<size; j++){
      if(j == COL-1){
	twod_arr[i][j] = sum;
      }else {
	twod_arr[i][j] = numbers[idx++];
	sum += twod_arr[i][j];
      }
    }
    sum = 0;
  }
  
  for (int k = 0; k < COL; k++) { //across
    for (int l = 0; l < ROW-1; l++) {
      sum += twod_arr[l][k];
    }
    twod_arr[ROW-1][k] = sum;
    sum = 0;
  }
    
  for(int a = 0; a < ROW; a++){ //std::cout
    std::cout << std::endl;
    for(int b = 0; b < COL; b++){
      std::cout << std::setw(COL_WIDTH) << twod_arr[a][b] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "\n[sum of the array is in the bottom right corner: {" << twod_arr[ROW-1][COL-1] << "}]\n\n";
}

// {
// Main function of the program, executes the logic
// Returns 0 upon successful execution
// }
int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]) {
  int numbers[ARRAYSIZE] = {0};
  int twod_arr[ROW][COL] = {0};
  int size = sizeof(numbers)/sizeof(int);
  int idx = read_file(numbers);
  
  get_sum(idx, size, twod_arr, numbers);
  
  return EXIT_SUCCESS;
}


