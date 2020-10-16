class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N= cost.size();
        if (N== 1) return 0;
        
        vector<int> dp(N+ 1, 0);
        dp[0]= cost[0];
        dp[1]= cost[1];
        
        for (int i= 2; i<= N; i++) {
            dp[i]= min(dp[i- 1], dp[i- 2]) + (i!= N? cost[i]: 0);
        }
        
        return dp[N];
    }
};
