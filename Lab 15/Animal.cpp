// Lab 15, Advanced Linked Structures
// Programmer: Aldo Sanjoto
// Editor(s) used: Code::Blocks
// Compiler(s) used: Code::Blocks

#include <iostream>
using std::endl;
using std::cin;
using std::cout;

#include <cstring>
using std::string;

#include <cstdlib>

// Struct Definition
struct animal
{
  char text[100];
  animal* yes;
  animal* no;
};

void outputME();
void deallocateTree(animal*);

int main()
{
  // Variables
  char buf[100];
  char a[100];
  char q[100];
  char yesNo;
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
          answer = atoi(buf);
          cin.ignore(1000, 10);
          if(buf[0] == 'y' || buf[0] == 'n' || buf[0] == 'Y' || buf[0] == 'N')break;
          cout << "Please enter yes or no." << endl << endl;
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

        else if(buf[0] == 'N' || buf[0] == 'n') // else if the correct response is no...
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
          if(buf[0] == 'y' || buf[0] == 'n' || buf[0] == 'Y' || buf[0] == 'N')break;
          cout << "Please enter yes or no" << endl << endl;
        }

        // if "yes", set p to p->yes
        if (buf[0] == 'y' || buf[0] == 'Y')
        p = p->yes;

        // else set p to p->no
        else
        p = p->no;
      }
    }
  }

  // reclaim memory
  deallocateTree(root);
}

void outputME()
{
  // Identifying output statements
  cout << "Lab 15, Advanced Linked Structures" << endl;
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
