// Lab 5, Advanced C++ Functions, Part D
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

int reversing (int);

int main()
{
  // Local variables
  int num, resNUM;
  char buf[100];

  // Identifying output statements
  cout << "Lab 5, Advanced C++ Functions, Part D" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // While loop or replay loop
  while(true)
  {
    // Prompt user to enter digits
    cout << "Enter q or Q to quit." << endl;
    cout << "Enter a number with to reverse it: ";
    cin >> buf;
    num = atoi(buf);
    cin.ignore(1000, 10);

    //if statements to check if user enter q or Q and the digits validity
    if(buf[0] == 'q' || buf[0] == 'Q')break;

    // Assign result value and output it
    resNUM = reversing(num);
    cout << resNUM << endl << endl;
  }
}

// Reverse subprogram
int reversing (int x)
{
  int y;

  // While loop and reverse calculation
  while(x > 0)
  {
    y = (y * 10) + (x % 10);
    x = x / 10;
  }

  // Returning value
  return y;
}
