// Lab 7, C Strings and C++ Strings
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

int myStrLen(const char*);
void myStrCpy(char*, const char*);
int myStrCmp(const char*, const char*);
void myStrSwap(char*, char*);
void myStrUpr(char*);
void myStrLwr(char*);

int main()
{
  // Local Variables
  char testLen[100] = "My number of string is 25";
  char testCpy1[100] = "hello";
  char testCpy[100] = "hi";
  char testCmp[100] = "Indonesia 1945";
  char testCmp1[100] = "Indonesia 1945";
  char testLwr[100] = "HAHAHA 2 GW";
  char testUpr[100] = "231 let go and enjoy life";
  char testSwp[100] = "ciut !!";
  char testSwp1[100] = "ali s";

  // Identifying output statements
  cout << "Lab 7, C Strings and C++ Strings" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks" << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << myStrLen(testLen);
  cout << endl;

  myStrCpy(testCpy1, testCpy);
  cout << endl;

  cout << myStrCmp(testCmp, testCmp1);
  cout << endl;

  myStrSwap(testSwp, testSwp1);
  cout << endl;

  myStrUpr(testUpr);
  cout << endl;

  myStrLwr(testLwr);
  cout << endl;
}

int myStrLen(const char* x)
{
  int i = 0;

  // For loop to increment the number of char in an array
  for(;; i++)
    if(x[i] == 0)break;

  // Return the number of increment = number of string
  return i;
}


void myStrCpy(char* newarray, const char* z)
{
  // For loop to copy an initialize array to a new array
  for(int i = 0;; i++)
  {
    // Set new array to be equal to initialize array
    newarray[i] = z[i];

    // If it hits null then break
    if(z[i] == 0)break;
  }
}

int myStrCmp(const char* b , const char* x)
{
  int y;

  for(int i = 0;; i++)
  {
    // Check if it's equal set y = 0
    if(x[i] == b[i])
      y = 0;

    // Check if it's not equal, set y = 1 and break
    if(x[i] != b[i])
    {
      y = 1;
      break;
    }

    // If it hits null, that means, y = 0, which is equal
    if(x[i] == 0)break;
  }

  return y;
}

void myStrSwap(char* a, char* b)
{
  char p[100];
  bool array1 = false;
  bool array2 = false;

  for(int i = 0;; i++)
  {
    // Function for swapping
    p[i] = b[i];
    b[i] = a[i];
    a[i] = p[i];

    if(a[i] == 0)array1 = true;
    if(b[i] == 0)array2 = true;
    if(array1 == true && array2 == true)break;
  }
}

void myStrUpr(char* y)
{
  char x[100];

  for(int i = 0;; i++)
  {
    // Set to new array, the uppercase of the initialize array
    x[i] = toupper(y[i]);

    // If initialize array hits null then break
    if(y[i] == 0)break;
  }
}

void myStrLwr(char* z)
{
  char w[100];

  for(int i = 0;; i++)
  {
    // Set to new array, the lowercase of the initialize array
    w[i] = tolower(z[i]);

    // If initialize array hits null then break
    if(z[i] == 0)break;
  }
}
