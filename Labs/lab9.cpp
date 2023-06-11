// {
//Jakob Balkovec
//lab9.cpp
//Driver Code
// }

#include <iostream>
#include <string>

// {
// Gets the input from the user
// }
static inline void input(std::string &val1, std::string &val2) {
  std::cout << "\n\n[enter two std::string values with a [Space] in-between]: ";
  std::cin >> val1;
  std::cin >> val2;
  return;
}

// {
// Prints the strings
// }
static inline void print(std::string &val1, std::string &val2) {
  std::cout << "\n[{str1} = " << val1 << " and {str2} = " << val2 << "]";
  return;
}

// {
// The brains of the program, covers all the logic
// }
static inline void worker() {
  std::string str1, str2;
 
  input(str1, str2);
  std::cout << "*** [before] ***\n";
  print(str1, str2);
  std::cin.ignore();

  std::swap(str1, str2);
  std::cin.ignore();
  std::cout << "*** [after] ***\n";
  print(str1, str2);
  std::cin.ignore();
}

// {
// Main function of the program, calls worker() to execute
// Returns 0 upon successful execution
// }
int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]){
  worker();
 return EXIT_SUCCESS;
}
