// Lab 4, Basic of C and C++ Functions, Part A
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

void outputsq (int, char);

int main()
{
  //Local Variables
  int sizez;
  char fillz;
  char buf[100];

  // Identifying output statements
  cout << "Lab 4, Basic of C and C++ Functions, Part A" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // While main loop
  while(true)
  {
    cout << "Enter Q or q to quit program. " << endl;
    cout << "Enter the size of square between 1-20: ";
    cin >> buf;
    sizez = atoi(buf);
    cin.ignore(1000, 10);

    // Terminate program if user enters Q or q
    if(buf[0] == 'q' || buf[0] == 'Q')break;

    // Check for valid range
    if(sizez < 1 || sizez > 20)
    {
      cout << "Invalid range. Please enter only 1-20." << endl << endl;
      continue;
    }

    // Prompt user to enter the desired character
    cout << "Enter your desired character: ";
    cin >> buf;
    fillz = buf[0];
    cin.ignore(1000, 10);

    // Calls the subprogram
    outputsq(sizez, fillz);
  }
}

// Subprogram to output Square
void outputsq(int sze, char c)
{
   // For loop to output program
   for(int g = 0; g < sze; g++)
   {
      cout << endl;
      for(int h = 0; h < sze; h++)
      {
         cout << c;
      }
   }
   cout << endl << endl;
}
