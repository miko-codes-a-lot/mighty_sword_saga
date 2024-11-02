void reset_board (int board[3][3])
{
  int checked = 0;
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      board[row][col] = 0;
    }
  }
}

int check_board_draw (int board[3][3])
{
  int checked = 0;
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] != 0) {
        checked++;
      }
    }
  }

  return checked == 9;
}

int check_board_horizontal (int board[3][3])
{
  int game_over = 0;
  for (int row = 0; row < 3 && !game_over; row++) {
    int player_one_points = 0;
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == 1) {
        player_one_points++;
      } else if (board[row][col] == 2) {
        player_one_points--;
      }

      if (player_one_points >= 3) {
        printf("Player 1 wins!\n");
        game_over = 1;
        return 1;
      } else if (player_one_points <= -3) {
        printf("Player 2 wins!\n");
        game_over = 1;
        return 2;
      }
    }
    printf("points %d: %d\n", row, player_one_points);
  }

  return 0;
}

int check_board_vertical (int board[3][3])
{
  int game_over = 0;
  for (int col = 0; col < 3 && !game_over; col++) {
    int player_one_points = 0;
    for (int row = 0; row < 3; row++) {
      // printf("%d ", col);
      // printf("%d, ", board[row][col]);
      if (board[row][col] == 1) {
        player_one_points++;
      } else if (board[row][col] == 2) {
        player_one_points--;
      }

      if (player_one_points >= 3) {
        printf("Player 1 wins!\n");
        game_over = 1;
        return 1;
      } else if (player_one_points <= -3) {
        printf("Player 2 wins!\n");
        game_over = 1;
        return 0;
      }
    }
  }
  return 0;
}

int check_broad_cross (int board[3][3])
{
  int player_x_one_points = 0;
  int player_x_r_one_points = 0;
  int ix = 2;
  for (int i = 0; i < 3; i++) {
    if (board[i][i] == 1) {
      player_x_one_points++;
    } else if (board[i][i] == 2) {
      player_x_one_points--;
    }

    printf("%d, ", ix);
    if (board[i][ix] == 1) {
      player_x_r_one_points++;
    } else if (board[i][ix] == 2) {
      player_x_r_one_points--;
    }

    ix--;

    if (player_x_one_points >= 3 || player_x_r_one_points >= 3) {
      printf("Player 1 wins!\n");
      return 1;
    } else if (player_x_one_points <= -3 || player_x_r_one_points <= -3) {
      printf("Player 2 wins!\n");
      return 2;
    }
  }

  return 0;
}