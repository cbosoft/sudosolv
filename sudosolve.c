#include <stdio.h>

int board[9][9] = {
  {0,0,0, 0,0,0, 0,0,0},
  {0,0,0, 0,0,0, 0,0,0},
  {0,0,0, 0,0,0, 0,0,0},

  {0,0,0, 0,0,0, 0,0,0},
  {0,0,0, 0,0,0, 0,0,0},
  {0,0,0, 0,0,0, 0,0,0},

  {0,0,0, 0,0,0, 0,0,0},
  {0,0,0, 0,0,0, 0,0,0},
  {0,0,0, 0,0,0, 0,0,0}
};

void
print_board(int board[9][9]) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      fprintf(stderr, " %d ", board[row][col]);
      if (col == 2 || col == 5)
        fprintf(stderr, "│");
    }
    if (row == 2 || row == 5)
      fprintf(stderr, "\n─────────┼─────────┼────────\n");
    else
      fprintf(stderr, "\n");

  }
}

int
main(int argc, char **argv) {

  print_board(board);

  return 0;
}
