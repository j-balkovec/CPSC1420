//Jakob Balkovec
//lab14.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

//function that prints a single record
//function that prints the average age
//function that returns the totla number of cups of coffee that are consumed by the entire lsot in one day

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


int main()
{
Person clients[SIZE];
int count = 0;
Person p;
ifstream infile;
double average = 0;
int total = 0;

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

cout << left <<setw(NAME_FIELD) << "NAME" << setw(AGE_FIELD) << "AGE" << setw(COFFEE_FIELD) << "COFFEE" << endl << endl;

 for (int i = 0; i < count; i++){
   p = clients[i];
   printOne(p);
}
cout << endl;
average = averageAge(clients, count);
total = coffeeTotals(clients, count);

cout << "Average age is: " << average << endl;
cout << endl;
cout << "Total cups of coffe: " << total << endl;

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

void printOne(Person p)
{
  cout << left << setw(NAME_FIELD) << p.name << SPACE;
  cout << setw(AGE_FIELD) << p.age << SPACE;
  cout << setw(COFFEE_FIELD) << p.coffee << SPACE;
  cout << endl;
}
