// Lab0, Programming Conventions, part b
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

int main()
{
  // The variable of choices
  int x;

  // Identifying output statements
  cout << "Lab 0, Programming Conventions, part b\n";
  cout << "Programmer: Aldo Sanjoto\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: Codeblocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Statement of welcoming and the sentence of the menu
  cout << "Welcome to Ron's Juice Company" << endl << endl;
  cout << "Please choose any Juice from the menu below: " << endl;
  cout << "1. Apple Juice\n";
  cout << "2. Orange Juice\n";
  cout << "3. Mix Juice\n";
  cout << "4. Strawberry Juice\n\n";

  // User input for choice of juice
  char buf[100];
  cin >> buf;
  x = atoi(buf);
  cout << endl;
  cout << "Thanks, your Juice will be ready in a minute " << endl;
}
