// {
//Jakob Balkovec
//lab15.cpp
//Driver Code
// }

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

// {
// A class representing a word search game.
// }
class WordSearch {
  private:
    const std::string FILENAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";
    const char YES = 'Y';
    const int WIDTH = 5;

    std::vector<std::string> arr;
    void read_file();
    int linear_search(std::string target);
    void print();
  public:
    explicit WordSearch();
    void run();
};

// {
// Initializes a new instance of the WordSearch class.
// }
WordSearch::WordSearch() {
  const int INITIAL = 200;
  arr.resize(INITIAL);
}

// {
// Reads a file and stores its contents in the "arr" vector.
// }
void WordSearch::read_file() {
  try {
    std::ifstream data_file;
    data_file.open(FILENAME);

    if(data_file.fail()){
      throw std::runtime_error("file error");

    } else {
      std::string word;
      while(data_file >> word){
        arr.push_back(word);
      }
      data_file.close();
    }
  } catch (std::exception &e) {
    std::cout << "[error]: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

// {
// A linear search function that finds the first occurrence of the given 
// target string in the array.
// }
int WordSearch::linear_search(std::string target) {
  int index = 0;
  while((index < arr.size()) && (arr.at(index) != target)){
    index++;
  }
  if(index < arr.size()){
    return index;
  } else {
    return -1; // for clarity
  }
}

// {
// Prints the index and word of each element in the `arr` vector.
// }
void WordSearch::print() {
  std::cout << "Index" << std::setw(WIDTH) << "Word" << std::endl << std::endl;

  for(int i = 0; i < arr.size(); i++){
    std::cout << std::setw(WIDTH) << i << std::setw(WIDTH) << arr[i] << std::endl;
  }
  std::cout << std::endl << std::endl;
}

// {
// Runs the WordSearch program by reading in a file, printing its contents,
// and allowing the user to search for a word. It loops until the user chooses
// to stop playing.
// }
void WordSearch::run() {
  std::string target;
  char choice = YES;
  int index = 0;

  read_file();
  print();

  while (choice == YES) {
    std::cout << "\n[enter the word you would like to search for]: ";
    std::cin >> target;

    try {
      index = linear_search(target);
      std::cout << "\n\n[the word you searched for: (" << target <<  ") was found at the index {" << index <<  "}]\n\n";
    } catch (std::runtime_error& e) {
      std::cout << e.what() << std::endl;
    }

    std::cout << "[would you like to play again(Y/N)]: ";
    std::cin >> choice;
  }
  std::cout << "\n\n";
}

// {
// The main function for running the WordSearch program.
// }
int main() {
  WordSearch wordSearch;
  wordSearch.run();
  return EXIT_SUCCESS;
}
