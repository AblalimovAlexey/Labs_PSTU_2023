#include <iostream>
using namespace std;

int board[8][8];

void viewTable(){
	for (int i = 0; i < 8; i++)	{
		for (int j = 0; j < 8; j++)	{
			if (board[i][j] == -1) {
				cout << " Q ";
			}
			else {
				cout << " - ";
			}
		}
		cout << endl;
	}
}

void setQueen(int i, int j) {
	for (int x = 0; x < 8; x++)	{
		++board[x][j];
		++board[i][x];
		int foo;
		foo = j - i + x;
		if (foo >= 0 && foo < 8)
			++board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < 8)
			++board[x][foo];
	}
	board[i][j] = -1;
}

void resetQueen(int i, int j) {
	for (int x = 0; x < 8; x++)	{
		--board[x][j];
		--board[i][x];
		int foo;
		foo = j - i + x;
		if (foo >= 0 && foo < 8)
			--board[x][foo];
		foo = j + i - x;
		if (foo >= 0 && foo < 8)
			--board[x][foo];
	}
	board[i][j] = 0;
}

bool tryQueen(int i) {
	bool success = false;
	for (int j = 0; j < 8; j++)	{
		if (board[i][j] == 0) {
			setQueen(i, j);
			if (i == 7)	{
				success = true;
			}
			else {
				if (!(success = tryQueen(i + 1))) {
					resetQueen(i, j);
				}
			}
		}
		if (success)	{
			break;
		}
	}
	return success;
}

bool tryQueen(){
	return tryQueen(0);
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++)	{
			board[i][j] = 0;
		}
	}
	tryQueen();
	viewTable();
	return 0;
}