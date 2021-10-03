#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <exception>


using namespace std;

enum Cell : char { CROSS = 'x', ZERO = 'o', EMPTY = '-' };

enum GameStat : uint8_t { proceed, wonAI, wonPlayer, tieGG};

struct Coord { size_t y{ 0 }; size_t x{ 0 }; };

#pragma pack(push, 1)
struct Game
{
	Cell** ppField = nullptr;
	const size_t SIZE = 3;
	size_t turn = 0;
	Cell Player;
	Cell AI;
	GameStat progress = proceed;
};
#pragma pack (pop)

inline void clearScreen()
{
	system("cls");
}


int32_t getRandomN(int32_t min, int32_t max) //generator random numbers
{
	const static auto seed = chrono::system_clock::now().time_since_epoch().count();
	static mt19937_64 generator(seed);
	uniform_int_distribution<int32_t>dis(min, max);
	return dis(generator);
}


void __fastcall initGame(Game & g) //allocate memory
{
	g.ppField = new Cell* [g.SIZE]; 
	for (size_t i = 0; i < g.SIZE; i++)
	{
		g.ppField[i] = new Cell[g.SIZE]; //allocate memory for array (which contains pointers)
	}
												
	for (size_t y = 0; y < g.SIZE; y++) // fill out with empty  "---"		
	{
		for (size_t x = 0; x < g.SIZE; x++) //  _________x
		{									//	|
			g.ppField[y][x] = EMPTY;		//	|
		}									//	|
	}										// y|

	if (getRandomN(0, 1000) > 500)
	{
		g.Player = CROSS;
		g.AI = ZERO;
		g.turn = 0;
	}
	else
	{
		g.Player = CROSS;
		g.AI = ZERO;
		g.turn = 1;
	}

}



void __fastcall deinitGame(Game& g) //clean mempry
{
	for (size_t i = 0; i < g.SIZE; i++)
	{
		delete[] g.ppField[i];
	}
	delete[] g.ppField; //array which contains arrays
	g.ppField = nullptr;
}



void __fastcall printGameField(const Game & g)
{
	cout << "   TicTacToe      Control" << endl;
	int Control[3][3] = { {1, 2, 3},{4, 5, 6}, {7, 8, 9} };
	for (size_t y = 0; y < g.SIZE; y++)
	{
		cout << " | ";
		for (size_t x = 0; x < g.SIZE; x++)
		{
			cout << g.ppField[y][x] << " | ";
		}
		cout << " < |";
		for (size_t x = 0; x < g.SIZE; x++)
		{
			cout << Control[y][x] << "|";
		}
		cout << endl;
	}

	cout << endl << " Player: " << g.Player << "  Bot: " << g.AI << endl;
}

void __fastcall gameOver(const Game& g)
{
	if (g.progress == wonPlayer)
		cout << "You WON!" << endl;
	if (g.progress == wonAI)
	cout << "You LOST!" << endl;
	if (g.progress == tieGG)
	cout << "Draw!" << endl;
}


GameStat getWon(const Game& g)
{
	for (size_t y = 0; y < g.SIZE; y++) //check strings for win position
	{
		if (g.ppField[y][0] == g.ppField[y][1] && g.ppField[y][0] == g.ppField[y][2])
		{
			if (g.ppField[y][0] == g.Player)
				return wonPlayer;

			if (g.ppField[y][0] == g.AI)
				return wonAI;
		}
	}

	for (size_t x = 0; x < g.SIZE; x++) //check column for win position
	{
		if (g.ppField[0][x] == g.ppField[1][x] && g.ppField[0][x] == g.ppField[2][x])
		{
			if (g.ppField[0][x] == g.Player)
				return wonPlayer;

			if (g.ppField[0][x] == g.AI)
				return wonAI;
		}
	}

	if (g.ppField[0][0] == g.ppField[1][1] && g.ppField[0][0] == g.ppField[2][2]) // check diag
	{
		if (g.ppField[0][0] == g.Player)
			return wonPlayer;

		if (g.ppField[0][0] == g.AI)
			return wonAI;
	}

	if (g.ppField[0][2] == g.ppField[1][1] && g.ppField[2][0] == g.ppField[1][1])
	{
		if (g.ppField[1][1] == g.Player)
			return wonPlayer;

		if (g.ppField[1][1] == g.AI)
			return wonAI;
	}

	bool draw = true; //check for draw (if have empty ceels)

	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMPTY)
			{
				draw = false;
				break;
			}
		}
		if (!draw)
			break;
	}

	if (draw)
		return tieGG;
	//else game procced...
	return proceed;
}

