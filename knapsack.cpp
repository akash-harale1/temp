#include <bits/stdc++.h>
using namespace std;

int knapsack(int index, int wt, vector<int> &val, vector<int> &weights, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (weights[index] <= wt)
        {
            return val[index];
        }

        return 0;
    }

    if (dp[index][wt] != -1)
        return dp[index][wt];

    int not_take = 0 + knapsack(index - 1, wt, val, weights, dp);

    int take = INT_MIN;

    if (weights[index] <= wt)
    {
        take = val[index] + knapsack(index - 1, wt - weights[index], val, weights, dp);
    }

    return dp[index][wt] = max(not_take, take);
}

int main()
{
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int max_weight = 50;
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(max_weight + 1, -1));
    cout << knapsack(n - 1, max_weight, values, weights, dp);
}