// Lab 16, Applied Recursion
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::endl;
using std::cin;
using std::cout;
using std::ios;

#include <cstring>
using std::string;

#include <cstdlib>

#include <fstream>
using std::fstream;

// Struct Definition
struct animal
{
  char text[100];
  animal* yes;
  animal* no;
};

void outputME();
void deallocateTree(animal*);
void saveTree(animal*, fstream&);
void restoreTree(animal*, fstream&);

int main()
{
  // Variables
  char buf[100];
  char a[100];
  char q[100];
  char yesNo;
  char x[100];
  char y[100];
  int choice;
  char answer;

  // Identifying output call
  outputME();

  // initialize a "root" pointer named "animal* root"
  animal* root;

  // set "root" to a newly created node; set its text to "elephant", pointers to 0
  root = new animal;
  strcpy(root->text, "elephant");
  root->yes = 0;
  root->no = 0;

  // restore tree from a disk file
  fstream fin;
  fin.open("Animal.dat", ios::in|ios::binary);
  restoreTree(root, fin); // create an empty root node before calling this
  fin.close();

  // start a "while" loop that runs each cycle of the program
  while(true)
  {
    // invite the user to think of an animal which it will try to guess
    // await the user's response, and break out of the loop if he declines
    while(true)
    {
      cout << "Think of an animal and I will try to guess it..Wanna try? Enter Y/N: ";
      cin >> buf;
      choice = atoi(buf);

      if(buf[0] == 'N' || buf[0] == 'n' || buf[0] == 'y' || buf[0] == 'Y')break;
      cout << "Please enter upper or lower case Y/N." << endl << endl;
    }

    if(buf[0] == 'n' || buf[0] == 'N')break;

    // declare a pointer "p" to traverse the tree, and initialize it to "root"
    animal* p = root;

    // start a loop to traverse the binary tree
    while(true)
    {
      if(p->yes == 0) // if p->yes is 0...
      {
        while(true)
        {
          //...print p->text as the guessed animal
          // ask user if this is correct
          cout << "Is " << p->text << " the animal that you're thinking of ? ";
          cin >> buf;
          cin.ignore(1000, 10);
          answer = atoi(buf);
          if(buf[0] == 'N' || buf[0] == 'n' || buf[0] == 'y' || buf[0] == 'Y')break;

          if(buf[0] == 'e')
          {
            // Prompt user what they want the answer should be
            cout << "What do you want to change " << p->text << " to ?: ";
            cin.getline(x, 100);

            // copy answer to p->text
            strcpy(p->text, x);
            cout << endl;
            continue;
          }
        }

        // if correct, brag and break from loop
        if(buf[0] == 'y' || buf[0] == 'Y')
        {
          cout << "Horeee, I'm correct" << endl << endl;
          break;
        }

        // ask user what animal he was thinking of...
        cout << "What animal are you thinking of ?: ";
        cin.getline(a, 100); // Store in char a[100]

        // ask what yes/no question differentiates "p->text" from "a"...
        cout << "What yes/no question differentiates " << p->text << " from " << a << " ?: ";
        cin.getline(q, 100); // Store in char q[100];

        while(true)
        {
          // ask which response is correct for "a" -- yes or no...
          cout << "Which respons is correct for " << a <<" ? yes or no ?: ";
          cin >> buf; //...store in "char yesNo"
          yesNo = atoi(buf);
          cin.ignore(1000, 10);

          if(buf[0] == 'y' || buf[0] == 'n'||buf[0] == 'Y' || buf[0] == 'N')break;
          else
          {
             cout << "Enter only yes or no !" << endl << endl;
          }
        }

        // create two new nodes, names "y" and "n"
        animal* y = new animal;
        animal* n = new animal;

        if(buf[0] == 'y' || buf[0] == 'Y') // if the correct response for "a" is yes...
        {
          strcpy(y->text, a); // copy "a" into y->text
          strcpy(n->text, p->text); // copy p->text into n->text
        }

        else if(buf[0] == 'n' || buf[0] == 'N')
        {
          strcpy(n->text, a); // copy "a" into n->text
          strcpy(y->text, p->text); // copy p->text into y->text
        }

        strcpy(p->text, q); // copy "q" into p->text

        // set y->yes, n->yes, y->no, and n->no to 0
        y->yes = 0, y->no = 0;
        n->yes = 0, n->no = 0;

        // set p->yes to y and p->no to n
        p->yes = y, p->no = n;

        // Notify changes and break from loop
        cout << "Thank you for your information!" << endl;
        cout << endl;
        break;
      }


      else if(p->yes != 0) // else if p->yes is not 0
      {
        while(true)
        {
          cout << p->text << " yes / no: "; // print p->text as a question
          cin >> buf;
          yesNo = atoi(buf);
          cin.ignore(1000, 10);

          // if "yes", set p to p->yes
          if (buf[0] == 'y' || buf[0] == 'Y')
          {
            p = p->yes;
            break;
          }

          // if no set p to p->no
          if(buf[0] == 'n' || buf[0] == 'N')
          {
            p = p->no;
            break;
          }

          // If users enter e...
          if(buf[0] == 'e' || buf[0] == 'E')
          {
            // Prompt user to change the question
            cout << "What do you want the question '" << p->text << "' change into ?: ";
            cin.getline(y, 100);

            // Copy new question to pointer pointing text
            strcpy(p->text, y);

            cout << endl;
            continue;
          }

          // If users enter d
          if(buf[0] == 'd' || buf[0] == 'D')
          {
            // remove pointer pointing to yes or no
            deallocateTree(p->yes);
            deallocateTree(p->no);

            // copy elephant to p->text and for later editing
            strcpy(p->text, "Elephant");

            // Set pointers to yes or no to 0 and break
            p->yes = 0;
            p->no = 0;
            break;
          }
        }
      }
    }
  }

  // save tree to a disk file
  fstream fout;
  fout.open("animal.dat", ios::out|ios::binary);
  saveTree(root, fout);
  fout.close();

  // reclaim memory
  deallocateTree(root);
}

void outputME()
{
  // Identifying output statements
  cout << "Lab 16, Applied recursion" << endl;
  cout << "Programmer: Aldo Sanjoto" << endl;
  cout << "Editor(s) used: Code::Blocks " << endl;
  cout << "Compiler(s) used: Code::Blocks" << endl;
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
}

// Function definition
void deallocateTree(animal* a)
{
  if (!a) return;
  deallocateTree(a->yes);
  deallocateTree(a->no);
  delete a;
}

// function definitions -- save and restore
void saveTree(animal* a, fstream& out) // saves tree to disk file
{
  if (a)
  {
    out.write((char*)a, sizeof(animal));
    saveTree(a->yes, out);
    saveTree(a->no, out);
  }
}

void restoreTree(animal* a, fstream& in) // loads tree from disk file
{
  in.read((char*)a, sizeof(animal));
  if(a->yes)
  {
    restoreTree(a->yes = new animal, in);
    restoreTree(a->no = new animal, in);
  }
}
