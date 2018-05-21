// Lab 5, Advanced C++ Functions, Part A
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;

#include <cstdlib>

#include <iomanip>
using std::setprecision;

double calculateCharges(double);

int main()
{
  // Local Variables
  char buf[100];
  double hours, charge;

  // Identifying output statements
  cout << "Lab 5, Advanced C++ Functions, Part A" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Prompt user for hours
  cout << "Enter hours to determine car charges: ";
  cin >> buf;
  hours = atof(buf);
  cin.ignore(1000, 10);

  // Setprecision to 2 decimal places
  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Call function and output it
  charge = calculateCharges(hours);
  cout << "The total charge for the car is $" << charge << endl;
}

// Subprogram to calculate charges
double calculateCharges(double h)
{
  // Local Variables
  double basicC = 2, c = 0, x;
  int y;

  // If statements to calculate charges
  if(h > 0 && h <= 3)
    c = basicC;

  if(h > 3 && h < 24)
  {
    y = h - 3;
    c = basicC + (y * 0.5);
    x = h - 3;

    if(x - y > 0)
    {
      c = c + 0.5;
    }
  }

  if(h >= 24)
    c = 10;

  return c;
}

