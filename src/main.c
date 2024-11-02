#include "raylib.h"
#include <stdio.h>

#include "resource_dir.h"

int main ()
{
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	InitWindow(500, 500, "Tic Tac Toe");
	SearchAndSetResourceDir("resources");

	SetTargetFPS(60);

	// Game State
	int grid[3][3] = { 0 };

	bool isPlayerOne = true;

	while (!WindowShouldClose())
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
			Vector2 mousePosition = GetMousePosition();
			int row = mousePosition.y;
			int col = mousePosition.x;

			// if (col < 100 || col > 400) {
			// 	printf("Col out of bound\n");
			// 	fflush(stdout);
			// }

			// if (row < 100 | row > 400) {
			// 	printf("Row out of bound \n");
			// 	fflush(stdout);
			// }

			if (col >= 100 && col <= 400 && row >= 100 && row <= 400) {
				isPlayerOne = !isPlayerOne;

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

				printf("rowIndex: %d, colIndex: %d\n", rowIndex, colIndex);
				fflush(stdout);
			}

			// printf("row: %d, col: %d\n", row, col);
			// fflush(stdout);
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Tic Tac Toe", 10, 10, 20, WHITE);

		DrawText(
			(isPlayerOne) ? "Player 1" : "Player 2",
			200,
			50,
			20,
			(isPlayerOne) ? RED : GREEN
		);

		// draw the grid
		for (int i = 1; i <= 4; i++) {
			DrawLine(100, 100 * i, 400, 100 * i, WHITE); // horizontal
			DrawLine(100 * i, 100, 100 * i, 400, WHITE); // vertical
		}
		
		EndDrawing();
	}

	CloseWindow();
	return 0;
}