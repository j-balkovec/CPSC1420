// Jakob Balkovec
// p2.cpp
// This program recreates the game called Hi-Ho-Cherry-O!
// game is made for 2 players only
// the goal is to pick all 10 cherries and put them in your bucket

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

string playerTurn, name1, name2;
int tree1, tree2, basket1, basket2;
int spin;
int const MAX_SPIN = 7;
int const MIN_SPIN = 1;
char choice;
const char YES = 'Y';

int main()
{
  do
    {
      cout << endl
           << endl;
      basket1 = 0;
      basket2 = 0;
      tree1 = 10;
      tree2 = 10;
      
      cout << "Welcome to a fun game called Hi-Ho-Cherry-O!";
      cout << endl;
      
      playerTurn = "p1";
      
      cout << endl;
      cout << "Player1 what is your name? ";
      cin >> name1;
      cin.get();
      cout << endl;
      cout << "Player2 what is your name? ";
      cin >> name2;
      cin.get();
      cout << endl;
      
      while ((basket1 < 10 || basket2 < 10) && (tree1 > 0 || tree2 > 0))
        {
          if (playerTurn == "P1" || playerTurn == "p1")
            {
              cout << endl
                   << endl;
              cout << name1 << " please press enter to spin... ";
              cin.get();
              cout << endl;
            }
          else
            {
              cout << endl
                   << endl;
              cout << name2 << " please press enter to spin... ";
              cin.ignore();
              cout << endl;
            }
          
          srand(time(0));
          spin = rand() % ((MAX_SPIN - MIN_SPIN) + 1) + MIN_SPIN;
          cout << "You spun: " << spin;
          cout << endl;
          
          switch (spin)
            {
            case 1:
              if (playerTurn == "P1" || playerTurn == "p1")
                {
                  cout << "1 cherry was added to the bucket " << endl;
                  tree1--;
                  basket1++;
                  
                  cout << name1 << "'s bucket: " << basket1 << endl;
                  cout << name1 << "'s tree: " << tree1 << endl;
                }
              else
                {
                  cout << "1 cherry was added to the bucket " << endl;
                  tree2--;
                  basket2++;
                  
                  cout << name2 << "'s bucket: " << basket2 << endl;
                  cout << name2 << "'s tree: " << tree2 << endl;
                }
              break;
              
            case 2:
              if (playerTurn == "P1" || playerTurn == "p1")
                {
                  cout << "2 cherries were added to the bucket " << endl;
                  if (tree1 == 1)
                    {
                      tree1 -= 1;
                      basket1 += 1;
                    }
                  else
                    {
                      tree1 -= 2;
                      basket1 += 2;
                    }
                  
                  cout << name1 << "'s bucket: " << basket1 << endl;
                  cout << name1 << "'s tree: " << tree1 << endl;
                }
              else
                {
                  cout << "2 cherries were added to the bucket " << endl;
                  if (tree2 == 1)
                    {
                      tree2 -= 1;
                      basket2 += 1;
                    }
                  else
                    {
                      tree2 -= 2;
                      basket2 += 2;
                    }
                  
                  cout << name2 << "'s bucket: " << basket2 << endl;
                  cout << name2 << "'s tree: " << tree2 << endl;
                }
              break;
              
            case 3:
              if (playerTurn == "P1" || playerTurn == "p1")
                {
                  cout << "3 cherries were added to the bucket " << endl;
                  if (tree1 == 2)
                    {
                      tree1 -= 2;
                      basket1 += 2;
                    }
                  else if (tree1 == 1)
                    {
                      tree1 -= 1;
                      basket1 += 1;
                    }
                  else
                    {
                      tree1 -= 3;
                      basket1 += 3;
                    }
                  
                  cout << name1 << "'s bucket: " << basket1 << endl;
                  cout << name1 << "'s tree: " << tree1 << endl;
                }
              else
                {
                  cout << "3 cherries were added to the bucket " << endl;
                  if (tree2 == 2)
                    {
                      tree2 -= 2;
                      basket2 += 2;
                    }
                  else if (tree2 == 1)
                    {
                      tree2 -= 1;
                      basket2 += 1;
                    }
                  else
                    {
                      tree2 -= 3;
                      basket2 += 3;
                    }
                  
                  cout << name2 << "'s bucket: " << basket2 << endl;
                  cout << name2 << "'s tree: " << tree2 << endl;
                }
              break;
              
            case 4:
              if (playerTurn == "P1" || playerTurn == "p1")
                {
                  cout << "4 cherries were added to the bucket " << endl;
                  if (tree1 == 1)
                    {
                      tree1 -= 1;
                      basket1 += 1;
                    }
                  else if (tree1 == 2)
                    {
                      tree1 -= 2;
                      basket1 += 2;
                    }
                  else if (tree1 == 3)
                    {
                      tree1 -= 3;
                      basket1 += 3;
                    }
                  else
                    {
                      tree1 -= 4;
                      basket1 += 4;
                    }
                  
                  cout << name1 << "'s bucket: " << basket1 << endl;
                  cout << name1 << "'s tree: " << tree1 << endl;
                }
              else
                {
                  cout << "4 cherries were added to the bucket " << endl;
                  if (tree2 == 1)
                    {
                      tree2 -= 1;
                      basket2 += 1;
                    }
                  else if (tree2 == 2)
                    {
                      tree2 -= 2;
                      basket2 += 2;
                    }
                  else if (tree2 == 3)
                    {
                      tree2 -= 3;
                      basket2 += 3;
                    }
                  else
                    {
                      tree2 -= 4;
                      basket2 += 4;
                    }
                  
                  cout << name2 << "'s bucket: " << basket2 << endl;
                  cout << name2 << "'s tree: " << tree2 << endl;
                }
              break;
              
            case 5:
              cout << "2 cherries have been removed from the bucket, " << endl
                   << "they have been added back to the tree. " << endl;
              if (playerTurn == "P1" || playerTurn == "p1")
                {
                  if (basket1 == 0)
                    {
                      basket1 = 0;
                      tree1 = 10;
                    }
                  else if (basket1 == 1)
                    {
                      basket1 = 1;
                      tree1 = 9;
                    }
                  else
                    {
                      tree1 += 2;
                      basket1 -= 2;
                    }
                  
                  cout << name1 << "'s bucket: " << basket1 << endl;
                  cout << name1 << "'s tree: " << tree1 << endl;
                }
              else if (playerTurn == "P2" || playerTurn == "p2")
                {
                  if (basket2 == 0)
                    {
                      basket2 = 0;
                      tree2 = 10;
                    }
                  else if (basket2 == 1)
                    {
                      basket2 = 1;
                      tree2 = 9;
                    }
                  else
                    {
                      tree2 += 2;
                      basket2 -= 2;
                    }
                  
                  cout << name2 << "'s bucket: " << basket2 << endl;
                  cout << name2 << "'s tree: " << tree2 << endl;
                }
              break;
              
            case 6:
              cout << "2 cherries have been removed from the bucket, " << endl
                   << "they have been added back to the tree. " << endl;
              if (playerTurn == "P1" || playerTurn == "p1")
                {
                  if (basket1 == 0)
                    {
                      basket1 = 0;
                      tree1 = 10;
                    }
                  else if (basket1 == 1)
                    {
                      basket1 = 1;
                      tree1 = 9;
                    }
                  else
                    {
                      tree1 += 2;
                      basket1 -= 2;
                    }
                  cout << name1 << "'s bucket: " << basket1 << endl;
                  cout << name1 << "'s tree: " << tree1 << endl;
                }
              else if (playerTurn != "P1" || playerTurn != "p1")
                {
                  if (basket2 == 0)
                    {
                      basket2 = 0;
                      tree2 = 10;
                    }
                  else if (basket2 == 1)
                    {
                      basket2 = 1;
                      tree2 = 9;
                    }
                  else
                    {
                      tree2 += 2;
                      basket2 -= 2;
                    }
                  cout << name2 << "'s bucket: " << basket2 << endl;
                  cout << name2 << "'s tree: " << tree2 << endl;
                }
              break;
              
            case 7:
              cout << "All cherries have been retuerned to the tree. " << endl;
              if (playerTurn == "P1" || playerTurn == "p1")
                {
                  basket1 = 0;
                  tree1 = 10;
                  
                  cout << name1 << "'s bucket: " << basket1 << endl;
                  cout << name1 << "'s tree: " << tree1 << endl;
                }
              else
                {
                  basket2 = 0;
                  tree2 = 10;
                  
                  cout << name2 << "'s bucket: " << basket2 << endl;
                  cout << name2 << "'s tree: " << tree2 << endl;
                }
              break;
            }
          
          if (playerTurn == "p1" || playerTurn == "P1")
            {
              playerTurn = "p2";
            }
          else
            {
              playerTurn = "p1";
            }
          if (basket1 == 10)
            {
              cout << endl;
              cout << name1 << " won! Congratulations!!! ";
              cout << endl;
            }
          else if (basket2 == 10)
            {
              cout << endl;
              cout << name2 << " won! Congratulations!!! ";
              cout << endl;
            }
        }
      cout << endl
           << endl;
      
      cout << "I hope you enjoyed a game of Hi-Ho-Cherry-O" << endl;
      cout << "Goodbye! " << endl;
      cout << endl;
      cout << "Press enter to continue... ";
      cin.get();
      cout << endl;
      
      cout << "Do you want to play again? (Y/N):  ";
      cin >> choice;
      
    } while (choice == YES);
  if (choice != YES)
    {
      cout << "Alright, thank you for playing! " << endl;
    }
  
  cout << endl << endl;
  return 0;
}
