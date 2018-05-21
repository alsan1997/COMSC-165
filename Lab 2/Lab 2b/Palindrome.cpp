// Lab 2, Basic C/C++ Control Structures, Part B
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
  // Local Variables
  char buf[100];
  int num;
  int module1,module2,module3, module4;
  int division1, division2, division3, division4;

  // Identifying output statements
  cout << "Lab 2, Basic C/C++ Control Structures, Part B\n";
  cout << "Programmer: Aldo Sanjoto\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: Codeblocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Main loop
  while(true)
  {
    // Code to prompt user to quit and ask digit(s)
    cout << "Enter Q or q to quit program." << endl;
    cout << "Enter digit(s) integer to decide if it's palindrome or not: ";
    cin >> buf;
    cin.ignore(1000, 10);
    num = atoi(buf);
    cout << endl;

    // Code to end program if user enter Q or q
    if(buf[0] == 'q' || buf[0] == 'Q')
    {
      break;
    }

    // Modulus calculation
    module1 = num % 10000;
    module2 = module1 % 1000;
    module3 = module2 % 100;
    module4 = module3 % 10;

    // Division calculation
    division1 = num / 10000;
    division2 = module1 / 1000;
    division3 = module2 / 100;
    division4 = module3 / 10;

    // Statements to check whether the 1st, 2nd is the same with 4th, 5th digit respectively
    if(module4 == division1 && division2 == division4)
    {
      cout << "That's a palindrome. " << endl << endl;
    }
    else
    {
      cout << "That's NOT a palindrome. " << endl << endl;
    }

    // "continue" To ask the user whether they want to test again or quit
    continue;
  }
}
