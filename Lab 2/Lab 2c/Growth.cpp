// Lab 2, Basic C/C++ Control Structures, Part C
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;
using std::setw;

int main()
{
  // Local Variables
  long double pop, numofinc;
  int year;
  double growth;

  // Identifying output statements
  cout << "Lab 2, Basic C/C++ Control Structures, Part C" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" <<  endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Adjust Table and title
  cout.setf(ios::left, ios::adjustfield);
  cout << setw(10) << "Year" << setw(15) << "Population" << setw(20) << "Number of population increase" << endl;
  cout << "======================================================" << endl;

  // Round to nearest whole number
  cout.setf(ios::fixed);
  cout << setprecision(0);

  // Assigned variables
  year = 2014;
  pop = 7257366450;
  growth = 1.1;

  // For loop for repeating the data each year
  for(int x = 0; x <= 75; x++)
  {
     numofinc = pop * (growth / 100);
     cout << setw(10) << year << setw(15) << pop << setw(20) << numofinc << endl;
     pop = pop + numofinc;
     year++;
  }
}
