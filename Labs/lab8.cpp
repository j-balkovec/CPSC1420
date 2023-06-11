// {
//Jakob Balkovec
//lab8.cpp
//Driver Code
// }

#include <iostream>
#include <string>

const int MAX = 300;
const int MIN = 5;
const char YES = 'Y';

// {
// Prompts the user with a welcome message
// }
static inline void welcome() {
  std::cout <<  "\n\n[welcome to Lab 8]\n";
  return;
}

// {
// Prompts the user with goodbye
// }
static inline void goodbye() {
  std::cout << "\n[goodbye]\n ";
  return;
}

// {
// Gets input from the user
// }
static inline void get_num(int &num) {
  try {
    std::cout << "\n[enter a number from 5 to 300]: ";
    std::cin >> num;
    if(num > MAX || num < MIN) {
      throw std::runtime_error("invalid");
    }
  } catch(std::exception &e) {
    std::cout << "[error]: " << e.what() << std::endl;
    get_num(num);
  }
  return;
}

// {
// Summs the numbers from 1 to ~num~
// }
static inline int summation (int nm1) {
  int sum = 0;
  for(auto i = 1; i <= nm1; i++){
    sum += i;
  }

  std::cout << "\n[sum from 1 to "<< nm1 << " is " << sum << "]\n\n";
  return sum;
}

// {
// Prompts the user to enter y or n
// }
static inline char get_choice() {
  char c;
  std::cout << "[play again(y/n)]: ";
  std::cin >> c;
  return c; 
}

// {
// Main function of the program
// Returns 0 upon successful execution
// }
int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]) {
  welcome ();
  char choice;
  do{
    int nm1;
    get_num(nm1);
    summation(nm1);
    choice = get_choice();
  }while (choice == YES);
  
  goodbye();
  return EXIT_SUCCESS;
}
