#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>

int readArray(int, int[]);
int avg(int, int[]);

int main()
{
  const int MAX_SCORE = 50;
  int score[MAX_SCORE];
  int numOfScores, average;

  numOfScores = readArray(MAX_SCORE, score);
  cout << "The number of scores entered is: " << numOfScores << endl;
  average = avg(numOfScores, score);
  cout << "The average of scores entered is: " << average << endl;
}

int readArray(int x, int y[])
{
  char buf[100];
  int nScores = 0;
  cout << "Enter the scores up to 50 numbers, and enter q or Q to quit. " << endl;
  for(int i = 0; i < x; i++)
  {
    cout << "Score: ";
    cin >> buf;
    y[i] = atoi(buf);

    if(y[i] < 0 || y[i] > 100)
    {
      cout << "Enter score only between 0 - 100" << endl;
      continue;
    }

    if(buf[0] == 'q' || buf[0] == 'Q')break;
    else
      nScores++;
  }

  return nScores;
}

int avg(int n, int y[])
{
  int balance = 0;
  int avgXX;
  for(int x = 0; x < n; x++)
  {
    balance = balance + y[x];
  }

  return avgXX = balance / n;
}
