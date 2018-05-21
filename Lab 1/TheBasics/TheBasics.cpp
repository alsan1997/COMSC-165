// Lab 1, Console Programming Basics
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

using std::ios;

#include <iomanip>
using std::setprecision;

#include <string>
using std::string;
using std::getline;

#include <cstdlib>

int main()
{
  // Identifying output statements
  cout << "Lab 1, Console Programming Basics\n";
  cout << "Programmer: Aldo Sanjoto\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: Code::Blocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Local Variables
  int age;
  double temp;
  string name, city;
  char buf[100];

  // Prompt user to enter their age
  cout << "Enter your age: ";
  cin >> buf;
  cin.ignore(1000,10);
  age = atoi(buf);

  cout << age << endl;
  // Prompt user to enter their name
  cout << "Enter your name: ";
  getline(cin, name);

  // Prompt user to enter the temperature where they are now
  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf;
  cin.ignore(1000,10);
  temp = atof(buf);

  // Prompt user to enter the city they are in right now
  cout << "What city are you in right now? ";
  getline(cin, city);
  cout << endl;

  // Codes that gives out the result
  cout << name << " is " << age << " years old now, and will be " << age + 1 << " a year from now. " << endl;
  cout << "It's " << temp << " degrees F in " << city;

  // Function rounded to tenth decimal and gives out the result
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(1);
  cout  << " -- that's " << (temp-32)*5/9 << " degrees C" << endl;
}
