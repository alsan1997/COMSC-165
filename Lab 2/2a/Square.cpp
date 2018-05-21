// Lab 2, Basic C/C++ Control Structures, Part A
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
  int n;

  // Identifying output statements
  cout << "Lab 2, Basic C/C++ Control Structures, Part A" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //  Main while loop
  while(true)
  {
    // Prompt user to enter size or to quit program
    cout << "Enter Q or q to quit the program" << endl;
    cout << "Please enter the Square size between 1-20: ";
    cin >> buf;
    cin.ignore(1000, 10);
    n = atoi(buf);
    cout << endl;

    // If user enter Q or q it will break which get out from loop = end program
    if(buf[0] == 'q' || buf[0] == 'Q')
    {
      break;
    }

    // If user enter wrong range, it will rePrompt user using "continue"
    if(n < 1 || n > 20)
    {
      cout << "Invalid range. Please try again. " << endl;
      continue;
    }

    // User enters 1 for size
    if(n == 1)
    {
      cout << "*" << endl << endl;
      continue;
    }

    // For loop printing first row
    for(int x = 0; x < n; x++)
    {
       cout << "*";
    }
    cout << endl;

    // Codes for making Star, Space, Star according to size
    int i = 0;
    while(true)
    {
      if(i == n-2)
      {
        break;
      }
      cout << "*";
      i++;

      int j = 0;
      while(true)
      {
        if(j == n-2)
        {
          break;
        }
        cout << " ";
        j++;
      }
      cout << "*" << endl;
    }

    // Output the last row of square
    for(int x = 0; x < n; x++)
    {
      cout << "*";
    }
    cout << endl << endl;
  }
}
