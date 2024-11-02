#include "raylib.h"
#include <stdio.h>
#include "check_board.h"

#include "resource_dir.h"

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(500, 500, "Tic Tac Toe");
	SearchAndSetResourceDir("resources");

	SetTargetFPS(60);

	// Game State
	int board[3][3] = { 0 };
	int is_player_turn_one = 1;
  int player_winner = 0;
  int game_over = 0;
  
  char *message;
  Color color;

	while (!WindowShouldClose())
	{
    if (!game_over) {
      if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        int row = mousePosition.y;
        int col = mousePosition.x;

        if (col >= 100 && col <= 400 && row >= 100 && row <= 400) {
          int rowIndex = 2;
          int colIndex = 2;

          if (row < 200) {
            rowIndex = 0;
          } else if (row < 300) {
            rowIndex = 1;
          };

          if (col < 200) {
            colIndex = 0;
          } else if (col < 300) {
            colIndex = 1;
          };

          if (board[rowIndex][colIndex] == 0) {
            board[rowIndex][colIndex] = (is_player_turn_one) ? 1 : 2;

            is_player_turn_one = !is_player_turn_one;
          }
        }
      }

      int winner =  check_board_horizontal(board) ||
                    check_board_vertical(board) ||
                    check_broad_cross(board);

      if (winner) {
        game_over = 1;
        player_winner = winner;
      } else {
        int is_draw = check_board_draw(board);
        if (is_draw) {
          game_over = 1;
          player_winner = 0;
        }
      }
    } else {
      if (IsKeyPressed(KEY_SPACE)) {
        reset_board(board);
        player_winner = 0;
        game_over = 0;
        is_player_turn_one = 1;
      }

      if (player_winner != 0) {
        message = (player_winner == 1) ? "Player 1 wins!" : "Player 2 wins!";
        color = (player_winner == 1) ? RED : GREEN;
      } else {
        message = "Draw game!";
        color = WHITE;
      }
    }

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Tic Tac Toe", 10, 10, 20, WHITE);

    // Game Header
      DrawText(message, 180, 50, 20, color);

		// draw the board
		for (int i = 1; i <= 4; i++) {
			DrawLine(100, 100 * i, 400, 100 * i, WHITE); // horizontal
			DrawLine(100 * i, 100, 100 * i, 400, WHITE); // vertical
		}

		for (int row = 0; row < 3; row++) {
			for (int col = 0; col < 3; col++) {
				if (board[row][col] != 0) {
					Color color = (board[row][col] == 1) ? RED : GREEN;
					DrawCircle(((col + 1) * 100) + 50, ((row + 1) * 100) + 50, 30, color);
				}
			}
		}
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}