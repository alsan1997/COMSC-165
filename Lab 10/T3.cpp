// Lab 10, Tic-Tac-Toe Game
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>
#include <ctime>

#include <fstream>
using std::ifstream;
using std::ofstream;

void outputMe();
void printGrid(const char*);
void goXplayer(char*);
void goOplayer1(char*);
void goOplayer2(char*);
void goOplayer3(char*);
char check4Xwinner(char*);
char check4Owinner(char*);
char check4tie(char*);

int main()
{
  // Call identifying statements
  outputMe();

  // Random number
  srand(time(0)); rand();

  // Local variables
  char grid[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  char buf[100];
  int play, owins , xwins , ties ;
  char lvl;

  // File initializer
  ofstream fout;
  ifstream fin;

  fin.open("t3.ini");

  if(!fin)
  {
    cout << "File not found!" << endl;
  }
  else
  {
    fin >> xwins;
    fin >> owins;
    fin >> ties;
  }
  fin.close();

  cout << "X wins: " << xwins << endl;
  cout << "O wins: " << owins << endl;
  cout << "Ties: " << ties << endl << endl;

  // Game instructions
  cout << "ENJOY THE TICTACTOE GAME! GOODLUCK!" << endl;
  cout << "------------------------------------------------------" << endl;
  cout << "Please input the X's or O's with the following instructions." << endl;
  cout << "q or Q for upper left grid" << endl;
  cout << "w or W for upper middle grid" << endl;
  cout << "e or E for upper right grid" << endl;
  cout << "a or A for middle left grid" << endl;
  cout << "s or S for middle grid" << endl;
  cout << "d or D for middle right grid" << endl;
  cout << "z or Z for lower left grid" << endl;
  cout << "x or X for lower middle grid" << endl;
  cout << "c or C for lower right grid" << endl;
  cout << endl;

  // Main replay
  while(true)
  {
    // Choice of mode
    cout << "1. 2 players" << endl;
    cout << "2. Easy level" << endl;
    cout << "3. Hard level" << endl;
    cout << "Please choose which mode you want to play with: ";
    cin >> buf;
    lvl = atoi(buf);
    cout << endl;

    if(lvl == 1 || lvl == 2 || lvl == 3)break;
    else
    {
      cout << "Please choose only 1,2,3" << endl << endl;
      continue;
    }
  }

  while(true)
  {
    char grid[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    while(true)
    {
      printGrid(grid);
      cout << endl;
      goXplayer(grid);
      cout << endl;
      printGrid(grid);
      cout << endl;

      if(check4Xwinner(grid) == 'Y')
      {
        cout << "X player wins!" << endl;
        xwins++;
        break;
      }

      if(check4tie(grid) == 'Y')
      {
        cout << "It's a tie!" << endl;
        ties++;
        break;
      }

      switch(lvl)
      {
        case 1:
            goOplayer1(grid);
            break;
        case 2:
            cout << "It's computer turn" << endl << endl;
            goOplayer2(grid);
            break;
        case 3:
            cout << "It's computer turn" << endl << endl;
            goOplayer3(grid);
            break;
      }

      if(check4Owinner(grid) == 'Y')
      {
         printGrid(grid);
         cout << endl;
         cout << "O player wins!" << endl;
         owins++;
         break;
      }
    }

    fout.open("t3.ini");

    if(!fout)
    {
      cout << "File not found" << endl << endl;
    }

    else
    {
      fout << xwins << endl;
      fout << owins << endl;
      fout << ties << endl;
    }
    fout.close();

    cout << "X wins: " << xwins << endl;
    cout << "O wins: " << owins << endl;
    cout << "Ties: " << ties << endl << endl;

     // Another while loop to check the validity input if user want to play again
    while(true)
    {
      cout << "Would you like to play again ? Enter (Y/N): ";
      cin >> buf;
      play = atoi(buf);
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


  cout << "Thanks for playing. " << endl;
}

void outputMe()
{
  // Identifying output statements
  cout << "Lab 10, Tic-Tac-Toe Game" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Codeblocks" << endl;
  cout << "Compiler(s) used: Codeblocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

void printGrid(const char* g)
{
  // Grid diagram
  cout << g[0] << "|" << g[1] << "|" << g[2] << endl;
  cout << "-+-+-" << endl;
  cout << g[3] << "|" << g[4] << "|" << g[5] << endl;
  cout << "-+-+-" << endl;
  cout << g[6] << "|" << g[7] << "|" << g[8] << endl;
}

void goXplayer(char* g)
{
  char ch;

  // While loop to choose which grid to input and which is available
  while(true)
  {
    // Prompt user to choose which grid they want to input
    cout << "For 'X' Please enter which grid you want to input: ";
    cin >> ch;

    if(ch == 'q' || ch == 'Q')
    {
      if(g[0] == 'x' || g[0] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[0] = 'x';
        return;
      }
    }

    else if(ch == 'w' || ch == 'W')
    {
      if(g[1] == 'x' || g[1] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[1] = 'x';
        return;
      }
    }

    else if(ch == 'e' || ch == 'E')
    {
      if(g[2] == 'x' || g[2] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[2] = 'x';
        return;
      }
    }

    else if(ch == 'a' || ch == 'A')
    {
      if(g[3] == 'x' || g[3] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[3] = 'x';
        return;
      }
    }

    else if(ch == 's' || ch == 'S')
    {
      if(g[4] == 'x' || g[4] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[4] = 'x';
        return;
      }
    }

    else if(ch == 'd' || ch == 'D')
    {
      if(g[5] == 'x' || g[5] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[5] = 'x';
        return;
      }
    }

    else if(ch == 'z' || ch == 'Z')
    {
      if(g[6] == 'x' || g[6] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[6] = 'x';
        return;
      }
    }

    else if(ch == 'x' || ch == 'X')
    {
      if(g[7] == 'x' || g[7] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[7] = 'x';
        return;
      }
    }

    else if(ch == 'c' || ch == 'C')
    {
      if(g[8] == 'x' || g[8] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[8] = 'x';
        return;
      }
    }

    else
      {
        cout << "Please input with the right characters written above." << endl << endl;
        continue;
      }
  }
}

void goOplayer1(char* g)
{
  char ch;

  // While loop to choose which grid O player want to input and which is available
  while(true)
  {
    // Prompt user to input
    cout << "For 'O' Please enter which grid you want to input: ";
    cin >> ch;

    if(ch == 'q' || ch == 'Q')
    {
      if(g[0] == 'x' || g[0] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[0] = 'o';
        return;
      }
    }

    else if(ch == 'w' || ch == 'W')
    {
      if(g[1] == 'x' || g[1] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[1] = 'o';
        return;
      }
    }

    else if(ch == 'e' || ch == 'E')
    {
      if(g[2] == 'x' || g[2] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[2] = 'o';
        return;
      }
    }

    else if(ch == 'a' || ch == 'A')
    {
      if(g[3] == 'x' || g[3] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[3] = 'o';
        return;
      }
    }

    else if(ch == 's' || ch == 'S')
    {
      if(g[4] == 'x' || g[4] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[4] = 'o';
        return;
      }
    }

    else if(ch == 'd' || ch == 'D')
    {
      if(g[5] == 'x' || g[5] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[5] = 'o';
        return;
      }
    }

    else if(ch == 'z' || ch == 'Z')
    {
      if(g[6] == 'x' || g[6] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[6] = 'o';
        return;
      }
    }

    else if(ch == 'x' || ch == 'X')
    {
      if(g[7] == 'x' || g[7] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[7] = 'o';
        return;
      }
    }

    else if(ch == 'c' || ch == 'C')
    {
      if(g[8] == 'x' || g[8] == 'o')
        {
          cout << "Please enter another grid, it has already filled." << endl << endl;
          continue;
        }
      else
      {
        g[8] = 'o';
        return;
      }
    }

    else
      {
        cout << "Please input with the right characters written above." << endl << endl;
        continue;
      }
  }
}

void goOplayer2(char* g)
{
  while(true)
  {
    int choice = rand() % 9;

    if(choice == 0)
    {
      if(g[0] == 'x' || g[0] == 'o')
      continue;
      else
      {
        g[0] = 'o';
        return;
      }
    }

    if(choice == 1)
    {
      if(g[1] == 'x' || g[1] == 'o')
      continue;
      else
      {
        g[1] = 'o';
        return;
      }
    }

    if(choice == 2)
    {
      if(g[2] == 'x' || g[2] == 'o')
      continue;
      else
      {
        g[2] = 'o';
        return;
      }
    }

    if(choice == 3)
    {
      if(g[3] == 'x' || g[3] == 'o')
      continue;
      else
      {
        g[3] = 'o';
        return;
      }
    }

    if(choice == 4)
    {
      if(g[4] == 'x' || g[4] == 'o')
      continue;
      else
      {
        g[4] = 'o';
        return;
      }
    }

    if(choice == 5)
    {
      if(g[5] == 'x' || g[5] == 'o')
      continue;
      else
      {
        g[5] = 'o';
        return;
      }
    }

    if(choice == 6)
    {
      if(g[6] == 'x' || g[6] == 'o')
      continue;
      else
      {
        g[6] = 'o';
        return;
      }
    }

    if(choice == 7)
    {
      if(g[7] == 'x' || g[7] == 'o')
      continue;
      else
      {
        g[7] = 'o';
        return;
      }
    }

    if(choice == 8)
    {
      if(g[8] == 'x' || g[8] == 'o')
      continue;
      else
      {
        g[8] = 'o';
        return;
      }
    }
  }
}

void goOplayer3(char* g)
{
  // Row 1 check
  if((g[0] == 'o') && (g[1] == 'o') && (g[2] == ' '))
  {
    g[2] = 'o';
    return;
  }

  if((g[0] == 'o') && (g[1] == ' ') && (g[2] == 'o'))
  {
    g[1] = 'o';
    return;
  }

  if((g[0] == ' ') && (g[1] == 'o') && (g[2] == 'o'))
  {
    g[0] = 'o';
    return;
  }

  // Row 2 check
  if((g[3] == 'o') && (g[4] == 'o') && (g[5] == ' '))
  {
    g[5] = 'o';
    return;
  }

  if((g[3] == 'o') && (g[4] == ' ') && (g[5] == 'o'))
  {
    g[4] = 'o';
    return;
  }

  if((g[3] == ' ') && (g[4] == 'o') && (g[5] == 'o'))
  {
    g[3] = 'o';
    return;
  }

  // Row 3 check
  if((g[6] == 'o') && (g[7] == 'o') && (g[8] == ' '))
  {
    g[8] = 'o';
    return;
  }

  if((g[6] == 'o') && (g[7] == ' ') && (g[8] == 'o'))
  {
    g[7] = 'o';
    return;
  }

  if((g[6] == ' ') && (g[7] == 'o') && (g[8] == 'o'))
  {
    g[6] = 'o';
    return;
  }

  // Column 1 check
  if((g[6] == ' ') && (g[7] == 'o') && (g[8] == 'o'))
  {
    g[6] = 'o';
    return;
  }

  if((g[6] == ' ') && (g[7] == 'o') && (g[8] == 'o'))
  {
    g[6] = 'o';
    return;
  }

  if((g[0] == ' ') && (g[3] == 'o') && (g[6] == 'o'))
  {
    g[0] = 'o';
    return;
  }

  // Column 2 check
  if((g[0] == 'o') && (g[3] == ' ') && (g[6] == 'o'))
  {
    g[3] = 'o';
    return;
  }

  if((g[0] == 'o') && (g[3] == 'o') && (g[6] == ' '))
  {
    g[6] = 'o';
    return;
  }

  if((g[1] == ' ') && (g[4] == 'o') && (g[7] == 'o'))
  {
    g[1] = 'o';
    return;
  }

  // Column 3 check
  if((g[1] == 'o') && (g[4] == ' ') && (g[7] == 'o'))
  {
    g[4] = 'o';
    return;
  }

  if((g[1] == 'o') && (g[4] == 'o') && (g[7] == ' '))
  {
    g[7] = 'o';
    return;
  }

  if((g[2] == ' ') && (g[5] == 'o') && (g[8] == 'o'))
  {
    g[2] = 'o';
    return;
  }

  if((g[2] == 'o') && (g[5] == ' ') && (g[8] == 'o'))
  {
    g[5] = 'o';
    return;
  }

  if((g[2] == 'o') && (g[5] == 'o') && (g[8] == ' '))
  {
    g[8] = 'o';
    return;
  }

  // Across 1 check
  if((g[0] == ' ') && (g[4] == 'o') && (g[8] == 'o'))
  {
    g[0] = 'o';
    return;
  }

  if((g[0] == 'o') && (g[4] == ' ') && (g[8] == 'o'))
  {
    g[4] = 'o';
    return;
  }

  if((g[0] == 'o') && (g[4] == 'o') && (g[8] == ' '))
  {
    g[8] = 'o';
    return;
  }

  // Across 2 check
  if((g[2] == ' ') && (g[4] == 'o') && (g[6] == 'o'))
  {
    g[2] = 'o';
    return;
  }

  if((g[2] == 'o') && (g[4] == ' ') && (g[6] == 'o'))
  {
    g[4] = 'o';
    return;
  }

  if((g[2] == 'o') && (g[4] == 'o') && (g[6] == ' '))
  {
    g[6] = 'o';
    return;
  }

  // Row 1 block
  if((g[0] == ' ') && (g[1] == 'x') && (g[2] == 'x'))
  {
    g[0] = 'o';
    return;
  }

  if((g[0] == 'x') && (g[1] == ' ') && (g[2] == 'x'))
  {
    g[1] = 'o';
    return;
  }

  if((g[0] == 'x') && (g[1] == 'x') && (g[2] == ' '))
  {
    g[2] = 'o';
    return;
  }

  // Row 2 block
  if((g[3] == ' ') && (g[4] == 'x') && (g[5] == 'x'))
  {
    g[3] = 'o';
    return;
  }

  if((g[3] == 'x') && (g[4] == ' ') && (g[5] == 'x'))
  {
    g[4] = 'o';
    return;
  }

  if((g[3] == 'x') && (g[4] == 'x') && (g[5] == ' '))
  {
    g[5] = 'o';
    return;
  }

  // Row 3 block
  if((g[6] == ' ') && (g[7] == 'x') && (g[8] == 'x'))
  {
    g[6] = 'o';
    return;
  }

  if((g[6] == 'x') && (g[7] == ' ') && (g[8] == 'x'))
  {
    g[7] = 'o';
    return;
  }

  if((g[6] == 'x') && (g[7] == 'x') && (g[8] == ' '))
  {
    g[8] = 'o';
    return;
  }

  // Column 1 block
  if((g[0] == ' ') && (g[3] == 'x') && (g[6] == 'x'))
  {
    g[0] = 'o';
    return;
  }

  if((g[0] == 'x') && (g[3] == ' ') && (g[6] == 'x'))
  {
    g[3] = 'o';
    return;
  }

  if((g[0] == 'x') && (g[3] == 'x') && (g[6] == ' '))
  {
    g[6] = 'o';
    return;
  }

  // Column 2 block
  if((g[1] == ' ') && (g[4] == 'x') && (g[7] == 'x'))
  {
    g[1] = 'o';
    return;
  }

  if((g[1] == 'x') && (g[4] == ' ') && (g[7] == 'x'))
  {
    g[4] = 'o';
    return;
  }

  if((g[1] == 'x') && (g[4] == 'x') && (g[7] == ' '))
  {
    g[7] = 'o';
    return;
  }

  // Column 3 block
  if((g[2] == ' ') && (g[5] == 'x') && (g[8] == 'x'))
  {
    g[2] = 'o';
    return;
  }

  if((g[2] == 'x') && (g[5] == ' ') && (g[8] == 'x'))
  {
    g[5] = 'o';
    return;
  }

  if((g[2] == 'x') && (g[5] == 'x') && (g[8] == ' '))
  {
    g[8] = 'o';
    return;
  }

  // Across 1 block
  if((g[0] == ' ') && (g[4] == 'x') && (g[8] == 'x'))
  {
    g[0] = 'o';
    return;
  }

  if((g[0] == 'x') && (g[4] == ' ') && (g[8] == 'x'))
  {
    g[4] = 'o';
    return;
  }

  if((g[0] == 'x') && (g[4] == 'x') && (g[8] == ' '))
  {
    g[8] = 'o';
    return;
  }

  // Across 2 block
  if((g[2] == ' ') && (g[4] == 'x') && (g[6] == 'x'))
  {
    g[2] = 'o';
    return;
  }

  if((g[2] == 'x') && (g[4] == ' ') && (g[6] == 'x'))
  {
    g[4] = 'o';
    return;
  }

  if((g[2] == 'x') && (g[4] == 'x') && (g[6] == ' '))
  {
    g[6] = 'o';
    return;
  }

  while(true)
  {
    int choice = rand() % 9;

    if(choice == 0)
    {
      if(g[0] == 'x' || g[0] == 'o')
      continue;
      else
      {
        g[0] = 'o';
        return;
      }
    }

    if(choice == 1)
    {
      if(g[1] == 'x' || g[1] == 'o')
      continue;
      else
      {
        g[1] = 'o';
        return;
      }
    }

    if(choice == 2)
    {
      if(g[2] == 'x' || g[2] == 'o')
      continue;
      else
      {
        g[2] = 'o';
        return;
      }
    }

    if(choice == 3)
    {
      if(g[3] == 'x' || g[3] == 'o')
      continue;
      else
      {
        g[3] = 'o';
        return;
      }
    }

    if(choice == 4)
    {
      if(g[4] == 'x' || g[4] == 'o')
      continue;
      else
      {
        g[4] = 'o';
        return;
      }
    }

    if(choice == 5)
    {
      if(g[5] == 'x' || g[5] == 'o')
      continue;
      else
      {
        g[5] = 'o';
        return;
      }
    }

    if(choice == 6)
    {
      if(g[6] == 'x' || g[6] == 'o')
      continue;
      else
      {
        g[6] = 'o';
        return;
      }
    }

    if(choice == 7)
    {
      if(g[7] == 'x' || g[7] == 'o')
      continue;
      else
      {
        g[7] = 'o';
        return;
      }
    }

    if(choice == 8)
    {
      if(g[8] == 'x' || g[8] == 'o')
      continue;
      else
      {
        g[8] = 'o';
        return;
      }
    }
  }
}

char check4Xwinner(char* g)
{
  // Row 1 check for x winner
  if((g[0] == 'x') && (g[1] == 'x') && (g[2] == 'x'))
  {
    return 'Y';
  }

  // Row 2 check for x winner
  else if((g[3] == 'x') && (g[4] == 'x') && (g[5] == 'x'))
  {
    return 'Y';
  }

  // Row 3 check for x winner
  else if((g[6] == 'x') && (g[7] == 'x') && (g[8] == 'x'))
  {
    return 'Y';
  }

  // Column 1 check for x winner
  else if((g[0] == 'x') && (g[3] == 'x') && (g[6] == 'x'))
  {
    return 'Y';
  }

  // Column 2 check for x winner
  else if((g[1] == 'x') && (g[4] == 'x') && (g[7] == 'x'))
  {
    return 'Y';
  }

  // Column 3 check for x winner
  else if((g[2] == 'x') && (g[5] == 'x') && (g[8] == 'x'))
  {
    return 'Y';
  }

  // Across 1 check for x winner
  else if((g[0] == 'x') && (g[4] == 'x') && (g[8] == 'x'))
  {
    return 'Y';
  }

  // Across 2 check for winner
  else if((g[2] == 'x') && (g[4] == 'x') && (g[6] == 'x'))
  {
    return 'Y';
  }

  else
    return 'N';
}

char check4Owinner(char* g)
{
  // Row 1 check
  if((g[0] == 'o') && (g[1] == 'o') && (g[2] == 'o'))
  {
    return 'Y';
  }

  // Row 2 check
  else if((g[3] == 'o') && (g[4] == 'o') && (g[5] == 'o'))
  {
    return 'Y';
  }

  // Row 3 check
  else if((g[6] == 'o') && (g[7] == 'o') && (g[8] == 'o'))
  {
    return 'Y';
  }

  // Column 1 check
  else if((g[0] == 'o') && (g[3] == 'o') && (g[6] == 'o'))
  {
    return 'Y';
  }

  // Column 2 check
  else if((g[1] == 'o') && (g[4] == 'o') && (g[7] == 'o'))
  {
    return 'Y';
  }

  // Column 3 check
  else if((g[2] == 'o') && (g[5] == 'o') && (g[8] == 'o'))
  {
    return 'Y';
  }

  // Across 1 check
  else if((g[0] == 'o') && (g[4] == 'o') && (g[8] == 'o'))
  {
    return 'Y';
  }

  // Across 2 check
  else if((g[2] == 'o') && (g[4] == 'o') && (g[6] == 'o'))
  {
    return 'Y';
  }

  else
    return 'N';
}

char check4tie(char *g)
{
  // Check every grid if there is an empty means it's not tie
  if(g[0] == ' ')
    return 'N';
  else if(g[1] == ' ')
    return 'N';
  else if(g[2] == ' ')
    return 'N';
  else if(g[3] == ' ')
    return 'N';
  else if(g[4] == ' ')
    return 'N';
  else if(g[5] == ' ')
    return 'N';
  else if(g[6] == ' ')
    return 'N';
  else if(g[7] == ' ')
    return 'N';
  else if(g[8] == ' ')
    return 'N';
  else
    return 'Y';
}
