#pragma once

#include <iostream>
#include <string>

using namespace std;

class TicTacToe
{
public:
	TicTacToe();
	~TicTacToe();

	void reset();
	bool move(int pos);
	bool isFinished();
	int getCurrPlayer();
	int getWinner();
	string getBoardState();
	void printBoard();

private:
	char grid[3][3];
	char sign[2];
	int currPlayer;
	int winner;
};