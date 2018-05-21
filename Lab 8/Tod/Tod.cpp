// Lab 8, Intro To Object Oriented Programming, Step 1-5
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::endl;
using std::cout;

// Struct Definition
struct tod
{
  int hour;
  int minute;
  int second;
  char descr[32];
};

void coutTod(const tod&);

int main()
{
  // Struct array initializer
  tod theTime[] = {{12, 0, 0, "Noon"}, {0, 0, 0, "Midnight"},
    {11, 30, 0, "Lunch time"}, {18, 45, 0, "Supper time"},
    {23, 59, 59, "Bed time"}};

  // Identifying output statements
  cout << "Lab 8, Intro To Object Oriented Programming, Step 1-5" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks" << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // For loop and call the function
  for(int i = 0; i < 5; i++)
  {
    coutTod(theTime[i]);
  }
}

void coutTod(const tod& t)
{
  // Output the time, hour, minute and seconds
  cout << t.descr << " is ";
  if(t.hour < 10)
    cout << '0';
  cout << t.hour << ':';
  if(t.minute < 10)
    cout << '0';
  cout << t.minute << ':';
  if(t.second < 10)
    cout << '0';
  cout << t.second << endl;
}
