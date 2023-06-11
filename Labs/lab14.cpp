// {
//Jakob Balkovec
//lab14.cpp
//Driver Code
// }

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <array>

// {
// A structure representing a person with a name, age, and number of cups of coffee
// }
struct Person{
  std::string name;
  int age;
  int coffee;
  // {
  // Overload the << operator to print a person's information
  // }
  friend std::ostream& operator<<(std::ostream& os, const Person& p)
  {
      os << std::left << std::setw(15) << p.name << ' ';
      os << std::setw(4) << p.age << ' ';
      os << std::setw(4) << p.coffee << ' ';
      os << std::endl;
      return os;
  }
};

const int SIZE = 150;

const int NAME_FIELD = 15;
const int AGE_FIELD = 4;
const int COFFEE_FIELD = 4;

const char SPACE = ' ';

// {
// Reads the list of people from the file and returns the number of people
// }
static inline void readPeople(std::array<Person, SIZE>& list) {
  try {
    int count = 0;
    const std::string file = "/home/fac/sreeder/class/cs1420/lab14input.dat";
    std::ifstream infile;
    infile.open(file);

    if (infile.fail()){
      throw std::runtime_error("file error");
    }

    while (infile >> list[count].name){
      infile >> list[count].age >> list[count].coffee;
      count++;
    }
    infile.close();
  } catch (std::exception &e) {
    std::cout << "[error]: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

// {
// Calculates the average age of a list of people
// }
static inline double average_age(const std::array<Person, SIZE>& list) {
  double average = 0;
  for (int i = 0; i < SIZE; i++){
    average += list[i].age;
  }
  return average / SIZE;
}

// {
// Calculates the total number of cups of coffee consumed by a list of people
// }
static inline int coffee_totals(const std::array<Person, SIZE>& list) {
  int total = 0;
  for(int i = 0; i < SIZE; i++){
    total += list[i].coffee;
  }
  return total;
}

// {
// Prints the information of a single person
// }
static inline void print(const std::array<Person, SIZE>& list) {
  for (auto client : list){
    std::cout << client;
  }
}

// {
//Executes the main function of the C++ program. 
// }
int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  std::array<Person, SIZE> clients{};
  readPeople(clients);

  std::cout << std::left << std::setw(NAME_FIELD) << "\n\n[name]" << SPACE << std::setw(NAME_FIELD) << "[age]" << SPACE << std::setw(AGE_FIELD) << "[coffee]" << std::endl << std::setw(COFFEE_FIELD);
  print(clients);
  std::cout << "\n[average]: " << average_age(clients) << "\n\n[total]: " << coffee_totals(clients) << "\n\n";
  return EXIT_SUCCESS;
}
