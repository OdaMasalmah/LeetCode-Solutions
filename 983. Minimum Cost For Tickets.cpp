class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        const int inf= 1e9+ 9;
        // dp[i]= min cost to pass day i if i abear in days
        vector<int> dp(367, inf);
        
        array<int, 3> ar= {1, 7, 30};
        
        for (int i= 0; i< days.size(); i++) {
            
            for (int j= 0; j< costs.size(); j++) {
                int d= days[i];
                int to= d- ar[j];
                bool can= 1;
                for (int k= to; k>= 0; k--) {
                    dp[d]= min({dp[d], dp[k]+ costs[j]});
                    if(dp[k]< inf) {
                        can= 0;
                        break;
                    }
                }
                if (can)
                    dp[d]= min(dp[d], costs[j]);
                
            }
        }
        
        return dp[days[days.size()- 1]];
    }
};
