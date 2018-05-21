// Lab 6, Arrays and Vectors in C++
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

// Prototype
int readArray(int, int[]);
int stat(int, const int[], int&, int&, int&);
int histogram(int, const int[], int[]);

int main()
{
  // Local Variable
  const int MAX_SCORE = 50;
  int score[MAX_SCORE];
  int numOfScores, aveS, minS, maxS;
  int grade[5];

  // Identifying output statements
  cout << "Lab 6, Arrays and Vectors in C ++" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks" << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Number of Scores
  numOfScores = readArray(MAX_SCORE, score);

  // If Statements to check if there's a number inputted
  if(stat(numOfScores, score, minS, maxS, aveS) == 0)
  {
    // Output min,max,avg score
    cout << endl;
    cout << "Min. Score: " << minS << endl;
    cout << "Max. Score: " << maxS << endl;
    cout << "Avg. Score: " << aveS << endl;

    // A histogram data and call histogram function
    histogram(numOfScores, score, grade);
    cout << "As: " << grade[0] << endl;
    cout << "Bs: " << grade[1] << endl;
    cout << "Cs: " << grade[2] << endl;
    cout << "Ds: " << grade[3] << endl;
    cout << "Fs: " << grade[4] << endl;
  }

  else
    cout << endl;
    cout << "No Data" << endl;
}

// ReadArray function
int readArray(int x, int y[])
{
  // Local Variable
  char buf[100];
  int nScores = 0;

  // Prompt user to input data
  cout << "Enter number with range between 0 - 100." << endl;
  cout << "Enter the scores up to 50 numbers, and enter q or Q to quit. " << endl;

  // For loop to input data until user enter q or Q
  for(int i = 0; i < x; i++)
  {
    cout << "Score: ";
    cin >> buf;
    y[i] = atoi(buf);

    // If statement to check range of score
    if(y[i] < 0 || y[i] > 100)
    {
      cout << "Enter only 0 - 100 score. Try again. " << endl << endl;
      i = i - 1;
      continue;
    }

    // If statement to check if user enter Q or q
    if(buf[0] == 'q' || buf[0] == 'Q')break;
    else
      nScores++;
  }

  return nScores;
}

// Stat function
int stat(int n, const int y[], int& mini, int& maxi, int& avgXX)
{
  // Local Variable
  int balance = 0;
  mini = y[0];
  maxi = y[0];

  // If statement to check if numofscores is 0
  if(n == 0)
    return 1;

  // Sorting min. and max score and average score
  for(int i = 0; i < n; i++)
  {
     if(mini > y[i]) mini = y[i];
     if(maxi < y[i]) maxi = y[i];
     balance = balance + y[i];
  }

  avgXX = balance / n ;

  return 0;
}

// histogram function
int histogram(int n, const int y[], int gra[])
{
  // initialize array
  gra[0] = 0;
  gra[1] = 0;
  gra[2] = 0;
  gra[3] = 0;
  gra[4] = 0;

  // Check whether numofscore is 0
  if(n == 0)
    return 1;

  // For loop to increment the data for the selected range
  for(int i = 0; i < n; i++)
  {
    if(y[i] >= 90)
      gra[0]++;

    else if(y[i] >= 80)
      gra[1]++;

    else if(y[i] >= 70)
      gra[2]++;

    else if(y[i] >= 60)
      gra[3]++;

    else
      gra[4]++;
  }

  return 0;
}
