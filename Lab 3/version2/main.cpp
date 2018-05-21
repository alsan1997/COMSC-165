// Lab 3, Advanced C/C++ Control Structures
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;

#include <iomanip>
using std::setprecision;

#include <cstdlib>

int main()
{
  // Local Variables
  float purchased, tendered, change;
  int numfiftyd = 0, numtwentyd = 0, numtend = 0, numfived = 0 , numoned = 0;
  int numfiftyc = 0, numquarter = 0, numtenc = 0, numfivec = 0, numonec = 0;
  char buf[100];

  // Identifying output statements
  cout << "Lab 3, Advanced C/C++ Control Structures" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::blocks" << endl;
  cout << "Compiler(s) used: Code::blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Prompt user amount purchased and amount tendered
  cout << "Enter the amount of purchased and tendered: ";
  cin >> buf;
  purchased = atof(buf);
  cin >> buf;
  tendered = atof(buf);

  cout.setf(ios::fixed|ios::showpoint);
  cout << setprecision(2);

  // Find the change by subtracting tendered with purchased
  change = tendered - purchased;
  cout << "Your change is $" << change << endl;

  // The loop of each different kind of money
  while(change >= 49.9999)
  {
     change = change - 49.9999;
     numfiftyd++;
  }

  while(change >= 19.9999)
  {
     change = change - 19.9999;
     numtwentyd++;
  }

  while(change >= 9.9999)
  {
     change = change - 9.9999;
     numtend++;
  }

  while(change >= 4.9999)
  {
     change = change - 4.9999;
     numfived++;
  }

  while(change >= 0.9999)
  {
     change = change - 0.9999;
     numoned++;
  }
  while(change >= 0.4999)
  {
     change = change - 0.4999;
     numfiftyc++;
  }
  while(change >= 0.2499)
  {
     change = change - 0.24999;
     numquarter++;
  }
  while(change >= 0.0999)
  {
     change = change - 0.0999;
     numtenc++;
  }

  while(change >= 0.0499)
  {
     change = change - 0.0499;
     numfivec++;
  }
  while(change >= 0.0099)
  {
     change = change - 0.0099;
     numonec++;
  }

  // Code for checking the existence of the money
  if(numfiftyd > 0)
  cout << numfiftyd  << " $50 bills" << endl;

  if(numtwentyd > 0)
  cout << numtwentyd << " $20 bills" << endl;

  if(numtend > 0)
  cout << numtend    << " $10 bills" << endl;

  if(numfived > 0)
  cout << numfived   << " $5 bills"  << endl;

  if(numoned > 0)
  cout << numoned    << " $1 bills"  << endl;

  if(numfiftyc > 0)
  cout << numfiftyc  << " 50 cents"  << endl;

  if(numquarter > 0)
  cout << numquarter << " 25 cents"  << endl;

  if(numtenc > 0)
  cout << numtenc    << " 10 cents"  << endl;

  if(numfivec > 0)
  cout << numfivec   << " 5 cents"   << endl;

  if(numonec > 0)
  cout << numonec    << " 1 cents"   << endl;
}
