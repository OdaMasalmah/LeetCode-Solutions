class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[102][102]= {0};
        int g[102][102]= {0};
        
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        
        for (int i= 1; i<= n; i++) 
            for (int j= 1; j<= m; j++) 
                g[i][j]= obstacleGrid[i- 1][j- 1];
            
        dp[1][1]= (g[1][1]== 1? 0: 1);
        
        for (int i= 1; i<= n; i++) {
            for (int j= 1; j<= m; j++) {
                if (g[i][j]== 0){
                    
                    if (g[i- 1][j]!= 1) 
                        dp[i][j]+= dp[i- 1][j];
                    
                    if (g[i][j- 1]!= 1) 
                        dp[i][j]+= dp[i][j- 1];
                    
                }
            }
        }
        
        return dp[n][m];
    }
};
