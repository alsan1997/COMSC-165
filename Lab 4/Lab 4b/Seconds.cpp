// Lab 4, Basic of C and C++ Functions, Part B
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

// Global Variable
int calcz(int, int, int);

int main()
{
  // Local Variables
  int hours, mins, secs, totalsecs;
  char buf[100];

  // Identifying output statements
  cout << "Lab 4, Basic of C and C++ Functions, Part B" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // While main loop
  while(true)
  {
    // Prompt user to enter hours, mins, seconds
    cout << "Enter q or Q at any three of the input to quit program." << endl;
    cout << "Please enter the number of hours, minutes, seconds respectively: ";
    cin >> buf;
    hours = atoi(buf);
    cin >> buf;
    mins = atoi(buf);
    cin >> buf;
    secs = atoi(buf);

    // Check if user enter q Or Q then it break
    if(buf[0] == 'q' || buf[0] == 'Q')
    {
       break;
    }

    // initialize and output result
    totalsecs = calcz(hours, mins, secs);
    cout << "Your time is " << totalsecs << " seconds from the last its struck 12 " << endl << endl;
  }
}

// Subprogram to calculate hours,minutes,seconds that is prompt by user
int calcz(int h, int m, int s)
{
  //Local variable inside subprogram
  int ts = 0;

  // while loop if hours greater or equal 12 and less than 24
  while(h >= 12 && h < 24)
    h = h - 12;

  // While loop if hours greater or equal 24
  while(h >=24)
    h = h - 24;

  // Calculate totalseconds (ts)
  ts = (h*3600) + (m*60) + (s);

  // Return total seconds
  return ts;
}

