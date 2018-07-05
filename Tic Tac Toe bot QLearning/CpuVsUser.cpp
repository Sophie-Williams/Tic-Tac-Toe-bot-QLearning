#include <iostream>

#include "TicTacToe.h"
#include "QLearning.h"

using namespace std;

TicTacToe game;
QLearning bot(.5, .8);

int main()
{

	int n, pos;
	cout << "Enter no of trial: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		game.reset();
		while (!game.isFinished())
		{
			if (game.getCurrPlayer() == 2)
			{
				cout << "here" << endl;
				pos = bot.getAction(game.getBoardState());
				game.move(pos+1);
				bot.addReward(0);
			}
			else
			{
				system("cls");
				game.printBoard();

				cout << "Current player: " << game.getCurrPlayer() << endl;
				cout << "Enter pos: ";
				cin >> pos;

				if (!game.move(pos))
				{
					cout << "Invalid move" << endl;
					cout << "Press ENTER to continue" << endl;
					cin.ignore();
					cin.ignore();
				}
			}
		}

		system("cls");
		game.printBoard();
		cout << "Player " << game.getWinner() << " wins!" << endl;
		cout << "Press ENTER to reset" << endl;
		cin.ignore();
		cin.ignore();

		bot.getAction(game.getBoardState());
		if(game.getWinner() == 2)
		{
			bot.addReward(3);
		}
		else if (game.getWinner() == 1)
		{
			bot.addReward(-3);
		}
		else
		{
			bot.addReward(-1);
		}
		cout << "updating" << endl;
		bot.update();
		cout << "updated" << endl;
	}
}