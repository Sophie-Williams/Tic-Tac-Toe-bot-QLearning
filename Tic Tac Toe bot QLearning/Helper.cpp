#include "Helper.h"



bool Helper::validMove(string state, int move)
{
	if (state[move] != 'X'&&state[move] != 'O')
	{
		return true;
	}
	return false;
}

Helper::Helper()
{
}


Helper::~Helper()
{
}
