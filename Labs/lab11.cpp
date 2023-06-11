// {
//Jakob Balkovec
//lab12.cpp
//Driver Code
// }

#include <iostream> 
#include <fstream> 
#include <string>  
#include <vector>

static std::string const FILENAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";
static int const SIZE = 50;
static int const DECIMAL = 3;

// {
// Reads the file
// }
static inline void read_file(std::string const FILENAME, std::vector<double> arr) {
  std::ifstream inputFile;  
  double number;
  int i = 0;

  try {
    inputFile.open(FILENAME);
    if (inputFile.good()) {
      
      while (inputFile >> number){
        arr.at(i) = number;
            i++;
      }
      inputFile.close();
    }else{ 
      throw std::runtime_error("cannot open file");
    } 
  } catch(std::exception &e) {
    std::cout << "\n[error]: {" << e.what() << "}\n";
    std::exit(EXIT_FAILURE);
  }
  return;
}

// {
// Computes the total 
// }
static inline double total(std::vector<double> arr) {
  double total = 0;
  for (auto iter : arr){
    total += iter;
    }
  return total;
}

// {
// Prints the array
// }
static inline void print_arr(std::vector<double> arr) {
  for(auto i = 0; i < arr.size(); i++){
    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(DECIMAL);
    std::cout << "[index: " << i << "]:  {" << arr[i] << "}\n";
  }
  return;
}

// {
// Main function of the program, executes the logic
// Returns 0 upon successful execution
// }
int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]) {
  std::vector<double> arr;

  read_file(FILENAME, arr);
  print_arr(arr);
  std::cout << "\n[total]:  " << total(arr) << "\n\n";
  
  return EXIT_SUCCESS;
}
