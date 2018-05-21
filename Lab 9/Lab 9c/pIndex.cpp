// Lab 9, Intro To C Pointers, part C
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

  // Chronological order initializer
  tod* tIndex[5];
  tIndex[0] = &theTime[1];
  tIndex[1] = &theTime[2];
  tIndex[2] = &theTime[0];
  tIndex[3] = &theTime[3];
  tIndex[4] = &theTime[4];

  // Alphabetical order initializer
  tod* aIndex[5];
  aIndex[0] = &theTime[4];
  aIndex[1] = &theTime[2];
  aIndex[2] = &theTime[1];
  aIndex[3] = &theTime[0];
  aIndex[4] = &theTime[3];

  // Identifying output statements
  cout << "Lab 9, Intro To C pointers, part C" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks" << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Output Original order
  cout << "Original order: " << endl;
  for(int i = 0; i < 5; i++)
  {
    coutTod(theTime[i]);
  }
  cout << endl;

  // Output Chronological order
  cout << "Chronological Order: " << endl;
  for (int i = 0; i < 5; i++)
  {
    coutTod(*tIndex[i]);
  }
  cout << endl;

  // Output Alphabetical order
  cout << "Alphabetical Order: " << endl;
  for (int i = 0; i < 5; i++)
  {
    coutTod(*aIndex[i]);
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
