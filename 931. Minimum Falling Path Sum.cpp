class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        const int inf= 1e9;
        int n= A.size();
        //dp[i][j]= min sum to reach i, j from above row
        vector<vector<int>> dp(n+ 2, vector<int> (n+ 2, inf));
        for (int i= 1; i<= n; i++) 
            dp[0][i]= 0;
        for (int i= 1; i<= n; i++) {
            for (int j= 1; j<= n; j++) {
                dp[i][j]= min({
                    dp[i- 1][j]+ A[i- 1][j- 1],
                    dp[i- 1][j- 1]+ A[i- 1][j- 1],
                    dp[i- 1][j+ 1]+ A[i- 1][j- 1]
                });
            }
        }
        
        int answer= inf;
        for (int i= 1; i<= n; i++) 
            answer= min(answer, dp[n][i]);
        
        return answer;
    }
};
