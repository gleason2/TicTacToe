#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char grid[3][3];

void init_grid() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid[i][j] = ' ';
    }
  }
}

void print_grid() {
  printf("  --a---b---c--\n");
  for (int i = 0; i < 3; i++) {
    printf("%d | %c | %c | %c |\n", i, grid[i][0], grid[i][1], grid[i][2]);
    printf("  -------------\n");
  }
}

bool check_grid() {
  for (int i = 0; i < 3; i++) {
    if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ') {
      printf("%c wins!\n", grid[i][0]);
      return true;
    }
    if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ') {
      printf("%c wins!\n", grid[0][i]);
      return true;
    }
  }
  if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ') {
    printf("%c wins!\n", grid[0][0]);
    return true;
  }
  if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ') {
    printf("%c wins!\n", grid[0][2]);
    return true;
  }
  bool draw = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[i][j] == ' ') {
        draw = false;
        break;
      }
    }
  }
  if (draw) {
    printf("It's a draw!\n");
    return true;
  }
  return false;
}

int main() {
  while (true) {
    bool gameover = false;
    char player = 'X';
    init_grid();
    printf("Type the coordinate you want to take, like 0a\n");
    while (!gameover) {
      print_grid();
      printf("%c's turn!\n", player);
      char coord[3];
      fgets(coord, 3, stdin);
      getchar();
      while (grid[coord[0] - '0'][coord[1] - 'a'] != ' ') {
        printf("That coordinate is taken! Try again!\n");
        fgets(coord, 3, stdin);
        getchar();
      }
      grid[coord[0] - '0'][coord[1] - 'a'] = player;
      gameover = check_grid();
      if (gameover) {
        print_grid();
      }
      if (player == 'X') {
        player = 'O';
      } else {
        player = 'X';
      }
    }
    printf("Play again? [y/n]: ");
    char again = getchar();
    getchar();
    if (again != 'y') {
      break;
    }
  }
}
