// {
//Jakob Balkovec
//lab7.cpp
//Driver Code
// }

#include <string>
#include <iostream>
#include <iomanip>
#include <thread>

static const int SLEEP = 1;
static const int PATTERNS = 6;
static const int COL_WIDTH = 3;
static const int MIN = 1;
static const int MAX = 10;

// {
// Enum that corresponds to the pattern number
// Avoiding hardcoding
// }
enum PATTERN_ID {
  ONE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX
};

// {
// Gets a number and checks if its in-bounds
// }
static inline void get_num(int &num) {
  try {
    std::cout << "\n\n[enter a number from 1 to 10]: ";
    std::cin >> num;
    if(num > MAX || num < MIN) {
      throw std::runtime_error("invalid");
    }
  } catch(std::exception &e) {
    std::cout << "[error]: " << e.what() << std::endl;
    get_num(num);
  }
}

// {
// Prints title
// }
static inline void print_title(int param) {
  std::cout << "\n\n[pattern]: #" << param << "\n\n";
  return;
}

// {
// Prints a row of ~num~ numbers
// }
static inline void pattern_1(int num) {
  for(int i = 0; i < num; i++){
   std::cout << num;
  }
}

// {
// Prints a column of ~num~ numbers
// }
static inline void pattern_2(int num) {
  for(int i = 0; i < num; i++){
    std::cout << num << std::endl;
  }
}

// {
// Prints a table of ~num~ numbers with multiples
// }
static inline void pattern_3(int num) {
  std::cout << "  ";
  for (int i = 1; i <= num; i++){ // down
    std::cout << std::setw(COL_WIDTH) << i << "  ";
  }
  std::cout << std::endl;
  
  for (int j = 1; j <= num; j++){
    std::cout << j;
    for(int i = 1; i <= num; i++){ // across
      std::cout << " " << std::setw(COL_WIDTH) << i*j << " ";
    }
    std::cout << std::endl;
  }
}

// {
// Prints an increasing pattern of ~num~ numbers
// }
static inline void pattern_4(int num) {
  for(int i = 1; i <= num; i++){
    for(int j = 0; j < i; j++){
      std::cout << i;
    }
    std::cout << std::endl;
  }
  
  std::cout << std::endl;
}

// {
// Prints a half diamond of ~num~ numbers
// }
static inline void pattern_5(int num) {
  for(int i = 1; i <= num; i++){
    for(int j = 1; j < i; j++){
      std::cout << " ";
    }
    std::cout << i << std::endl;
  }

  for(int i = num -1; i >= 1; i--){
    for(int j = 1; j < i; j++){
      std::cout << " ";
    }
    std::cout << i << std::endl;
  }
}

// {
// Prints a zigzag pattern of ~num~ numbers
// }
static inline void pattern_6(int num) {
  for (int i = num; i >= 2; i--){ // not slanted
    for(int j = 2; j <= i; j++){
      std::cout << " ";
    }
    std::cout << i << std::endl;
  }
  // top right
  for(int i = 1; i <= num; i++){
    for(int j = 1; j < i; j++){
      std::cout << " ";
    }
    std::cout << i << std::endl;
  }
  // bottom right
  for(int i = num-1; i >= 1; i--){
    for(int j = 2; j <= i; j++){
      std::cout << " ";
    }
    std::cout << i << std::endl;
}
  //bottom left
  for(int i = 2; i <= num-1; i++){
    for(int j = 1; j < i; j++){
      std::cout << " ";
    }
    std::cout << i << std::endl;
  }
}

// {
// Main function of the program
// Returns 0 upon successful execution
// }
int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]) {
  int num = 0;
  get_num(num);

  for(auto i = 1; i < PATTERNS+1; i++) {
    try{
    switch(i) {
      case PATTERN_ID::ONE: {
        print_title(PATTERN_ID::ONE);
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
        pattern_1(num);
        break;
      }

      case PATTERN_ID::TWO: {
        print_title(PATTERN_ID::TWO);
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
        pattern_2(num);
        break;
      }

      case PATTERN_ID::THREE: {
        print_title(PATTERN_ID::THREE);
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
        pattern_3(num);
        break;
      }
      case PATTERN_ID::FOUR: {
        print_title(PATTERN_ID::FOUR);
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
        pattern_4(num);
        break;
      }
      case PATTERN_ID::FIVE: {
        print_title(PATTERN_ID::FIVE);
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
        pattern_5(num);
        break;
      }
      case PATTERN_ID::SIX: {
        print_title(PATTERN_ID::SIX);
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
        pattern_6(num);
        break;
      }
      default: {
        throw std::runtime_error("invalid PATTERN_ID obtained");
        std::this_thread::sleep_for(std::chrono::seconds(SLEEP));
      }
    }
    } catch (std::exception &e) {
      std::cout << "[error]: " <<  e.what() << std::endl;
    }
  }
  return EXIT_SUCCESS;
}
