class Solution {
public:
    int maxCoins(vector<int>& nums) {
    
        int n= nums.size();
        vector<vector<int>> dp(n+ 1);
        
        for (int i= 0; i<= n; i++) 
            for (int j= 0; j<= n; j++) dp[i].push_back(-1);
        
        function<int(int, int)> calc= [&](int start, int end) {
            if (end< start) return 0;
            
            int &ret= dp[start][end];
            if (ret!= -1) return ret;
            ret= 0;
            
            for (int i= start; i<= end; i++) {
                int left= calc(start, i- 1);
                int right= calc(i+ 1, end);
                ret= max(ret, left+ right+ nums[i]* (start- 1< 0? 1:  nums[start- 1])* (end+ 1>= n? 1: nums[end+ 1]));
            }
            
            return ret;
        };
    
        return calc(0, nums.size()- 1);
    }
    
};
