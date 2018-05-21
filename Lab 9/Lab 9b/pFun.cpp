// Lab 9, Intro To C Pointers, part B
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

void coutTod(const tod*);
void coutTod(int, const tod*);
int diffTod(const tod*, const tod*);
int isAfter(const tod*, const tod*);
int isBefore(const tod*, const tod*);

int main()
{
  // Struct array initializer
  tod theTime[] = {{12, 0, 0, "Noon"}, {0, 0, 0, "Midnight"},
    {11, 30, 0, "Lunch time"}, {18, 45, 0, "Supper time"},
    {23, 59, 59, "Bed time"}};

  // Identifying output statements
  cout << "Lab 9, Intro To C Pointers, part B" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks" << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Call the time in array
  coutTod(5, theTime);
  cout << endl;

  // Output difference in seconds
  cout << "From " << theTime[2].descr << " to " << theTime[0].descr << " is "
    << diffTod(&theTime[2], &theTime[0]) << " seconds." << endl;
  cout << "From " << theTime[4].descr << " to " << theTime[0].descr << " is "
    << diffTod(&theTime[4], &theTime[0]) << " seconds." << endl;
  cout << "From " << theTime[2].descr << " to " << theTime[3].descr << " is "
    << diffTod(&theTime[2], &theTime[3]) << " seconds." << endl;
  cout << endl;

  // Outpur whether the time is after or not after or before or not before
  if(isAfter(&theTime[2], &theTime[0]) == 1)
    cout << theTime[2].descr << " is after " << theTime[0].descr << endl;
  else
    cout << theTime[2].descr << " is not after " << theTime[0].descr << endl;

  if(isBefore(&theTime[2], &theTime[0]) == 1)
    cout << theTime[2].descr << " is before " << theTime[0].descr << endl;
  else
    cout << theTime[2].descr << " is not before " << theTime[0].descr << endl;

  if(isAfter(&theTime[2], &theTime[3]) == 1)
    cout << theTime[2].descr << " is after " << theTime[3].descr << endl;
  else
    cout << theTime[2].descr << " is not after " << theTime[3].descr << endl;
}

void coutTod(const tod* t)
{
  // Output of the time, hour, minutes, seconds
  cout << t->descr << " is ";
  if(t->hour < 10)
    cout << '0';
  cout << t->hour << ':';
  if(t->minute < 10)
    cout << '0';
  cout << t->minute << ':';
  if(t->second < 10)
    cout << '0';
  cout << t->second << endl;
}

void coutTod(int n, const tod* t)
{
  // For loop and call the other coutTod function
  for(int i = 0; i < n; i++)
  {
    coutTod(&t[i]);
  }
}

int diffTod(const tod* first, const tod* secondzz)
{
  int h, m, s, result;

  // Hour, minute and second calculation
  h = (first->hour - secondzz->hour) * 3600;
  m = (first->minute - secondzz->minute) * 60;
  s = first->second - secondzz->second;

  // return number of seconds
  return result = h + m + s;
}

int isAfter(const tod* f, const tod* s)
{
  int x = diffTod(f, s);
  int y = 0;

  // if x is positive then return y = 1
  if(x > 0)
    y = 1;

  // return y value
  return y;
}

int isBefore(const tod* f, const tod* s)
{
  int x = diffTod(f, s);
  int y = 0;

  // if x is negative then return y = 1
  if(x < 0)
    y = 1;

  // return y value
  return y;
}
