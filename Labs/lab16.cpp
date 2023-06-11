// {
// Jakob Balkovec
// lab16.cpp
// Driver Code
// }

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <typeinfo>

// {
// Represents a person
// }
class Person {
private:
    std::string name;
    int age;
    int coffee;
public:
    explicit Person() : name(""), age(0), coffee(0) {}
    Person(const std::string& name, int age, int coffee) : name(name), age(age), coffee(coffee) {}
    
    inline std::string getName() const { return name; }
    inline int getAge() const { return age; }
    inline int getCoffee() const { return coffee; }
    
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        const int NAME_FIELD = 15;
        const int AGE_FIELD = 4;
        const int COFFEE_FIELD = 4;
        const char SPACE = ' ';
        
        os << std::left << std::setw(NAME_FIELD) << p.name << SPACE;
        os << std::setw(AGE_FIELD) << p.age << SPACE;
        os << std::setw(COFFEE_FIELD) << p.coffee << SPACE;
        os << std::endl;
        return os;
    }
};

const std::string FILENAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";

// {
// Reads the data from the given file into a vector of Person objects
// }
static inline void read_file(const std::string& filename, std::vector<Person>& clients) {
    std::ifstream infile(filename);
  try {
      if (!infile.is_open()) {
          throw std::runtime_error("Failed to open file: " + filename);
      }

      std::string name;
      int age, coffee;
      while (infile >> name) {
          infile >> age >> coffee;
          clients.emplace_back(name, age, coffee);
      }
  }catch (std::exception& e) {
    std::cout << "[error]: " << e.what() << std::endl; 
  }
}

// {
// Finds the average age of the clients
// }
static inline double average_age(const std::vector<Person>& list) {
    double average = 0;
    for (const auto& person : list) {
        average += person.getAge();
    }
    average /= list.size();
    return average;
}

// {
// Finds the total amount of coffee consumed by each person
// }
static inline int coffee_totals(const std::vector<Person>& list) {
    int total = 0;
    for (const auto& person : list) {
        total += person.getCoffee();
    }
    return total;
}

// {
// Prints the given vector of Person objects 
// }
static inline void print(const std::vector<Person>& list) {
    for(const auto &person : list) {
        std::cout << person;
    }
}

// {
// Finds the person who drinks the least coffee
// }
static inline Person least_coffee(const std::vector<Person>& list) {
    int least = 0;
    for (int i = 1; i < list.size(); i++) {
        if (list[i].getCoffee() < list[least].getCoffee())
            least = i;
    }
    return list.at(least);
}

// {
// Finds the oldest person in the list.
// }
static inline Person oldest(const std::vector<Person>& list) {
    int index = 0;
    for (int i = 1; i < list.size(); i++) {
        if (list[i].getAge() > list[index].getAge()) {
            index = i;
        }
    }
    return list.at(index);
}

// {
// Sorts the given vector of Person objects in alphabetical order by name.
// }
static inline void alphabet_order(std::vector<Person>& list) {
    std::sort(list.begin(), list.end(), [](const Person& p1, const Person& p2) {
        return p1.getName() < p2.getName();
    });
}

// {
// Performs a binary search on the given vector of Person objects.
// }
static inline int bin_search(const std::vector<Person>& list, const std::string& target) {
    int first = 0;
    int middle = list.size() / 2;
    int last = list.size();
    int index = -1;
    bool found = false;
    while (!found && first <= last) {
        middle = (first + last) / 2; // split it in half
        if (list[middle].getName() == target) { //if found
            found = true;
            index = middle;
        }
        else if (list[middle].getName() > target) { //if greater we get the appropriate half
            last = middle - 1;
        }
        else { // if lower we get the other half
            first = middle + 1;
        }
    }
    return index;
}

// {
// Gets the target (name) typeid std::string
// }
static inline std::string get_name() {
  std::string target;
  bool validInput = false;

  while (!validInput) {
      try {
          std::cout << "[enter a name]: ";
          std::cin >> target;

          const std::type_info& type = typeid(target);
          if (type == typeid(std::string)) {
              validInput = true;
          } else {
              throw std::runtime_error("[input is not a string]");
          }
      } catch (const std::exception& e) {
          std::cout << "{error}:  " << e.what() << std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
  }

  return target;
}

// {
// Lambda function for printing the header
// }
auto header = []() {
      std::cout << std::left << std::setw(15) << "NAME" << std::setw(4) << "AGE" << std::setw(4) << "COFFEE" << std::endl << std::endl;
};

// {
// Calculates and prints statistics for a list of Person objects.
// }
static inline void get_stats(const std::vector<Person>& list) {
  std::cout << "\n[average]: " << average_age(list);
  std::cout << "\n[total cups of coffee]: " << coffee_totals(list);
  std::cout << "\n[the oldest person is]: \n\n";
  header();
  std::cout << oldest(list);

  std::cout << "\n[the person who drinks the least coffee]: \n\n";
  header();
  std::cout << least_coffee(list);
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
  std::vector<Person> clients;
  read_file(FILENAME, clients);
  
  std::cout << "\n\n[original array]:\n\n";
  header();
  print(clients);

  get_stats(clients);
  
  std::cout << "\n\n[sorted alphabetically]: \n\n";
  header();
  alphabet_order(clients);
  print(clients);
  
  std::cout << "\n\n[total clients]: " << clients.size() << "\n\n";

  std::string name = get_name();
  short index = bin_search(clients, name);
  std::cout << "[{" + name + "}" + " is at the index of: (" << index << ")]\n\n";
  return EXIT_SUCCESS;
}
