class Solution {
public:
    int numSquares(int n) {
        const int inf= 1e9;
        vector<int> dp(n+ 4, inf);
        dp[0]= 0;
        dp[1]= 1;
        dp[2]= 2;
        dp[3]= 3;
        
        for (int i= 4; i<= n; i++) {
            for (int j= 1; j* j<= i; j++) {
                dp[i]= min(dp[i], dp[i- (j* j)]+ 1);
            }
        }
        
        return dp[n];
    }
};
