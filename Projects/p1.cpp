//{
// @author: Jakob Balkovec
// @file: p3.cpp
// @brief: This program simulates a game of chutes and ladders.
//              The player 1 starts at 0 and the player 2 starts at 100.
//              The game ends when either player reaches a hundred.
// }

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cctype>

static const char YES = 'Y';
static const int MAX_SPIN = 6;
static const int MIN_SPIN = 1;
static const int END = 100;

enum Chute {
  CHUTE_1 = 98,
  CHUTE_2 = 95,
  CHUTE_3 = 93,
  CHUTE_4 = 87,
  CHUTE_5 = 64,
  CHUTE_6 = 62,
  CHUTE_7 = 56,
  CHUTE_8 = 49,
  CHUTE_9 = 48,
  CHUTE_10 = 16
};

enum Ladder {
  LADDER_1 = 1,
  LADDER_2 = 4,
  LADDER_3 = 9,
  LADDER_4 = 23,
  LADDER_5 = 28,
  LADDER_6 = 36,
  LADDER_7 = 51,
  LADDER_8 = 71,
  LADDER_9 = 80,
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
 * @brief Prints the instructions for the Chutes and Ladders game.
 * @param None
 * @return None
 * @throws None
    } **/
static inline void welcome() {
  std::cout << "\n\nWelcome to Chutes and Ladders!\n"
    << "-----------------------------------\n"
    << "Instructions:\n\n"
    << "- This is a two-player game.\n"
    << "- The players take turns rolling a six-sided die.\n"
    << "- Each player starts at square 1 and tries to reach square 100.\n"
    << "- To move forward, the player's current position is incremented by the number rolled.\n"
    << "- If a player lands at the base of a ladder, they will move up to the top of the ladder.\n"
    << "- If a player lands on the head of a chute, they will slide down to the bottom of the chute.\n"
    << "- The first player to reach or exceed square 100 wins the game!\n"
    << "-----------------------------------\n";
}

/** {
 * @brief Prints a goodbye message to the console.
 * @throws none
    }**/
static inline void goodbye() {
  std::cout << "\n\n[Goodbye]\n\n";
}

/** {
 * @brief Generates a random integer using a uniform distribution within the range
 * [MIN_SPIN, MAX_SPIN].
 * @return The randomly generated integer.
 * @throws None
    }**/
static inline int spin() {
  std::random_device rd;
  std::mt19937 rng(rd());
  std::uniform_int_distribution<int> dist(MIN_SPIN, MAX_SPIN);
  return dist(rng);
}

/** {
 * @brief Calculates the sum of dice thrown by spinning them.
 * @param dice an integer reference to the dice to be spun
 * @return the sum of dice after spinning
 * @throws None
    }**/
static inline int sum(int& dice) {
  std::cout << "Press [Enter] to spin...";
  std::cin.get();
  dice = spin();
  std::cout << "\nYou threw/spun " << dice << ".\n";
  return dice;
}

/** {
 * @brief orders the players and their names for a game
 * @param player_name_1 the name of player 1
 * @param player_name_2 the name of player 2
 * @return the name of the player who goes first
 * @throws std::invalid_argument if an invalid player name or selection is provided
    } **/
static inline std::string order_play(std::string& player_name_1, std::string& player_name_2) {
  std::string player_turn;
  std::cout << "[Please initiate which player is going first (P1/P2)]: ";
  std::cin >> player_turn;
  std::cout << "\n";

  try {
    if (player_turn != "P1" || player_turn != "p1" && player_turn != "P2" || player_turn != "p2") {
      throw std::invalid_argument("Invalid player selection!");
    }

    if (player_turn == "P1" || player_turn == "p1") {
      std::cout << "[Player 1 enter your name]: ";
      std::cin >> player_name_1;
      std::cout << "\n";
      if (!isalpha(player_name_1[0])) {
        throw std::invalid_argument("[Invalid player name! Names cannot start with a number]");
      }

      std::cout << "[Player 2 enter your name]: ";
      std::cin >> player_name_2;
      std::cout << "\n";
      if (!isalpha(player_name_2[0])) {
        throw std::invalid_argument("[Invalid player name! Names cannot start with a number]");
      }
    }
    else {
      std::cout << "[Player 2 enter your name]: ";
      std::cin >> player_name_2;
      std::cout << "\n";
      if (!isalpha(player_name_2[0])) {
        throw std::invalid_argument("[Invalid player name! Names cannot start with a number]");
      }

      std::cout << "[Player 1 enter your name]: ";
      std::cin >> player_name_1;
      std::cout << "\n";
      if (!isalpha(player_name_1[0])) {
        throw std::invalid_argument("[Invalid player name! Names cannot start with a number]");
      }
    }
  }
  catch (const std::invalid_argument& e) {
    std::cout << "[error]: " << e.what() << "\n";
    return order_play(player_name_1, player_name_2); //recursive call to try again
  }

  return player_turn;
}

/** {
 * @brief Checks if the given position is on a chute and updates it according to the
 * corresponding position. If the position is not on a chute, it does nothing.
 * @param new_pos the position to be checked and updated if necessary
 * @return void
 * @throws None
    }**/
static inline void check_chutes(int& new_pos) {
  switch (new_pos) {
  case CHUTE_1:
    new_pos = 78;
    break;
  case CHUTE_2:
    new_pos = 75;
    break;
  case CHUTE_3:
    new_pos = 73;
    break;
  case CHUTE_4:
    new_pos = 24;
    break;
  case CHUTE_5:
    new_pos = 60;
    break;
  case CHUTE_6:
    new_pos = 19;
    break;
  case CHUTE_7:
    new_pos = 53;
    break;
  case CHUTE_8:
    new_pos = 11;
    break;
  case CHUTE_9:
    new_pos = 26;
    break;
  case CHUTE_10:
    new_pos = 6;
    break;
  default:
    /** @brief do nothing*/
    break;
  }

  if (new_pos != new_pos) {
    std::cout << "[You landed on a chute and have to move down]" << std::endl;
  }
}

