// {
//Jakob Balkovec
//lab3.cpp
//Driver Code
// }

#include <iostream>
#include <string>

// {
// Gets string input
// Templated so it can be used for multiple types
// }
template <typename T>
void get_input(T& value) {
    std::cout << "\n[enter int]: ";
    std::cin >> value;
}

// {
// Prints Result
// Templated so it can be used for multiple types
// }
template <typename T>
void print_result(const T& value1, const T& value2) {
    std::cout << "\n[" << value1 << " is a multiple of " << value2
              << " the other factor is " << (value1 / value2) << "]\n\n";
}

// {
// Checks if the two numbers are multiples of each other
// Templated so it can be used for multiple types   
// }
template <typename T>
void check_multiple(const T& value1, const T& value2) {
    if (value1 % value2 == 0) {
        print_result(value1, value2);
    } else {
        std::cout << "[" << value1 << " is NOT a multiple of " << value2 << "]\n\n";
    }
}

// {
// Main function of the program
// Returns 0 upon successful execution
// }
int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]) {
    int nm1, nm2;
    get_input(nm1);
    get_input(nm2);
    check_multiple(nm1, nm2);
    return EXIT_SUCCESS;
}

