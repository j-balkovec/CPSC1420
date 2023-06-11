// {
//Jakob Balkovec
//lab13.cpp
//Driver Code
// }

#include <iostream>
#include <fstream>
#include <iomanip>
#include <array>
#include <string>

const int ROWS = 5;
const int COLS = 8;
const int WIDTH = 5;

// {
// Reads the contents of a file and stores the values in a 2D array.
// @param file the file to be read
// @param arr the 2D array to store the file contents in
// @throws std::runtime_error if the file is not found
// }
static inline void read_file(const std::string& file, std::array<std::array<int, COLS>, ROWS>& arr) {
  try {
    std::ifstream data_file(file);
    if (!data_file) {
        throw std::runtime_error("File not found");
    }
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        data_file >> arr[i][j];
      }
    }
    data_file.close();
  } 
  catch(const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    std::exit(1);
  }
}

//{
// Displays a 2D array of integers with row and column totals. 
// @param arr The 2D array of integers to display.
// @return void
// @throws None
// }
void display(const std::array<std::array<int, COLS>, ROWS>& arr){
  int row_total, col_total;

  for (int i = 0; i < COLS * 5; ++i) {
    std::cout << ' ';
  }
  std::cout << "[total]\n\n";
  for (int i = 0; i < ROWS; ++i) {
    row_total = 0;
    for (int j = 0; j < COLS; ++j) {
      row_total += arr[i][j];
      std::cout << std::setw(WIDTH) << arr[i][j];
    }
    std::cout << std::setw(WIDTH) << row_total << '\n';
  }

  for (int k = 0; k < COLS; ++k) {
    col_total = 0;
    for (int l = 0; l < ROWS; ++l) {
      col_total += arr[l][k];
    }
    std::cout << std::setw(WIDTH) << col_total;
  }
}

// {
// Calculates the total sum of all elements in a 2D grid.
// @param grid a 2D array of integers representing the grid
// @return an integer representing the total sum of all elements in the grid
// @throws none
// }
static inline int get_total(const std::array<std::array<int, COLS>, ROWS>& grid) {
  int total = 0;
  for (int i = 0; i < ROWS; ++i) {
    for (int j = 0; j < COLS; ++j) {
        total += grid[i][j];
      }
    }
  return total;
}

// {
// The main function of the program, which reads an input file, stores it in a 
// two-dimensional array of integers, displays the array, calculates the total 
// sum of the array, and prints the result. 
// @return 0 since the program has finished successfully.
// @throws None.
// }
int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  static const std::string file = "/home/fac/sreeder/class/cs1420/lab11input.dat";
  std::array<std::array<int, COLS>, ROWS> arr{};

  read_file(file, arr);
  display(arr);
  std::cout << std::setw(WIDTH) << get_total(arr);

  std::cout << std::endl << std::endl;
  return 0;
}
