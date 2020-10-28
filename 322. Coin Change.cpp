class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int inf= 1e9;
        vector<int> dp(amount+ 1, inf);
        dp[0]= 0;
        for (int i= 1; i<= amount; i++) {
            for (auto X: coins) {
                if (i- X>= 0)
                    dp[i]= min(dp[i], dp[i- X]+ 1);
            }
        }
        return (dp[amount]>= inf? -1: dp[amount]);
    }
};
