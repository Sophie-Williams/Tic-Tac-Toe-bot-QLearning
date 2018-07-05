#pragma once

#include <string>
#include <vector>
#include <map>

#include "Helper.h"

using namespace std;

#define MAX_STATE 20000
#define MAX_ACTION 9

class QLearning
{
public:
	QLearning(double learningRate, double discount);
	~QLearning();

	int getAction(string state);
	void addReward(int reward);
	void update();

private:
	int mStateCounter;
	double mLearningRate, mDiscount;
	double mQValue[MAX_STATE][MAX_ACTION];
	map<string, int> mStateID;
	vector<int> mStates;
	vector<int> mActions;
	vector<int> mRewards;
};

