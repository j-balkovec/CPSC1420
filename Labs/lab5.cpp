// {
//Jakob Balkovec
//lab5.cpp
//Driver Code
// }

#include <iostream>
#include <string>
#include <algorithm>

// {
// Gets string input
// Templated so it can be used for multiple types
// }
template <typename T>
void get_input(T& value) {
    std::cout << "\n[enter int]: ";
    std::cin >> value;
    return;
}

// {
// Prints Result
// Templated so it can be used for multiple types
// }
template <typename T>
void print_result(const T& value1, const T& value2) {
    std::cout << "\n[" << value1 << " is a multiple of " << value2
              << " the other factor is " << (value1 / value2) << "]\n\n";
    return;
}

// {
// Checks if the two numbers are multiples of each other
// Templated so it can be used for multiple types   
// }
template <typename T>
void check_multiple(const T& value1, const T& value2) {
    try {
        if (value1 % value2 == 0) {
            print_result(value1, value2);
        } else if(value1 == 0 || value2 == 0) {
            throw std::runtime_error("\n[cannot be zero!]\n");
        } else if(value1 < value2) {
            std::swap(value1, value2);
        } else {
            std::cout << "[" << value1 << " is NOT a multiple of " << value2 << "]\n\n";
        }
    }catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return;
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
  char choice = '\0';
  static const char Y = 'Y';
  do{
    int nm1, nm2;
    get_input(nm1);
    get_input(nm2);
    check_multiple(nm1, nm2);
    choice = get_choice();
  }while(choice == 'Y');
    return EXIT_SUCCESS;
}

