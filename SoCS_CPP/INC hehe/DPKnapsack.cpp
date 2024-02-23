#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();

    // Create a 2D table to store the computed values
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill the table using bottom-up dynamic programming
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            // If the current item can fit into the knapsack
            if (weights[i - 1] <= w) {
                // Choose the maximum value between including and excluding the current item
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // If the current item is too heavy, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "|    |";
    for (int i = 0; i <= capacity; ++i) {
        printf("%5d|", i);
    }
    cout << endl;

    // Print separator line
    cout << "|----|";
    for (int i = 0; i <= capacity; ++i) {
        cout << "-----|";
    }
    cout << endl;

    // Print DP table
    for (int i = 0; i <= n; ++i) {
    	if(i == 0) printf("|  0 |");
        else printf("|%3d |", weights[i-1]);
        
        for (int j = 0; j <= capacity; ++j) {
            printf("%4d |", dp[i][j]);
        }
        cout << endl;
    }
    // The result is stored in the bottom-right cell of the table
    return dp[n][capacity];
}

int main() {
    // Example usage
    vector<int> values = {2, 5, 6};
    vector<int> weights = {1, 2, 3};
    int capacity = 5;

    int maxValue = knapsack(values, weights, capacity);

    cout << "Maximum value in the knapsack: " << maxValue << endl;

    return 0;
}
