class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N= text1.size();
        int M= text2.size();
        vector<vector<int>> dp(N+ 1, vector<int>(M+ 1, 0));

        for (int i= 1; i<= N; i++) {
            for (int j= 1; j<= M; j++) {
                if (text1[i- 1]== text2[j- 1]) {
                    dp[i][j]= max(dp[i][j], dp[i- 1][j- 1]+ 1);
                }else {
                    dp[i][j] = max({
                        dp[i][j],
                        dp[i][j- 1],
                        dp[i- 1][j]
                    });
                }
            }
        }
        return dp[N][M];
    }
        
};
