// { 
// Driver Code Starts 
// Jakob Balkovec
// p1.cpp
// The purpose of this programme is to create a short,
//   funny story based on the users input. Similar to madlibz
// }

#include <iostream>
#include <string>
#include <limits>
#include <tuple>

/**
 * {
 * @brief a welcome message for The Word Game.
 * @return void
 * @throws none
 * }
 */
static inline void welcome() {
  std::cout << "\n\nWelcome to The Word Game\n"
    << "You will be asked to input some words!\n\n";
}

/**
 * {
 * @brief Returns a tuple containing user input for name, place, profession,
 *        university, animal, pet name, and age.
 * @return a tuple containing user input for name, place, profession,
 *         university, animal, pet name, and age.
 * @throws none
 * }
 */
static inline std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, int> input() {
  std::string name;
  std::string place;
  std::string profession;
  std::string university;
  std::string animal;
  std::string pet_name;
  int age;
  std::cout << "[Enter name]:  ";
  std::cin >> name;

  std::cout << "[Enter place]:  ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, place);

  std::cout << "[Enter university]:  ";
  std::getline(std::cin, university);

  std::cout << "[Enter profession]:  ";
  std::getline(std::cin, profession);

  std::cout << "[Enter animal]:  ";
  std::cin >> animal;

  std::cout << "[Enter pet name]:  ";
  std::cin >> pet_name;

  bool valid = false;
  while (!valid) {
    std::cout << "[Enter age]:  ";
    std::cin >> age;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "[Error]: age must be an integer\n";
    }
    else {
      valid = true;
    }
  }
  return std::make_tuple(name, place, profession, university, animal, pet_name, age);
}

/**
 * {
 * @brief Prints a story about a person's life based on the given input.
 * @param input a tuple containing the person's name, city of residence, job title,
 *              university they graduated from, type of pet adopted, and the pet's name,
 *              as well as the person's age at graduation
 * @throws N/A
 * }
 */
static inline void story(std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, int> input) {
  std::cout << "\n\nThere once was a person named " << std::get<0>(input) << " who lived in " << std::get<1>(input) << ".\n"
    << "At the age of " << std::get<6>(input) << ", " << std::get<0>(input) << " graduated from " << std::get<3>(input)
    << " and went to work as a " << std::get<2>(input) << ".\n"
    << "He then adopted a " << std::get<4>(input) << " named " << std::get<5>(input) << ". "
    << "They both lived happily ever after.\n\n";
  std::cout << std::flush; // flush buffer
}

/**
 * {
 * @brief Executes the run function. This function parses the input and passes it to
 *        the story function.
 * @return void
 * @throws None
 * }
 */
static inline void run() {
  std::tuple<std::string, std::string, std::string, std::string, std::string, std::string, int> words = input();
  story(words);
}

/**
 * {
 * The main function that runs The Word Game.
 * @return the exit status of the program
 * @throws None
 * }
 */
int main() {
  const char YES = 'Y';
  char choice = 'N';

  do {
    run();
    std::cout << "Do you want to play again? (Y/N): ";
    std::cin >> choice;

  } while (toupper(choice) == YES);
  std::cout << "\nGoodbye!\n\n";
  return EXIT_SUCCESS;
}
