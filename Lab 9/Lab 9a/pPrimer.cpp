// Lab 9, Intro To C Pointers, part A
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
  tod theTime[5];
  int i;

   // Identifying output statements
  cout << "Lab 9, Intro To C Pointers, part A" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks" << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Address of thetime array
  cout << "theTime: " << &theTime << endl << endl;

  // Address of each of the thetime array
  for(int i = 0; i < 5; i++)
  {
    cout << "theTime[" << i << "]: " << &theTime[i] << endl;
    cout << "theTime[" << i << "].hour: " << &theTime[i].hour << endl;
    cout << "theTime[" << i << "].minute: " << &theTime[i].minute << endl;
    cout << "theTime[" << i << "].second: " << &theTime[i].second << endl;
    cout << "theTime[" << i << "].descr: " << &theTime[i].descr << endl;
    cout << endl;
  }

  // Address of int i
  cout << "int i: " << &i << endl;

  // Size of tod and tod pointers
  cout << "Size of tod = " << sizeof(tod) << endl;
  cout << "Size of tod pointers = " << sizeof(tod*) << endl;
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
