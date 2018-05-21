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

  // If and while condition statements for checking the change
  if(49.9999 <= change)
  {
     do
     {
        change = change - 49.9999 ;
        numfiftyd++;
     }while(49.9999  <= change);
  }

  if(19.9999 <= change)
  {
     do
     {
        change = change - 19.9999;
        numtwentyd++;
     }while(19.9999 <= change);
  }

  if(9.9999 <= change)
  {
     do
     {
        change = change - 9.9999;
        numtend++;
     }while(9.9999 <= change);
  }

  if(4.9999 <= change)
  {
     do
     {
        change = change - 4.9999;
        numfived++;
     }while(4.9999 <= change);
  }

  if(0.9999 <= change)
  {
     do
     {
        change = change - 0.9999;
        numoned++;
     }while(0.9999 <= change);
  }

  if(0.4999 <= change)
  {
     do
     {
        change = change - 0.4999;
        numfiftyc++;
     }while(0.4999 <= change);
  }

  if(0.2499 <= change)
  {
     do
     {
        change = change - 0.2499;
        numquarter++;
     }while(0.2499 <= change);
  }

  if(0.0999 <= change)
  {
     do
     {
        change = change - 0.0999;
        numtenc++;
     }while(0.0999 <= change);
  }

  if(0.0499 <= change)
  {
     do
     {
        change = change - 0.0499;
        numfivec++;
     }while(0.0499 <= change);
  }

  if(0.0099 <= change)
  {
     do
     {
        change = change - 0.0099;
        numonec++;
     }while(0.0099 <= change);
  }

  // Code to display the number needed for bills if it does exist
  if(numfiftyd == 0 )
  cout << "";
  else if (numfiftyd == 1)
  cout << numfiftyd << " $50 bill" << endl;
  else
  cout << numfiftyd << " $50 bills" << endl;

  if(numtwentyd == 0)
  cout << "";
  else if (numtwentyd == 1)
  cout << numtwentyd << " $20 bill" << endl;
  else
  cout << numtwentyd << " $20 bills" << endl;

  if(numtend == 0)
  cout << "";
  else if (numtend == 1)
  cout << numtend << " $10 bill" << endl;
  else
  cout << numtend << " $10 bills" << endl;

  if(numfived == 0)
  cout << "";
  else if (numfived == 1)
  cout << numfived << " $5 bill" << endl;
  else
  cout << numfived << " $5 bills" << endl;

  if(numoned == 0)
  cout << "";
  else if (numoned == 1)
  cout << numoned << " $1 bill" << endl;
  else
  cout << numoned << " $1 bills" << endl;

  if(numfiftyc == 0)
  cout << "";
  else if (numfiftyc == 1)
  cout << numfiftyc << " 50 cent" << endl;
  else
  cout << numfiftyc << " 50 cents" << endl;

  if(numquarter == 0)
  cout << "";
  else if (numquarter == 1)
  cout << numquarter << " 25 cent" << endl;
  else
  cout << numquarter << " 25 cents" << endl;

  if(numtenc == 0)
  cout << "";
  else if (numtenc == 1)
  cout << numtenc << " 10 cent" << endl;
  else
  cout << numtenc << " 10 cents" << endl;

  if(numfivec == 0)
  cout << "";
  else if (numfivec == 1)
  cout << numfivec << " 5 cent" << endl;
  else
  cout << numfivec << " 5 cents" << endl;

  if(numonec == 0)
  cout << "";
  else if (numonec == 1)
  cout << numonec << " 1 cent" << endl;
  else
  cout << numonec << " 1 cents" << endl;
}
