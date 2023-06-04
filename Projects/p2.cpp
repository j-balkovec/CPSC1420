// {
// Jakob Balkovec
// CPSC 1420 Project 2 - Hi-Ho-Cherry-O! Game
// Last Modified: 2022-10-01
// }

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <random>

static int const MAX_SPIN = 7;
static int const MIN_SPIN = 1;
static const char YES = 'Y';

enum SPIN {
  ONE = 1,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN
};

/** {
 * Displays information about the last compilation of the file.
 * @return void
    } **/
static inline void show_last_compiled() {
  std::cout << "\n[file]: " << __FILE__ << '\n'
    << "[compiled on]: " << __DATE__ << " at " << __TIME__ << '\n'
    << "[compiler]: " << __VERSION__ << '\n'
    << "[timestamp]: " << __TIMESTAMP__ << '\n';
}

/** {
 * Returns a tuple containing two player names after prompting for them via
 * standard input.
 * @return A tuple containing two player names as strings.
 * @throws None
    } **/
static inline std::tuple<std::string, std::string> welcome() {
  std::string name1, name2;
  std::cout << "\n\nWelcome to Hi-Ho-Cherry-O!\n\n";

  std::cout << "[player_1 name]: ";
  std::cin >> name1;

  std::cout << "[player_2 name]: ";
  std::cin >> name2;

  return std::make_tuple(name1, name2);
}

/** {
 * Returns the value of the "turn" parameter after prompting the user to enter either "p1" or "p2".
 * @param turn the string to prompt the user to enter a value into
 * @return the value of the "turn" parameter after it has been transformed to lowercase
 * @throws std::invalid_argument if the user enters a value other than "p1" or "p2"
    } **/
static inline std::string goes_first(std::string& turn) {
  while (true) {
    std::cout << "\n[who goes first]: ";
    std::cin >> turn;
    std::transform(turn.begin(), turn.end(), turn.begin(), ::tolower);
    try {
      if (turn != "p1" && turn != "p2") {
        throw std::invalid_argument("invalid input, please enter either \"p1\" or \"p2\"");
      }
      break; // Exit the loop if the input is valid
    }
    catch (const std::exception& e) {
      std::cerr << "[error]: " << e.what() << std::endl;
    }
  }
  return turn;
}

/** {
 * Generates a random integer within a specified range.
 * @return an integer between MIN_SPIN and MAX_SPIN (inclusive)
 * @throws None
    } **/
static inline int spin() {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<int> dist(MIN_SPIN, MAX_SPIN);
  return dist(rng);
}

/** {
 * Calculates the sum of a spin after prompting the user to press "Enter" to
 * spin. Prints the name of the user and the number they spun.
 * @param name the name of the user
 * @return the number spun by the user
 * @throws None
    } **/
static inline int sum(std::string name) {
  std::cout << name << "  press [Enter] to spin: ";
  std::cin.ignore();
  int spin_ = spin();
  std::cin.ignore();
  std::cout << "[" << name << " spun]: " << spin_ << std::endl;
  return spin_;
}

/** {
 * Shows the status of the game for the specified player turn, displaying the
 * contents of their bucket and tree.
 * @param player_turn the player whose turn it is, either "P1" or "p1" for player 1 or "P2" or "p2" for player 2.
 * @param name1 the name of player 1.
 * @param name2 the name of player 2.
 * @param player_basket_1 the number of nuts in player 1's bucket.
 * @param player_basket_2 the number of nuts in player 2's bucket.
 * @param tree_1 the number of nuts in player 1's tree.
 * @param tree_2 the number of nuts in player 2's tree.
 * @throws None.
    } **/
static inline void show_status(std::string player_turn, std::string name1, std::string name2, int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2) {
  if (player_turn == "P1" || player_turn == "p1") {
    std::cout << name1 << "'s bucket: " << player_basket_1 << std::endl;
    std::cout << name1 << "'s tree: " << tree_1 << "\n\n";
  }
  else {
    std::cout << name2 << "'s bucket: " << player_basket_2 << std::endl;
    std::cout << name2 << "'s tree: " << tree_2 << "\n\n";
  }
}

/** {
 * Adds one cherry to the player's basket and reduces the count of cherries in the corresponding tree.
 *
 * @param player_basket_1 an integer reference representing the first player's cherry basket
 * @param player_basket_2 an integer reference representing the second player's cherry basket
 * @param tree_1 an integer reference representing the count of cherries in the first tree
 * @param tree_2 an integer reference representing the count of cherries in the second tree
 * @param player_turn a string representing the current player's turn
 * @param name1 a constant string representing the name of the first player
 * @param name2 a constant string representing the name of the second player
 *
 * @throws none
    } **/
