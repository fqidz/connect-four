#include <ios>
#include <iostream>
#include <limits>
#include <vector>
std::vector<std::vector<char>> board = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' '},
};
char piece = 'X';
bool game_over = false;

void insert_piece(std::vector<std::vector<char>> &board, int location,
                  char input) {
  int x{};
  while (x < board.size() - 1 && board[x + 1][location] == ' ') {
    x++;
  }
  board[x][location] = input;
}

void toggle_player(char &piece) {
  if (piece == 'X') {
    piece = 'O';
  } else {
    piece = 'X';
  }
}

void check_win(std::vector<std::vector<char>> &board, char piece) {
  // check vertical
  for (int i{}; i < 3; i++) {
    for (int j{}; j < board[0].size(); j++) {
      if (board[i][j] == piece && board[i + 1][j] == piece &&
          board[i + 2][j] == piece && board[i + 3][j] == piece) {
        game_over = true;
      }
    }
  }
  // check horizontal
  for (int i{}; i < board.size(); i++) {
    for (int j{}; j < 4; j++) {
      if (board[i][j] == piece && board[i][j + 1] == piece &&
          board[i][j + 2] == piece && board[i][j + 3] == piece) {
        game_over = true;
      }
    }
  }
  // check anti-diagonal
  for (int i{}; i < 3; i++) {
    for (int j{}; j < 4; j++) {
      if (board[i][j] == piece && board[i + 1][j + 1] == piece &&
          board[i + 2][j + 2] == piece && board[i + 3][j + 3] == piece) {
        game_over = true;
      }
    }
  }
  // check diagonal
  for (int i{3}; i < 6; i++) {
    for (int j{}; j < 4; j++) {
      if (board[i][j] == piece && board[i - 1][j + 1] == piece &&
          board[i - 2][j + 2] == piece && board[i - 3][j + 3] == piece) {
        game_over = true;
      }
    }
  }
}

int main() {
  while (!game_over) {
    ;
    int location{0};

    while ((std::cout << piece << " moves\n") && (std::cout << "Column: ") &&
           !(std::cin >> location)) {
      std::cout << "Not a number. Move again.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    location -= 1;

    if (location >= 0 && location < 7) {
      insert_piece(board, location, piece);

      for (int i{}; i < board.size(); i++) {
        std::cout << "| " << board[i][0] << " | " << board[i][1] << " | "
                  << board[i][2] << " | " << board[i][3] << " | " << board[i][4]
                  << " | " << board[i][5] << " | " << board[i][6] << " |\n";
      }
      std::cout << "-----------------------------\n";
      std::cout << "  1   2   3   4   5   6   7\n";
      check_win(board, piece);
      toggle_player(piece);
    } else {
      std::cout << "Out of bounds. Move again.\n";
    }
  }

  toggle_player(piece);
  std::cout << piece << " wins!";

  return 0;
}
