// Lab 5, Advanced C++ Functions, Part B
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

#include <cmath>

int main()
{
  // Local Variables
  char buf[100];
  double x, y;

  // Identifying output statements
  cout << "Lab 5, Advanced C++ Functions, Part B" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // While or Replay loop
  while(true)
  {
    // Prompt user to enter a number
    cout << "Enter Q or q to quit. " << endl;
    cout << "Enter a number to be rounded to the nearest whole number: ";
    cin >> buf;
    x = atof(buf);
    cin.ignore(1000,10);

    // If statements to check if users enter Q or q
    if(buf[0] == 'q' || buf[0] == 'Q')break;

    // Floor function
    y = floor(x + 0.5);

    // Output original and rounded number
    cout << "The original number is: " << x << endl;
    cout << "The rounded number is: " << y << endl << endl;
  }
}

