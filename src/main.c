#include <stdbool.h>

#include "application.h"

struct global {
	int tile_size;
	bool turn;
	int map[9];
	int playerX;
	int playerO;
	int tie;
	int w_Width;
	int w_Height;
} state;

int tile_size = 200;
bool turn = true;
int map[9];
int playerX = 0;
int playerO = 0;
int tie = 0;

int main () {
	Log();
	App();
	return 0;
}
