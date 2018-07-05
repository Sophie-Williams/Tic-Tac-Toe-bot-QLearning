#include "TicTacToe.h"



TicTacToe::TicTacToe()
{
	reset();
}


TicTacToe::~TicTacToe()
{
}

void TicTacToe::reset()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int pos = (i * 3) + j;
			grid[i][j] = '1' + pos;
		}
	}
	sign[0] = 'X';
	sign[1] = 'O';
	currPlayer = 0;
	winner = -1;
}

bool TicTacToe::move(int pos)
{
	pos--;
	int row = pos / 3;
	int col = pos % 3;
	if (!isFinished() && row >= 0 && row<3 && col >= 0 && col<3)
	{
		grid[row][col] = sign[currPlayer++];
		currPlayer %= 2;
		return true;
	}
	return false;
}

bool TicTacToe::isFinished()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (grid[i][0] == sign[j] && grid[i][1] == sign[j] && grid[i][2] == sign[j])
			{
				winner = j;
				return true;
			}
		}

		for (int j = 0; j < 2; j++)
		{
			if (grid[0][i] == sign[j] && grid[1][i] == sign[j] && grid[2][i] == sign[j])
			{
				winner = j;
				return true;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if ((grid[0][0] == sign[i] && grid[1][1] == sign[i] && grid[2][2] == sign[i]) || (grid[0][2] == sign[i] && grid[1][1] == sign[i] && grid[2][0] == sign[i]))
		{
			winner = i;
			return true;
		}
	}

	return false;
}

int TicTacToe::getCurrPlayer()
{
	return currPlayer;
}

int TicTacToe::getWinner()
{
	return winner;
}

string TicTacToe::getBoardState()
{
	string boardState = "";

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			boardState += grid[i][j];
		}
	}

	return boardState;
}

void TicTacToe::printBoard()
{
	for (int i = 0; i < 12; i++)
	{
		cout << "=";
	}
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		if (i != 0)
		{
			for (int j = 0; j <= 10; j++)
			{
				cout << "-";
			}
			cout << endl;
		}

		cout << " " << grid[i][0] << " | " << grid[i][1] << " | " << grid[i][2] << endl;
	}

	for (int i = 0; i < 12; i++)
	{
		cout << "=";
	}
	cout << endl;
}