Coord getPlayerCoord(const Game& g)
{
	Coord c;
	int m;
	//get move
	do {
		do {
			cout << "Enter 1-9 to get move: ";
			cin >> m;

		} while (m <= 0 || m > 9);

		switch (m) {
		case (1): c.x = 1, c.y = 1;
			break;
		case (2): c.x = 2, c.y = 1;
			break;
		case (3): c.x = 3, c.y = 1;
			break;
		case (4): c.x = 1, c.y = 2;
			break;
		case (5): c.x = 2, c.y = 2;
			break;
		case (6): c.x = 3, c.y = 2;
			break;
		case (7): c.x = 1, c.y = 3;
			break;
		case (8): c.x = 2, c.y = 3;
			break;
		case (9): c.x = 3, c.y = 3;
			break;
		default:
			cout << "Error!" << endl;
		}
	} while (g.ppField[c.y - 1][c.x - 1] != EMPTY);

	c.y--; //convertation
	c.x--;

	return c;
}

Coord getAICoord(Game & g)
{
	//Player win prediction
	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMPTY)
			{
				g.ppField[y][x] = g.AI;
				if (getWon(g) == wonAI)
				{
					g.ppField[y][x] = EMPTY;
					cout << "PredictionWin" << y << x << endl;
					return { y, x };
				}
				g.ppField[y][x] = EMPTY;
			}
		}
	}

	//AI fail prediction

	for (size_t y = 0; y < g.SIZE; y++)
	{
		for (size_t x = 0; x < g.SIZE; x++)
		{
			if (g.ppField[y][x] == EMPTY)
			{
				g.ppField[y][x] = g.Player;
				if (getWon(g) == wonPlayer)
				{
					g.ppField[y][x] = EMPTY;
					cout << "PredictionFalse" << y << x << endl;
					return { y, x };
				}
				g.ppField[y][x] = EMPTY;
			}
		}
	}

	if (g.ppField[1][1] == EMPTY)
		return { 1, 1 }; //center

	Coord arr[4];                     //corners
	size_t n = 0;
	if (g.ppField[0][0] == EMPTY)
	{
		arr[n] = { 0, 0 };
		n++;
	}

	if (g.ppField[2][2] == EMPTY)
	{
		arr[n] = { 2, 2 };
		n++;
	}

	if (g.ppField[0][2] == EMPTY)
	{
		arr[n] = { 0, 2 };
		n++;
	}

	if (g.ppField[2][0] == EMPTY)
	{
		arr[n] = { 2, 0 };
		n++;
	}

	if (n > 0)
	{
		const size_t index = getRandomN(0, 1000) % n; //get random number 0 - size-1
		return arr[index];
	}

	n = 0;
	if (g.ppField[0][1] == EMPTY)     //mid sides
	{
		arr[n] = { 0, 1 };
		n++;
	}

	if (g.ppField[2][1] == EMPTY)
	{
		arr[n] = { 2, 1 };
		n++;
	}

	if (g.ppField[1][0] == EMPTY)
	{
		arr[n] = { 1, 0 };
		n++;
	}

	if (g.ppField[1][2] == EMPTY)
	{
		arr[n] = { 1, 2 };
		n++;
	}

	if (n > 0)//if empty corner cell exist
	{
		const size_t index = getRandomN(0, 1000) % n;
		return arr[index];
	}

	return {};
}
bool checkGameField(const Game& g, Coord c, Cell cell) { //for debug
	if (c.x > g.SIZE - 1) {
		cout << "Error: wrong x coord";
		return false;
	}

	if (c.y > g.SIZE - 1) {
		cout << "Error: wrong y coord";
		return false;
	}

	if (g.ppField[c.y][c.x] == EMPTY) {
		g.ppField[c.y][c.x] = cell;
		return true;
	}
	else {
		cout << "Error: Field is not empty" << c.y << c.x;
		return false;
	}

	cout << "Unknown error";
	return false;
}


int main()
{
	Game g;
	initGame(g);

	clearScreen();
	printGameField(g);

	do {
		if (g.turn % 2 == 0)  //player's turn
		{
			Coord c = getPlayerCoord(g);
			bool result = checkGameField(g, c, g.Player);
			if (!result) {
				return 0;
			}
		}
		else //AI turn
		{
			Coord c = getAICoord(g);
			bool result = checkGameField(g, c, g.AI);
			if (!result) {
				return 0;
			}
			this_thread::sleep_for(1500ms);
		}

		clearScreen();
		printGameField(g);
		g.progress = getWon(g);
		g.turn++;

	} while (g.progress == proceed);

	gameOver(g);

	deinitGame(g);

	return 0;

}