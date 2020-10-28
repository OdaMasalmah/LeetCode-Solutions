class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int inf= 1e9;
        const int N= stations.size();
        // dp[i][j]= max fule can get with i stations end in jth 
        vector<vector<long long>> dp(N+ 1, vector<long long> (N+ 1, startFuel));
        for (int i= 1; i<= N; i++) {
            for (int j= 1; j<= N; j++) {
                if (stations[j- 1][0]<= dp[i- 1][j- 1]) {
                    dp[i][j]= max(dp[i][j], dp[i- 1][j- 1]+ stations[j- 1][1]);
                }
                dp[i][j]= max(dp[i][j], dp[i][j- 1]);
            }
        }
        for(int i= 0; i<= N; i++) {
            for (int j= 0; j<= N; j++) {
                if (dp[i][j]>= target) 
                    return i;
            }
        }
        return -1;
    }
};
