#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 9; // constant global variable
const int MAX_MOVES = 10; // the max number of moves
const int TOTAL_CHARS = 6; // total number of enum values

enum BOARD{EXCLAMATION = '!', QUOTES, HASH, DOLLAR, PERCENT, AMPERSAND};

struct player
{
	char row_pos; // row position
	int col_pos; // column position
	char dir; // direction
	int moves; // move counter
	int score; // score
};

// function declarations
void Header();
void Description();
void Initialize(BOARD **board);
void Update(player input, BOARD **board);
void Check_Coordinate(BOARD **board, player &input);

