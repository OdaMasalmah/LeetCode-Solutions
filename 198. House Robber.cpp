class Solution {
    int dp[101][2];
    int calc(int idx, bool wh, vector<int> &nums) {
        if (idx== nums.size())
            return 0;
        
        int &ret= dp[idx][wh];
        if(ret!= -1) return ret;
        ret= 0;
        
        ret= max(ret, calc(idx+ 1, 0, nums));
        if (wh== 0)
            ret= max(ret, calc(idx+ 1, 1, nums)+ nums[idx]);
        return ret;
    }
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return calc(0, 0, nums);
    }
};
