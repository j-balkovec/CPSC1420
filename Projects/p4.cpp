// {
// Jakob Balkovec Memory Game
// Last Modified: 2022-10-01
// p4.cpp
// }

#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <thread>
#include <random>

static const char YES = 'Y';
static const int COL = 3;
static const int ROW = 4;
static const std::string SPACE = "   ";
static const int SIZE = 12;
static const int FILE_NUM = 1;
static const int COL_WIDTH = 4;

enum WAIT {
  BEG = 5,
  PRO = 2
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
 * @brief Suspends the execution of the calling thread for a given number of seconds.
 * @param SECONDS The number of seconds to wait.
 * @return None.
 * @throws None.
    }**/
static inline void wait(const int SECONDS) {
  std::this_thread::sleep_for(std::chrono::seconds(SECONDS));
}

/** {
 * @brief Prints the welcome message and the rules of the memory game.
 * @param None
 * @return None
 * @throws None
    } **/
static inline void welcome() {
  std::cout << "\n\nWELCOME TO THE MEMORY GAME!\n\n"
    << "------------------------------------ RULES ------------------------------------\n\n"
    << "-> Players start with 0 cards, the one with the most cards in the end wins.\n"
    << "-> A player must always pick 2 cards\n"
    << "-> If a player gets 6 pairs, they win the game\n"
    << "-> A player cannot pick the same card that was already picked\n"
    << "-> If a player does not draw a pair, both of the cards are returned to the board\n\n"
    << "Press [Enter] to continue...";
  std::cin.get();
}

/** {
 * @brief Prints a goodbye message to the console.
 * @return void
 * @throws None
    }**/
static inline void goodbye() {
  std::cout << "\n[Goodbye, Thanks for playing!]\n\n";
}

/** {
 * @brief Generates a random file number between 1 and FILE_NUM, inclusive.
 * @return an integer representing the randomly generated file number
 * @throws none
    }**/
static inline int random_file() {
  static const int FILE_NUM = 1;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(FILE_NUM, FILE_NUM + 1);
  return dist(gen);
}

/** {
 * @brief Read a file containing characters and places them into the given 2D array.
 * @param board a 2D character array to store the characters read from the file
 * @throws std::runtime_error if the file cannot be opened
    }**/
static inline void read_file(char board[][COL]) {
  const std::string FILE_1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
  const std::string FILE_2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";

  std::string filename;
  std::ifstream input_file;
  try {
    if (random_file() == 1) {
      filename = FILE_1;
    }
    else {
      filename = FILE_2;
    }

    input_file.open(filename);
    if (!input_file.good()) {
      throw std::runtime_error("cannot open: [" + filename + "]\n");
    }

    for (auto row = 0; row < ROW; ++row) {
      for (auto col = 0; col < COL && col < SIZE; ++col) {
        input_file >> board[row][col];
      }
    }

    input_file.close();
  }
  catch (const std::exception& e) {
    std::cerr << "\n[error]: " << e.what() << std::endl;
    std::exit(1);
  }
  std::cout << std::endl << std::endl;
}

/** {
 * @brief Clears the terminal screen.
 * @return void
 * @throws None
    }**/
static inline void clear_screen() {
  printf("\033[2J\033[1;1H");
}

/** {
 * @brief Display the game board on the console, with cell values and indices.
 * @param board the game board to display
 * @param c1_row the row index of the first character
 * @param c1_col the column index of the first character
 * @param c2_row the row index of the second character
 * @param c2_col the column index of the second character
 *
 * @throws None
    } **/
static inline void display(char board[][COL], int c1_row, int c1_col, int c2_row, int c2_col)
{
  std::cout << "\n";
  std::cout << SPACE;
  for (int l = 0; l < COL; l++) {
    std::cout << std::setw(COL_WIDTH + 2) << l;
  }
  std::cout << "\n";
  for (int i = 0; i < ROW; i++) {
    std::cout << "\n";
    std::cout << std::setw(COL_WIDTH) << i << std::setw(COL_WIDTH);
    for (int k = 0; k < COL; k++) {
      if (i == c1_col && k == c1_row) {
        std::cout << std::setw(COL_WIDTH) << "[" << board[i][k] << "]";
      }
      else if (i == c2_col && k == c2_row) {
        std::cout << std::setw(COL_WIDTH) << "[" << board[i][k] << "]";
      }
      else if (board[i][k] == '_') {
        std::cout << std::setw(COL_WIDTH) << "[" << "_" << "]";
      }
      else {
        std::cout << std::setw(COL_WIDTH) << "[" << "*" << "]";

      }
    }
    std::cout << "\n";
  }
}

/** {
 * @brief Gets the row and column of the first card from the user and validates the input.
 * @param board The board of the game
 * @param c1_row The row of the card picked by the user
 * @param c1_col The column of the card picked by the user
 *
 * @throws std::runtime_error If the input is invalid
    }**/
