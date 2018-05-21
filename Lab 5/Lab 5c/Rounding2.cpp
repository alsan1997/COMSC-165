// Lab 5, Advanced C++ Functions, Part C
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

#include <cmath>

float roundToIntegers(float);
float roundToTenths(float);
float roundToHundredths(float);
float roundToThousandths(float);

int main()
{
  // Local Variables
  char buf[100];
  float x;
  float yToInt, yToTen, yToHun, yToThou;

  // Identifying output statements
  cout << "Lab 5, Advanced C++ Functions, Part C" << endl;
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
    cout << "Enter a number: ";
    cin >> buf;
    x = atof(buf);
    cin.ignore(1000,10);

    // If statements to check if user enter q or Q
    if(buf[0] == 'q' || buf[0] == 'Q')break;

    // Call functions
    yToInt = roundToIntegers(x);
    yToTen = roundToTenths(x);
    yToHun = roundToHundredths(x);
    yToThou = roundToThousandths(x);

    // Output the original and assigned rounded number
    cout << "The original number is: " << x << endl;
    cout << "The rounded number to integers is: " << yToInt << endl;
    cout << "The rounded number to tenths is: " << yToTen << endl;
    cout << "The rounded number to hundredths is: " << yToHun << endl;
    cout << "The rounded number to thousandths is: " << yToThou << endl << endl;
  }
}

// Subprogram round to whole number
float roundToIntegers(float x)
{
  float y;

  y = floor(x + 0.5);

  return y;
}

// Subprogram round to nearest tenths
float roundToTenths(float x)
{
  float y;

  y = floor(x * 10 + 0.5) / 10;

  return y;
}

// Subprogram round to nearest hundredths
float roundToHundredths(float x)
{
  float y;

  y = floor(x * 100 + 0.5) / 100;

  return y;
}

// Subprogram round to nearest thousandths
float roundToThousandths(float x)
{
  float y;

  y = floor(x * 1000 + 0.5) / 1000;

  return y;
}
