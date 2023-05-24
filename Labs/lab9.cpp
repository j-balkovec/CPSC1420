// Jakob Balkovec
// lab9.cpp

#include <iostream>
#include <string>

using namespace std;

void swapStr(string &val1, string &val2);
void input(string &val1, string &val2);
void output(string val1, string val2);

int main()
{ //local scope
string str1, str2;
 
 cout << endl << endl;
 input(str1, str2);
 cin.ignore();
 output(str1, str2);
 swapStr(str1, str2);
 cin.ignore();
 output(str1, str2);
 cout << endl << endl;
 return 0;
}

void input(string &val1, string &val2)
{
  cout << "Enter two string values: ";
  cin >> val1;
  cin >> val2;
  cout << endl;
}

void output(string val1, string val2)
{
  cout << endl;
  cout << "str1 is " << val1 << " and str2 is " << val2 << endl;
  
}

void swapStr(string &val1, string &val2)
{
  string temp = val1;
  val1 = val2;
  val2 = temp;
}
