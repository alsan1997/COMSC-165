// Lab 11, Linked List Concepts
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;

// Struct Definition
struct tod
{
  int hour;
  int minute;
  int second;
  char d[32];
  tod* next;
};

void coutTod(const tod*);
void outputme();

int main()
{
  //  Tod initialize
  tod noon = {12, 0, 0, "Noon"};
  tod midnight = {0, 0, 0, "Midnight"};
  tod suppertime = {18, 45, 0, "Supper Time"};
  tod bedtime = {23, 0, 0, "Bed time"};
  tod lunchtime = {11, 30, 0, "Lunch time"};
  tod br = {8, 0, 0, "Breakfast"};
  tod cs = {9, 30, 0, "Class Starts"};
  tod ce = {12, 20, 0, "Class Ends"};
  tod* p;

  // Identifying output call
  outputme();

  // Original list
  tod* start = 0;
  start = &midnight;
  midnight.next = &lunchtime;
  lunchtime.next = &noon;
  noon.next = &suppertime;
  suppertime.next = &bedtime;
  bedtime.next = 0;

  cout << "Original list" << endl;
  cout << "-----------------------" << endl;
  for (p=start; p; p=p->next)
  {
      coutTod(p);
  }

  // Adding breakfast
  midnight.next = &br;
  br.next = &lunchtime;

  cout << endl;
  cout << "Breakfast was added to list" << endl;
  cout << "-----------------------" << endl;
  for(p=start; p; p=p->next)
  {
      coutTod(p);
  }

  // Adding Class start time
  br.next = &cs;
  cs.next = &lunchtime;

  cout << endl;
  cout << "Class Start time was added to list" << endl;
  cout << "-----------------------" << endl;
  for(p=start; p; p=p->next)
  {
      coutTod(p);
  }

  // Adding class end time
  noon.next = &ce;
  ce.next = &suppertime;

  cout << endl;
  cout << "Class End time was added to list" << endl;
  cout << "-----------------------" << endl;
  for(p=start; p; p=p->next)
  {
      coutTod(p);
  }

  //Removing meal times
  midnight.next = &cs;
  cs.next = &noon;
  noon.next = &ce;
  ce.next = &bedtime;

  cout << endl;
  cout << "Meal times was removed from list" << endl;
  cout << "-----------------------" << endl;
  for(p=start; p; p=p->next)
  {
      coutTod(p);
  }

  // Adding back meal times
  midnight.next = &br;
  br.next = &cs;
  cs.next = &lunchtime;
  lunchtime.next = &noon;
  noon.next = &ce;
  ce.next = &suppertime;
  suppertime.next = &bedtime;

  cout << endl;
  cout << "Meal times was added back to list" << endl;
  cout << "-----------------------" << endl;
  for(p=start; p; p=p->next)
  {
      coutTod(p);
  }
}

void outputme()
{
  // Identifying output statements
  cout << "Lab 11, Linked List Concepts" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks" << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

void coutTod(const tod* t)
{
  // Output the time, hour, minute and seconds
  cout << t->d << " is ";
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
