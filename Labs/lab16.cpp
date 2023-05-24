//Jakob Balkovec
//lab16.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

struct Person{
  string name;
  int age;
  int coffee;
};

const int SIZE = 150;
const int COLWIDTH = 8;
const int NAME_FIELD = 15;
const int AGE_FIELD = 4;
const int COFFEE_FIELD = 4;
const char SPACE = ' ';
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";


int coffeeTotals(const Person list[], int numElements);
double averageAge(const Person list[], int numElements);
void printOne(Person p);
int oldestPerson(const Person list[], int numElements);
int leastCoffee(const Person list[], int numElements);
void alphabetOrder(Person list[], int numElements);
void swapPerson(Person &val1, Person &val2);
int binSearch(Person list[], int numElements, string target);

int main()
{
  Person clients[SIZE];
  Person p;
  Person dude;
  ifstream infile;
  double average = 0;
  int total = 0;
  int least;
  int index;
  int indexi;
  int count = 0;
  string target;
  cout << endl << endl;

  infile.open(FILENAME);
  if (infile.fail()){
    cout << "File error, exiting the program";
    cin.get();
    exit(1);
  }

  while (infile >> clients[count].name){
    infile >> clients[count].age >> clients[count].coffee;
    count++;
  }
  cout << "**ORIGINAL ARRAY**" << endl << endl;
  cout << left <<setw(NAME_FIELD) << "NAME" << setw(AGE_FIELD) << "AGE" << setw(COFFEE_FIELD) << "COFFEE" << endl << endl;

  for (int i = 0; i < count; i++){
    p = clients[i];
    printOne(p);
  }
  cout << endl;
  average = averageAge(clients, count);
  total = coffeeTotals(clients, count);
  least = leastCoffee(clients, count);
  index = oldestPerson(clients, count);
  
  cout << "Average age is: " << average << endl;
  cout << endl;cout << "Total cups of coffe: " << total << endl;
  cout << endl;
  cout << "The oldest person is: " << endl;
  cout << endl;
  cout << left <<setw(NAME_FIELD) << "NAME" << setw(AGE_FIELD) << right << "AGE  " << setw(COFFEE_FIELD) << right << "COFFEE" << endl;
  printOne(clients[index]);
  cout << endl;
  cout << "The person who drinks the least coffee: " << endl;
  cout << endl;
  cout << left <<setw(NAME_FIELD) << "NAME" << setw(AGE_FIELD) << right << "AGE  " << setw(COFFEE_FIELD) << right << "COFFEE" << endl;
  printOne(clients[least]);
  cout << endl;

  cout << "**SORTED ARRAY**" << endl << endl;
  cout << left <<setw(NAME_FIELD) << "NAME" << setw(AGE_FIELD) << right << "AGE  " << setw(COFFEE_FIELD) << right << "COFFEE" << endl << endl;
  alphabetOrder(clients, count);
  for(int i = 0; i < count; i++){
    dude = clients[i];
    printOne(dude);
  }
  cout << endl << endl;
  cout << "There are 21 people on the list, we using binary search to find a specific name " << endl << endl;
  cout << "Enter a name: ";
  cin >> target;
  cout << endl << endl;
  indexi = binSearch(clients, count, target);
  cout << target << " is at the index of: [" << indexi <<"]";

  cout << endl << endl;
  return 0;
}

double averageAge(const Person list[], int numElements)
{
  double average = 0;
  for (int i = 0; i < numElements; i++){
    average += list[i].age;
  }
  average = (average / numElements);
return average;
}

int coffeeTotals(const Person list[], int numElements)
{
  int total = 0;
  for(int i = 0; i < numElements; i++){
    total += list[i].coffee;
  }
return total;
}

void printOne(Person p) //prints one...can print all with for loop
{
  cout << left << setw(NAME_FIELD) << p.name << SPACE;
  cout << setw(AGE_FIELD) << p.age << SPACE;
  cout << setw(COFFEE_FIELD) << p.coffee << SPACE;
  cout << endl;
}

int leastCoffee(const Person list[], int numElements)
{
  int least = 0;

  for(int i = 1; i < numElements; i++ ){
    if(list[i].coffee < list[least].coffee)
      least = i;
  }
  return least;
}

int oldestPerson(const Person list[], int numElements)
{
  int index = 0;

  for(int i = 1; i < numElements; i++){
    if(list[i].age > list[index].age){
      index = i;
    }
  }
  return index;
}

void alphabetOrder(Person list[], int numElements)
{
  int index = 0;

  for(int i = 0; i < numElements; i++){
    index = i;
    for(int j = i+1; j < numElements; j++){
      if(list[j].name < list[index].name)
        index = j;
    }
    if(index != i)
      swapPerson(list[index], list[i]);
  }
}

void swapPerson(Person &val1, Person &val2)
{
  Person temp = val1;
  val1 = val2;
  val2 = temp;
}

int binSearch(Person list[], int numElements, string target)
{
  int first = 0;
  int middle = numElements/2;
  int last = numElements;
  int indexi = -1;

  bool found = false;

  while(!found && first <= last){
    middle = (first + last)/2; // split it in half
    if(list[middle].name == target){ //if found
      found = true;
      indexi = middle;
    }else if(list[middle].name > target){ //if greater we get the appropriate half
      last = middle -1;
    }else{ // if lower we get the other half
      first = middle + 1; 
    }
  }
  return indexi;
}
