class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx= INT_MIN, cnt= 0;
        
        for (auto x: nums) {
            cnt= max(x, cnt+ x);
            mx= max(mx, cnt);
        }
        
        return mx;
    }
};
