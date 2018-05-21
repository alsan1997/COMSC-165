// Lab 12, Stacks as Linked Lists
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;

#include <iomanip>
using std::setw;

#include <cstdlib>

// Struct definition
struct course
{
  char cs[12];
  char term[7];
  double units;
  char grade;
  course* next;
};

void outputMe();
void table(const course*);

int main()
{
  // Local Variables
  char buf[100];
  int choice;

  // Call identifying output statements
  outputMe();

  // New list
  course* start = 0;

  while(true)
  {
    table(start); // cout table before input and after input

    // Code to output each time data input using for loop
    const course* p;
    for (p=start; p; p=p->next)
    cout << setw(10) << p->cs << setw(10) << p->term << setw(10) << p->units << setw(10) << p->grade << endl;

    // Prompt user to add a Node or N to quit
    while(true)
    {
      cout << endl;
      cout << "Enter Y to add a node, N to quit: ";
      cin >> buf;
      choice = atoi(buf);
      cin.ignore(1000, 10);

      if(buf[0] == 'y' || buf[0] == 'Y'|| buf[0] == 'n' || buf[0] == 'N')break;
      else
      {
        cout << "Please enter upper or lower case of Y or N only." << endl;
        continue;
      }

    }

    if(buf[0] == 'N' || buf[0] == 'n')break;

    // Code to input a list
    course* t = new course;

    // Prompt user to enter information (course, term, units, grades)
    cout << "Please enter the course (ex. COMSC-165): ";
    cin >> t->cs;
    cout << endl;

    cout << "Please enter the term (ex. FA-2011): ";
    cin >> t->term;
    cout << endl;

    cout << "Please enter the units: ";
    cin >> buf;
    t->units = atof(buf);
    cout << endl;

    cout << "Please enter the grade: ";
    cin >> t->grade;
    cout << endl;

    // Insert data to front of the list
    t->next = start;
    start = t;
  }

  // Code of deallocate memory
  while (start) // zero when the list is empty
  {
    course* p = start; // node to delete
    start = start->next; // reset start
    delete p; // now delete it
  }
}

void outputMe()
{
  // Identifying output statements
  cout << "Lab 12, Stacks as Linked Lists" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks " << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

void table(const course* x)
{
  // Table format
  cout.setf(ios::left, ios::adjustfield);
  cout << setw(10) << "Course" << setw(10) << "Term" << setw(10) << "Units" << setw(10) << "Grade" << endl;
  cout << setw(10) << "------" << setw(10) << "------" << setw(10) << "-----" << setw(10) << "-----" << endl;
}