static inline void get_first(char board[][COL], int& c1_row, int& c1_col) {
  int max_row = ROW - 1;
  int max_col = COL - 1;

  while (true) {
    try {
      std::cout << "\n[Pick the first card]:\n\n";
      std::cout << "[ROW (0-" << max_row << ")]: ";
      std::cin >> c1_row;
      if (std::cin.fail()) {
        throw std::runtime_error("[Invalid input]");
      }

      std::cout << "[COL (0-" << max_col << ")]: ";
      std::cin >> c1_col;
      if (std::cin.fail()) {
        throw std::runtime_error("[Invalid input]");
      }

      if (c1_row >= 0 && c1_row <= max_row && c1_col >= 0 && c1_col <= max_col) {
        if (board[c1_row][c1_col] != '_') {
          break;
        }
        else {
          std::cout << "This card has already been picked or turned over!\n";
        }
      }
      else {
        throw std::runtime_error("[Invalid input]");
      }
    }
    catch (const std::exception& e) {
      std::cout << "[Error]: " << e.what() << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/** {
 * Gets the second card from the player and validates the input.
 *
 * @param board 2D array of char representing the game board.
 * @param c1_row the row of the first card picked.
 * @param c1_col the column of the first card picked.
 * @param c2_row reference to an integer that will be set to the row of the second card picked.
 * @param c2_col reference to an integer that will be set to the column of the second card picked.
 *
 * @throws std::runtime_error if the input is invalid.
    }**/
static inline void get_second(char board[][COL], int& c1_row, int& c1_col, int& c2_row, int& c2_col) {
  int max_row = ROW - 1;
  int max_col = COL - 1;

  while (true) {
    try {
      std::cout << "\n[Pick the first card]:\n\n";
      std::cout << "[ROW (0-" << max_row << ")]: ";
      std::cin >> c2_row;
      if (std::cin.fail()) {
        throw std::runtime_error("[Invalid input!]");
      }

      std::cout << "[COL (0-" << max_col << ")]: ";
      std::cin >> c2_col;
      if (std::cin.fail()) {
        throw std::runtime_error("[Invalid input!]");
      }

      if ((board[c2_row][c2_col] != '_') && ((c1_row != c2_row) || (c1_col != c2_col))) {
        break;
      }
      else {
        std::cout << "This card has already been picked or turned over, or it is the same as the first card!\n";
      }
    }
    catch (const std::exception& e) {
      std::cout << "[Error]: " << e.what() << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}

/** {
 * @brief Checks if the given game board is empty.
 * @param board the 2D char array representing the game board
 * @return true if the board is empty, false otherwise
    }**/
static inline bool is_board_empty(char board[][COL]) {
  for (int col = 0; col < COL; col++) {
    for (int row = 0; row < ROW; row++) {
      if (board[col][row] != '_') {
        return false;
      }
    }
  }
  return true;
}

/** {
 * @brief Returns a char representing the selected level of expertise.
 * @return char representing selected level: 'B' for beginner or 'I' for expert.
 * @throws None
    }**/
static inline char get_level() {
  char lev;
  std::cout << "Select [B] for beginner or [I] for expert: ";
  std::cin >> lev;
  return lev;
}

/** {
 * @brief Checks if two positions on the board match and updates the board accordingly.
 * @param board the board to check
 * @param c1_col the column index of the first position
 * @param c1_row the row index of the first position
 * @param c2_col the column index of the second position
 * @param c2_row the row index of the second position
 * @throws None
    }**/
static inline void is_match(char board[][COL], int& c1_col, int& c1_row, int& c2_col, int& c2_row) {
  if (board[c1_col][c1_row] == board[c2_col][c2_row]) {
    std::cout << "\n\nIt's a match!\n";
    board[c1_col][c1_row] = '_';
    board[c2_col][c2_row] = '_';
    std::cout << "Press [Enter] to continue...";
    std::cin.get();
    std::cout << "\n";
  }
  else {
    std::cout << "\nUnfortunately wasn't a match, try again!\n";
    std::cout << "Press enter to continue...\n";
    std::cin.get();
  }
}

/** {
 * @brief Returns the user's choice (Y/N) to play again after winning the game.
 * @return char Y or N based on user's choice
 * @throws None
    } **/
static inline char get_choice() {
  char choice = '\0';
  std::cout << "\n\nYou cleared the board and won!\n";
  std::cout << "Congratulations!\n\n\n";
  std::cout << "Do you want to play again? (Y/N): ";
  std::cin >> choice;
  std::cout << "\n\n";
  return choice;
}

int main([[maybe_unused]] int argv, [[maybe_unused]] char* argc[]) {
  show_last_compiled();
  int c1_row = 0;
  int c1_col = 0;
  int c2_row = 0;
  int c2_col = 0;
  char choice = '\0';
  char level = '\0';

  char board[ROW][COL];

  char const BEGINNER = 'B';

  welcome();
  do {
    level = get_level();
    read_file(board);
    display(board, c1_row, c1_col, c2_row, c2_col);
    while (!is_board_empty(board)) {
      get_first(board, c1_row, c1_col);
      display(board, c1_row, c1_col, c2_row, c2_col);
      get_second(board, c1_row, c1_col, c2_row, c2_col);
      display(board, c1_row, c1_col, c2_row, c2_col);
      if (level == BEGINNER)
        wait(WAIT::BEG);
      else
        wait(WAIT::PRO);
      clear_screen();
      is_match(board, c1_row, c1_col, c2_row, c2_col);
      display(board, c1_row, c1_col, c2_row, c2_col);
    }
    choice = get_choice();
  } while (choice == YES);

  if (choice != YES) {
    goodbye();
  }
  std::cout << "\n\n" << std::flush;
  return EXIT_SUCCESS;
}
