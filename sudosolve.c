#include <stdio.h>
#include <stdlib.h>


enum DIFFICULTY {
  HARD,
  MEDIUM,
  EASY
};





void
print_board(int board[9][9]) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col])
        fprintf(stderr, " %d ", board[row][col]);
      else
        fprintf(stderr, "   ");
      if (col == 2 || col == 5)
        fprintf(stderr, "\033[34m│\033[0m");
    }
    if (row == 2 || row == 5)
      fprintf(stderr, "\n\033[34m─────────┼─────────┼────────\033[0m\n");
    else
      fprintf(stderr, "\n");

  }
  fprintf(stderr, "\n");
  
  int counts[10] = {0};
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      counts[board[row][col]] += 1;
    }
  }

  for (int i = 0; i < 9; i++){ 
    fprintf(stderr, " \033[34;1m%d\033[0m ", i+1);
  }
  fprintf(stderr, "\n");
  for (int i = 1; i < 10; i++){
    fprintf(stderr, " %d ", counts[i]);
  }
}








void
get_lines(int board[9][9], int r, int c, int lines[27]) {

  // horizontal line
  for (int i = 0; i < 9; i++) {
    lines[i] = board[r][i];
  }

  // vertical line
  for (int i = 0; i < 9; i++) {
    lines[9+i] = board[i][c];
  }

  // box
  int box_l = (c / 3)*3, box_t = (r / 3)*3; // floor to 3
  for (int ri = box_t; ri < (3+box_t); ri++) {
    for (int ci = box_l; ci < (3+box_l); ci++) {
      int i = ((ri - box_t)*3) + (ci - box_l) + 18;
      lines[i] = board[ri][ci];
    }
  }
}




int
is_in(int arr[27], int v) {
  for (int i = 0; i < 27; i++) {
    if (arr[i] == v)
      return 1;
  }
  return 0;
}





int
any_left(int board[9][9], int v) {
  int count = 0;
  for (int ro = 0; ro < 9; ro++) {
    for (int co = 0; co < 9; co++) {
      if (board[ro][co] == v)
        count ++;
      if (count >= 9)
        return 0;
    }
  }

  return 1;
}





void
reset(int board[9][9]) {
  for (int ro = 0; ro < 9; ro++) {
    for (int co = 0; co < 9; co++)
      board[ro][co] = 0;
  }
}



void
solve(int board[9][9]) {
  int solved[9][9];

  // find a blank point, get val for that point (or give up, don't guess).
  // TODO
}




void
gen_board(int board[9][9], int difficulty) {
  int n = (difficulty+1)*20, i, r, c, v;
  
  for (i = 0; i < n; i++) {

    do { // generate random coord
      r = (rand() % 9);
      c = (rand() % 9);
    } while (board[r][c] != 0);
    
    // get suitable value for coord
    int values_at_point[27];
    get_lines(board, r, c, values_at_point);
    int j = 0;
    do {
      v = (rand() % 9) + 1;
      j++;
      if (j > 81) {
        fprintf(stderr, " could not generate board, stuck at r%dc%d\n", r, c);
        print_board(board);
        fprintf(stderr, " giving up on this board\n");
        reset(board);
        get_lines(board, r, c, values_at_point);
        i = 0;
      }
    } while (is_in(values_at_point, v) || !any_left(board, v));

    board[r][c] = v;
  }
}





void
print_arr(int *arr, int start, int end) {
  for (int i = start; i < end; i++)
    fprintf(stderr, "%d, ", arr[i]);
  fprintf(stderr, "\n");
}






int
main(int argc, char **argv) {
  int board[9][9] = {0};
  gen_board(board, MEDIUM);
  print_board(board);
  return 0;
}
