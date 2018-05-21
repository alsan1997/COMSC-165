// Lab 4, Basic of C and C++ Functions, Part C
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

#include <ctime>

// enum function
enum Result{LO, HI, OK};

// Global variables
Result check(int, int);
int input(int, int);

int main()
{
  // Local Variables
  int guess, choice, num, result;
  char buf[100];

  // Identifying output statements
  cout << "Lab 4, Basic of C and C++ Functions, Part C" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // While main loop
  while(true)
  {
     // Seeding new number every seconds
     srand(time(0)); rand();

     // Assign random number to int, and output instructions
     num = 1 + rand() % 1000;
     cout << "I have a number between 1 and 1000." << endl;
     cout << "Can you guess my number ?" << endl;

     // For loop to keep looping until enum reach OK
     for(int x = 0;; x++)
     {
       // Calls sub program
       guess = input(guess, num);
       result = check(guess, num);

       // Check result
       if(result == OK)
       {
         cout << "Excellent! You guessed the number!" << endl << endl;
         break;
       }

       if(result == LO)
          cout << "Too Low. Try again!" << endl << endl;
       if(result == HI)
          cout << "Too High. Try again!" << endl << endl;
     }

     // Another while loop to check the validity input if user want to play again
     while(true)
     {
       cout << "Would you like to play again ? Enter (Y/N): ";
       cin >> buf;
       choice = atoi(buf);
       cin.ignore(1000,10);
       cout << endl;

       if(buf[0] == 'y' || buf[0] == 'Y'|| buf[0] == 'n' || buf[0] == 'N')break;
       else
       {
          cout << "Please enter capital or lower case of Y or N only." << endl << endl;
          continue;
       }
     }

     if(buf[0] == 'y' || buf[0] == 'Y')continue;
     if(buf[0] == 'n' || buf[0] == 'N')break;
  }
}

// Input number subprogram
int input(int g, int n)
{
   char buf[100];

   cout << "Please enter a number: ";
   cin >> buf;
   g = atoi(buf);
   cin.ignore(1000, 10);

   return  g;
}

// Result check for input number with random number
Result check(int g, int n)
{
   Result score;

   if(g == n)
     score = OK;

   if(g > n)
     score = HI;

   if(g < n)
     score = LO;

   return score;
}