/** {
 * @brief Checks if the new position of a player is on a ladder and moves them accordingly.
 * @param new_pos the position of the player to check for ladder.
 * @return void
 * @throws None
    }**/
static inline void check_ladders(int& new_pos) {
  switch (new_pos) {
  case LADDER_1:
    new_pos = 38;
    break;
  case LADDER_2:
    new_pos = 14;
    break;
  case LADDER_3:
    new_pos = 21;
    break;
  case LADDER_4:
    new_pos = 44;
    break;
  case LADDER_5:
    new_pos = 84;
    break;
  case LADDER_6:
    new_pos = 44;
    break;
  case LADDER_7:
    new_pos = 66;
    break;
  case LADDER_8:
    new_pos = 90;
    break;
  case LADDER_9:
    new_pos = END;
    break;
  default:
    /** @brief do nothing*/
    break;
  }

  if (new_pos != new_pos) {
    std::cout << "[You landed on a ladder and get to move up]" << std::endl;
  }
}

/** {
 * Checks if both pos and pos_ are greater than or equal to END.
 * @param pos an integer reference representing a position
 * @param pos_ an integer reference representing a position
 * @return True if both pos and pos_ are greater than or equal to END, False otherwise.
    }**/
static inline bool done(int& pos, int& pos_) {
  if (pos < END && pos_ < END) {
    return false;
  }
  return true;
}

/** {
 * Checks if the given positions are equal to the END position.
 * @param pos A reference to an integer representing a position.
 * @param pos_ A reference to an integer representing a position.
 * @return True if both positions are equal to the END position.
    }**/
static inline void win(int& pos1, int& pos2, std::string const player_name_1, std::string const player_name_2) {
  if (pos1 == END) {
    std::cout << "\n" << player_name_1 << " reached a hundred and won!\n";
  }
  else if (pos2 == END) {
    std::cout << "\n" << player_name_2 << " reached a hundred and won!\n";
  }
}

/** {
 * @brief Checks if the player passed the end position on the board.
 * @param pos the current position of the player
 * @param dice the number rolled on the dice
 * @return true is passed, false if not
 * @throws None
    }**/
static inline bool passed(int& pos, int& dice) {
  if ((pos + dice) > END) {
    std::cout << "Unfortunately passed a 100...can't do that " << std::endl;
    std::cout << "You need to throw" << END - pos << std::endl;
    return true;
  }
  return false;
}

/** {
 * Returns a string value representing the current status of the game
 * for the given player. It updates the player_turn variable and waits for
 * user input before returning.
 * @param location an integer reference representing the player's current location
 * @param player_name a string representing the name of the player
 * @param player_turn a string reference representing the current turn of the player
 * @return a string representing the player's current turn
 * @throws None
    }**/
static inline std::string status(int& location, std::string const player_name, std::string& player_turn) {
  std::cout << player_name << ", your new location is: " << location << std::endl;
  player_turn = "p1";
  std::cout << std::endl << "Press enter to continue... ";
  std::cin.ignore();
  return player_turn;
}

/** {
 * @brief Sets the game's current turn and prints a message indicating whose turn it is.
 * @param turn a reference to a string containing the name of the player whose turn it is
 * @return void
 * @throws None
    }**/
static inline void turn_status(std::string& turn) {
  std::cout << "\n" << turn << "'s turn\n\n";
}

/** {
 * @brief Returns a character obtained from user input to determine if they want to
 * play the game again.
 * @return The character 'Y' or 'N' based on user input.
 * @throws None
    }**/
static inline char get_choice() {
  char choice;
  std::cout << "\n\nDo you want to play again? (Y/N) ";
  std::cin >> choice;
  return choice;
}

/** {
 * The main function for the Snakes and Ladders game. Controls the game
 * flow and player turns while calling helper functions to manage the
 * board state. Uses standard input/output to communicate with the
 * player in the console.
 *
 * @return int A status code indicating program success or failure.
 *
 * @throws None This function does not throw any exceptions.
    }**/
int main() {
  show_last_compiled();
  char ans = '\0';

  int dice = 0;
  int new_pos_1 = 0;
  int new_pos_2 = 0;

  std::string player_name_1 = "\0";
  std::string player_name_2 = "\0";

  welcome();

  do {
    std::string player_turn = order_play(player_name_1, player_name_2);
    while (!done(new_pos_1, new_pos_2)) {
      if (player_turn == "p1" || player_turn == "P1") {
        turn_status(player_name_1);
        sum(dice);
        if (passed(new_pos_1, dice)) {
          break;
        }
        else {
          new_pos_1 += dice;
          check_chutes(new_pos_1);
          check_ladders(new_pos_1);
        }
        player_turn = status(new_pos_1, player_name_1, player_turn);
      }
      else {
        turn_status(player_name_2);
        sum(dice);

        if (passed(new_pos_2, dice)) {
          break;
        }
        else {
          new_pos_2 += dice;
          check_chutes(new_pos_2);
          check_ladders(new_pos_2);
        }
        player_turn = status(new_pos_2, player_name_2, player_turn);
      }
    }
    win(new_pos_1, new_pos_2, player_name_1, player_name_2);
    ans = get_choice();
  } while (ans == YES);
  goodbye();
  return EXIT_SUCCESS;
}
