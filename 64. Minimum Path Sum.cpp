class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<long long>> dp(n+ 1);
        vector<vector<int>> g(n+ 1);
        
        for (int i= 0; i<= n; i++) {
            for (int j= 0; j<= m; j++) {
                dp[i].push_back(INT_MAX);
                g[i].push_back(0);
            }
        }
        
        for (int i= 0; i< n; i++) {
            for (int j= 0; j< m; j++) {
                g[i+ 1][j+ 1]= (grid[i][j]);
            }
        }
        
        dp[1][1]= g[1][1];
        
        for (int i= 1; i<= n; i++) {
            for (int j= 1; j<= m; j++) {
                if (i== 1&& j== 1) continue;
                else{
                    dp[i][j]= min(dp[i][j], dp[i- 1][j]+ g[i][j]);
                    dp[i][j]= min(dp[i][j], dp[i][j- 1]+ g[i][j]);
            
                }
            }
        }
        
        return dp[n][m];
    }
};
