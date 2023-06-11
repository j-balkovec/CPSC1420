// {
//Jakob Balkovec
//lab10.cpp
//Driver Code
//Fix SegFault
// }

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

const std::string FILENAME = "/Users/jbalkovec/Desktop/plane/Labs:reeder/nums.txt";
const int arraySize = 30;

// {
// Prints array
// Templated for variability
// }
template<typename T>
static inline void print(T array) {
  std::cout << "\n[array]: ";
  for(auto const& iter : array) {
    std::cout << iter << " ";
  }
  std::cout << "\n\n";
}

// {
// Reads the given file
// }
static inline void file_read(std::vector<int> numbers) {
  std::ifstream input_file(FILENAME);  
  int normal_count = 0;
  try {
    if (input_file.good()) {
      int current_number = 0;
      while (input_file >> current_number){
        numbers[normal_count] = current_number;
        normal_count++;
      }
      
      input_file.close();
      print(numbers);
    } else{ 
      throw std::runtime_error("cannot read file!");
    }
  } catch(std::exception &e) {
    std::cout << "[error]: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

// {
// Finds odd and even numbers, stores them in a vector
// }
static inline void find_nums(std::vector<int> numbers) {
  std::vector<int> even_n;
  std::vector<int> odd_n;

  int even_c = 0;
  int odd_c = 0;

  for(auto i = 0; i < (int)numbers.size(); i++){     
    if(numbers[i]%2 == 0 && numbers[i] > 0){
        even_n[even_c] = numbers[i];
        even_c++;        
    } else if(numbers[i]%2 != 0 && numbers[i] > 0){
        odd_n[odd_c] = numbers[i];
        odd_c++;
        }
    }
  print(even_n);
  print(odd_n);
  return;
}

// {
// Main function of the program, calls worker() to execute
// Returns 0 upon successful execution
// }
int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]) {
  std::vector<int> numbers;
  file_read(numbers);
  find_nums(numbers);
  return EXIT_SUCCESS;
}

