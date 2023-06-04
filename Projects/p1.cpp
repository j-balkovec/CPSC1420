// { 
// Driver Code Starts 
// Jakob Balkovec
// p1.cpp
// The purpose of this programme is to create a short,
//   funny story based on the users input
//
// }

#include <iostream>
#include <string>


int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {

  std::string name, place, profession, university, animal, pet_name;
  int age;

  std::cout << "\n\nWelcome to The Word Game\n"
    << "You will be asked to input some words!\n\n";

  std::cout << "[Enter name]:  ";
  std::cin >> name;

  std::cout << "[Enter place]:  ";
  std::getline(std::cin, place);

  std::cout << "[Enter university]:  ";
  std::getline(std::cin, university);

  std::cout << "[Enter profession]:  ";
  std::getline(std::cin, profession);

  std::cout << "[Enter animal]:  ";
  std::cin >> animal;

  std::cout << "[Enter pet name]:  ";
  std::cin >> pet_name;

  try {
    std::cout << "[Enter age]:  ";
    std::cin >> age;
    while (std::cin.fail()) {
      std::cout << "[Enter an integer]:  ";
      std::cin >> age;
    }
  }
  catch (std::exception& e) {
    std::cout << "[Error]: age must be a integer\n";
  }

  std::cout << "\n\nThere once was a person named " << name << " who lived in " << place << ".\n"
    << "At the age of " << age << ", " << name << " graduated from " << university
    << " and went to work as a " << profession << ".\n"
    << "He then adopted a " << animal << " named " << pet_name << ".\n"
    << "They both lived happily ever after.\n\n";
  std::cout << std::flush; //flush buffer
  return 0;
}
