#include <SDL2/SDL.h>

extern SDL_Surface* wSurface;
extern SDL_Surface* xBmp;
extern SDL_Surface* oBmp;

extern int map[];
extern int tile_size;
extern int playerX, playerO, tie;
extern SDL_Rect t1, t2, t3, t4, t5, t6, t7, t8, t9;

void cleanBoard() {
//	printf("Log: Clear Board!\n");
	SDL_Rect tiles[] = {t1, t2, t3, t4, t5, t6, t7, t8, t9};
	for (int i = 0; i < 9; i++) {
		SDL_FillRect(wSurface, &tiles[i], SDL_MapRGB(wSurface->format, 0x69, 0x69, 0x69));
		map[i] = 0;
	}
}

void spillBrett() {

	int offset_x = 0;
	int offset_y = 0;
	int size = tile_size;
	int set1 =  50;
	int set2 = 300;
	int set3 = 550;

	t1.x = set1 + offset_x, t1.y = set1 + offset_y, t1.w = size, t1.h = size;
	t2.x = set2 + offset_x, t2.y = set1 + offset_y, t2.w = size, t2.h = size;
	t3.x = set3 + offset_x, t3.y = set1 + offset_y, t3.w = size, t3.h = size;
	t4.x = set1 + offset_x, t4.y = set2 + offset_y, t4.w = size, t4.h = size;
	t5.x = set2 + offset_x, t5.y = set2 + offset_y, t5.w = size, t5.h = size;
	t6.x = set3 + offset_x, t6.y = set2 + offset_y, t6.w = size, t6.h = size;
	t7.x = set1 + offset_x, t7.y = set3 + offset_y, t7.w = size, t7.h = size;
	t8.x = set2 + offset_x, t8.y = set3 + offset_y, t8.w = size, t8.h = size;
	t9.x = set3 + offset_x, t9.y = set3 + offset_y, t9.w = size, t9.h = size;

}

void playerXVic() {
	printf("Log: Spiller X har vunnet!\n");
	playerX++;
	SDL_Delay(2000);
	cleanBoard();
}
void playerOVic() {
	printf("Log: Spiller O har vunnet!\n");
	playerO++;
	SDL_Delay(2000);
	cleanBoard();
}
void playerTie() {
	printf("Log: It's a Tie!\n");
	tie++;
	SDL_Delay(2000);
	cleanBoard();
}

void checkBrett() {
	int matrix[8][9] = {
		{1,0,0, 1,0,0, 1,0,0},
		{0,1,0, 0,1,0, 0,1,0},
		{0,0,1, 0,0,1, 0,0,1},
		{1,1,1, 0,0,0, 0,0,0},
		{0,0,0, 1,1,1, 0,0,0},
		{0,0,0, 0,0,0, 1,1,1},
		{1,0,0, 0,1,0, 0,0,1},
		{0,0,1, 0,1,0, 1,0,0}
	};
	for (int j = 0; j < 8; j++) {
		int checkX = 0, checkO = 0;
		for (int i = 0; i < 9; i++) {
			if (matrix[j][i] == 1) {

					// Check for Player X
				if (map[i] == 1) {
					checkX++;
					if (checkX == 3) {
						playerXVic();
						checkX = 0;
						break;
					}

					// Check for Player O
				} else if (map[i] == 2) {
					checkO++;
					if (checkO == 3) {
						playerOVic();
						checkO = 0;
						break;
					}
				} 
			}
		}
	}
	int checkT = 0;
	for (int i = 0; i < 9; i++) {
		if (map[i] != 0) {
			checkT++;
			if (checkT == 9) {
				playerTie();
				checkT = 0;
				break;
			}
		}
	}
}