static inline void add_cherry(int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  const std::string P1 = "p1";
  if (player_turn == "P1" || player_turn == P1) {
    std::cout << "\n[1 cherry was added to the bucket]\n";
    --tree_1;
    ++player_basket_1;

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
  else {
    std::cout << "\n[1 cherry was added to the bucket]\n";
    --tree_2;
    ++player_basket_2;

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
}

/** {
 * Updates the game status when a player selects two cherries. The function
 * takes two baskets and two trees, and updates one of the baskets and one of
 * the trees depending on the player's turn, using the following logic:
 *  - If it's player 1's turn, 1 cherry is removed from the first tree and
 *    added to player 1's basket if the first tree has 1 cherry, or 2 cherries
 *    are removed from the first tree and added to player 2's basket otherwise.
 *  - If it's player 2's turn, 1 cherry is removed from the second tree and
 *    added to player 2's basket if the second tree has 1 cherry, or 2 cherries
 *    are removed from the second tree and added to player 2's basket otherwise.
 * The function also prints the message "[2 cherries were added to the bucket]"
 * for both players.
 *
 * @param player_basket_1 the number of cherries in player 1's basket
 * @param player_basket_2 the number of cherries in player 2's basket
 * @param tree_1 the number of cherries in the first tree
 * @param tree_2 the number of cherries in the second tree
 * @param player_turn a string indicating the current player's turn, either "P1"
 *                    or "P2"
 * @param name1 the name of player 1
 * @param name2 the name of player 2
 *
 * @throws None
    } **/
static inline void two(int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  if (player_turn == "P1" || player_turn == "p1") {
    std::cout << "[2 cherries were added to the bucket]\n";
    if (tree_1 == 1) {
      tree_1--;
      player_basket_1++;
    }
    else {
      tree_1 -= 2;
      player_basket_2 += 2;
    }
    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
  else {
    std::cout << "[2 cherries were added to the bucket]\n";
    if (tree_2 == 1) {
      tree_2--;
      player_basket_2++;
    }
    else {
      tree_2 -= 2;
      player_basket_2 += 2;
    }

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
}

/** {
 * Updates the player's basket, the tree, and the game status when the player adds three cherries to their basket.
 *
 * @param player_basket_1 number of cherries in player 1's basket
 * @param player_basket_2 number of cherries in player 2's basket
 * @param tree_1 number of cherries on tree 1
 * @param tree_2 number of cherries on tree 2
 * @param player_turn the player whose turn it is
 * @param name1 name of player 1
 * @param name2 name of player 2
 *
 * @throws None
    } **/
static inline void three(int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  if (player_turn == "P1" || player_turn == "p1") {
    std::cout << "\n[3 cherries were added to the bucket]\n";
    if (tree_1 == 2) {
      tree_1 -= 2;
      player_basket_1 += 2;
    }
    else if (tree_1 == 1) {
      tree_1 -= 1;
      player_basket_1 += 1;
    }
    else {
      tree_1 -= 3;
      player_basket_1 += 3;
    }

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
  else {
    std::cout << "\n[3 cherries were added to the bucket]\n";
    if (tree_2 == 2) {
      tree_2 -= 2;
      player_basket_2 += 2;
    }
    else if (tree_2 == 1) {
      tree_2 -= 1;
      player_basket_2 += 1;
    }
    else {
      tree_2 -= 3;
      player_basket_2 += 3;
    }
    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
}

/** {
 * Updates the game state when a player takes four cherries from a tree.
 *
 * @param player_basket_1 reference to player 1's cherry basket
 * @param player_basket_2 reference to player 2's cherry basket
 * @param tree_1 reference to tree 1's remaining cherries
 * @param tree_2 reference to tree 2's remaining cherries
 * @param player_turn reference to the current player's turn
 * @param name1 the name of player 1
 * @param name2 the name of player 2
 *
 * @return void
 *
 * @throws none
     } **/
static inline void four(int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  if (player_turn == "P1" || player_turn == "p1") {
    std::cout << "\n[4 cherries were added to the bucket]\n";
    if (tree_1 == 1) {
      tree_1--;
      player_basket_1++;
    }
    else if (tree_1 == 2) {
      tree_1 -= 2;
      player_basket_1 += 2;
    }
    else if (tree_1 == 3) {
      tree_1 -= 3;
      player_basket_1 += 3;
    }
    else {
      tree_1 -= 4;
      player_basket_1 += 4;
    }

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
  else {
    std::cout << "\n[4 cherries were added to the bucket]\n";
    if (tree_2 == 1) {
      tree_2 -= 1;
      player_basket_2 += 1;
    }
    else if (tree_2 == 2) {
      tree_2 -= 2;
      player_basket_2 += 2;
    }
    else if (tree_2 == 3) {
      tree_2 -= 3;
      player_basket_2 += 3;
    }
    else {
      tree_2 -= 4;
      player_basket_2 += 4;
    }

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
}

/** {
 * Updates the game state after a player has taken 5 cherries from their basket and returned them to the tree.
 *
 * @param player_basket_1 An integer reference to player 1's cherry basket.
 * @param player_basket_2 An integer reference to player 2's cherry basket.
 * @param tree_1 An integer reference to the cherry tree from which player 1's cherries have been taken.
 * @param tree_2 An integer reference to the cherry tree from which player 2's cherries have been taken.
 * @param player_turn A string indicating the current player's turn.
 * @param name1 A constant string reference to player 1's name.
 * @param name2 A constant string reference to player 2's name.
 *
 * @return void
 *
 * @throws None
     } **/
static inline void five(int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  std::cout << "\n[2 cherries have been removed from the bucket, and returned to the tree]\n";
  if (player_turn == "P1" || player_turn == "p1") {
    if (player_basket_1 == 0) {
      player_basket_1 = 0;
      tree_1 = 10;
    }
    else if (player_basket_1 == 1) {
      player_basket_1 = 1;
      tree_1 = 9;
    }
    else {
      tree_1 += 2;
      player_basket_1 -= 2;
    }

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
  else if (player_turn == "P2" || player_turn == "p2") {
    if (player_basket_2 == 0) {
      player_basket_2 = 0;
      tree_2 = 10;
    }
    else if (player_basket_2 == 1) {
      player_basket_2 = 1;
      tree_2 = 9;
    }
    else {
      tree_2 += 2;
      player_basket_2 -= 2;
    }

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
}

/** {
 * Updates the state of the game by removing two cherries from the player's
 * basket and returning them to the tree. If it is player 1's turn, then
 * parameter player_basket_1 is updated and if it is player 2's turn,
 * parameter player_basket_2 is updated accordingly. If a player's basket is
 * empty, then their basket is set to 0 and the corresponding tree is set to 10.
 * If a player's basket has one cherry, then their basket is set to 1 and the
 * corresponding tree is set to 9. If a player's basket has two or more cherries,
 * then two cherries are removed from the basket and returned to the tree.
 *
 * @param player_basket_1 The number of cherries in player 1's basket.
 * @param player_basket_2 The number of cherries in player 2's basket.
 * @param tree_1 The number of cherries left on the tree for player 1.
 * @param tree_2 The number of cherries left on the tree for player 2.
 * @param player_turn The current player's turn ("P1" or "p1" for player 1 and
 * "P2" or "p2" for player 2).
 * @param name1 The name of player 1.
 * @param name2 The name of player 2.
 *
 * @throws None
    } **/
static inline void six(int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  std::cout << "\n[2 cherries have been removed from the bucket, and returned to the tree]\n";
  if (player_turn == "P1" || player_turn == "p1") {
    if (player_basket_1 == 0) {
      player_basket_1 = 0;
      tree_1 = 10;
    }
    else if (player_basket_1 == 1) {
      player_basket_1 = 1;
      tree_1 = 9;
    }
    else {
      tree_1 += 2;
      player_basket_1 -= 2;
    }
    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
  else if (player_turn != "P1" || player_turn != "p1") {
    if (player_basket_2 == 0) {
      player_basket_2 = 0;
      tree_2 = 10;
    }
    else if (player_basket_2 == 1) {
      player_basket_2 = 1;
      tree_2 = 9;
    }
    else {
      tree_2 += 2;
      player_basket_2 -= 2;
    }
    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
}

/** {
 * Resets the state of the game by returning all cherries to their respective trees.
 *
 * @param player_basket_1 integer reference to player 1's basket
 * @param player_basket_2 integer reference to player 2's basket
 * @param tree_1 integer reference to tree 1
 * @param tree_2 integer reference to tree 2
 * @param player_turn string reference to the current player's turn
 * @param name1 constant string reference to player 1's name
 * @param name2 constant string reference to player 2's name
 *
 * @throws None
    } **/
static inline void seven(int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  std::cout << "\n[All cherries have been returned to the tree]\n";
  if (player_turn == "P1" || player_turn == "p1") {
    player_basket_1 = 0;
    tree_1 = 10;

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
  else {
    player_basket_2 = 0;
    tree_2 = 10;

    show_status(player_turn, name1, name2, player_basket_1, player_basket_2, tree_1, tree_2);
  }
}

/** {
 * Checks if a player has won based on the number of baskets they scored.
 *
 * @param player_basket_1 the number of baskets scored by the first player
 * @param player_basket_2 the number of baskets scored by the second player
 * @param name1 the name of the first player
 * @param name2 the name of the second player
 *
 * @return true if either player has 10 baskets, false otherwise
 *
 * @throws None
    } **/
static inline bool check_win(int& player_basket_1, int& player_basket_2, std::string const name1, std::string const name2) {
  if (player_basket_1 == 10) {
    std::cout << "\n[" << name1 << " won]\n";
    return true;
  }
  else if (player_basket_2 == 10) {
    std::cout << "\n[" << name2 << " won]\n";
    return true;
  }
  return false;
}

/** {
 * Returns the user's choice whether to play again or not after finishing a game of Hi-Ho-Cherry-O.
 * @return char the user's choice (either 'Y' or 'N')
 * @throws std::logic_error if user input is not 'Y' or 'N'
    } **/
static inline char get_choice() {
  char choice;
  try {
    std::cout << "\n[you finished a game of Hi-Ho-Cherry-O\n"
      << "Do you want to play again? (Y/N)]:  ";
    std::cin >> choice;
    if (choice != 'Y' && choice != 'N') {
      throw std::logic_error("[invalid input]");
    }
  }
  catch (std::exception& e) {
    std::cerr << "[error: " << e.what() << "]\n";
  }
  return choice;
}

/** {
 * Prints a goodbye message to the console.
 * @param None
 * @return None
 * @throws None
    } **/
static inline void goodbye() {
  std::cout << "\n[goodbye]\n\n";
  std::cout << std::flush;
}

/** {
 * Returns the opposite player turn given the current player turn.
 * @param player_turn The current player turn.
 * @return The opposite player turn.
 * @throws None
    } **/
static inline std::string switch_turn(std::string& player_turn) {
  if (player_turn == "p1" || player_turn == "P1") {
    return "p2";
  }
  else {
    return "p1";
  }
}

/** {
 * Runs a game spin and updates player baskets and trees accordingly.
 *
 * @param spin an integer reference representing the spin
 * @param player_basket_1 an integer reference representing the first player's basket
 * @param player_basket_2 an integer reference representing the second player's basket
 * @param tree_1 an integer reference representing the first tree
 * @param tree_2 an integer reference representing the second tree
 * @param player_turn a string reference representing the current player's turn
 * @param name1 a constant string representing the first player's name
 * @param name2 a constant string representing the second player's name
 *
 * @throws none
    } **/
static inline void run(int& spin, int& player_basket_1, int& player_basket_2, int& tree_1, int& tree_2, std::string& player_turn, std::string const name1, std::string const name2) {
  switch (spin) {
  case SPIN::ONE: {
    add_cherry(player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
    break;
  }

  case SPIN::TWO: {
    two(player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
    break;
  }

  case SPIN::THREE: {
    three(player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
    break;
  }
  case SPIN::FOUR: {
    four(player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
    break;
  }

  case SPIN::FIVE: {
    five(player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
    break;
  }
  case SPIN::SIX: {
    six(player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
    break;
  }
  case SPIN::SEVEN: {
    seven(player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
    break;
  }
  default: {
    break;
  }
  }
}

/** {
 * Main function that runs the game.
 * @param argc number of command-line arguments
 * @param argv array of command-line arguments
 * @return integer representing exit status of the program
 * @throws None
    } **/
int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  show_last_compiled();
  srand(time(NULL));

  int tree_1 = 10;
  int tree_2 = 10;
  int player_basket_1 = 0;
  int player_basket_2 = 0;
  int spin = 0;

  char choice;

  std::string player_turn;
  std::tuple<std::string, std::string> name_pair = welcome();

  std::string const name1 = std::get<0>(name_pair);
  std::string const name2 = std::get<1>(name_pair);

  do {
    player_turn = goes_first(player_turn);
    while (!check_win(player_basket_1, player_basket_2, name1, name2)) {
      if (player_turn == "P1" || player_turn == "p1") {
        spin = sum(name1);
        std::cout << std::endl;
      }
      else {
        spin = sum(name2);
        std::cout << std::endl;
      }

      run(spin, player_basket_1, player_basket_2, tree_1, tree_2, player_turn, name1, name2);
      player_turn = switch_turn(player_turn);
    }
    choice = get_choice();
  } while (choice == YES);
  if (choice != YES) {
    goodbye();
  }
  return EXIT_SUCCESS;
}
