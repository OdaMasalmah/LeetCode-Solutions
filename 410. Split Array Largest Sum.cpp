class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sm= 0;
        for (auto x: nums) sm+= x;
        auto can= [&](int md) {
            int cnt= 0, g= 1;
            for (int i= 0; i< nums.size(); i++) {
                cnt+= nums[i];
                if (nums[i]> md) return 0;
                if (cnt> md) {
                    g++;
                    cnt= nums[i];
                }
            }
            return g<= m? 1: 0;
        };
        int lo= -1, hi= sm;
        while (hi- lo> 1) {
            int md= (lo+ hi)/ 2;
            if (can(md))
                hi= md;
            else lo= md;
        }
        return hi;
    }
};
