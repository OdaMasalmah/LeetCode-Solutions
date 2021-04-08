class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        auto get_rev = [](int x) {
            int nm = 0;
            bool start = false;
            while (x) {
                int rem = x % 10;
                if (start) nm = nm * 10 + rem;
                if (rem > 0&& !start) {
                    start = true;
                    nm = nm * 10 + rem;
                }
                x /= 10;
            }
            return nm;
        };
        long long ans = 0;
        int n = nums.size(), MOD = 1e9 + 7;
        map<int, int> freq;
        // (nums[i] - rev[i]) = (nums[j] - rev[j]) => (nums[i] - rev[i]) - (nums[j] - rev[j]) = 0
        for (int i = 0; i < n; i++) {
            ans += freq[nums[i] - get_rev(nums[i])];
            freq[nums[i] - get_rev(nums[i])]+= 1;
        }
        return ans% MOD;
    }
};
