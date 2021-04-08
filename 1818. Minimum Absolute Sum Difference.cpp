class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long mx = 0, ans = 0;
        int MOD = 1e9 + 7, n = nums1.size();
        vector<int> ar(nums1.size(), 0);

        for (int i = 0; i < n; i++) {
            mx += abs(nums1[i] - nums2[i]);
            ar[i] = nums1[i];
        }
        
        ans = mx;
        sort(begin(ar), end(ar));
        for (int i = 0; i < n; i++) {
            auto posBig = lower_bound(begin(ar), end(ar), nums2[i]);
            if (posBig == begin(ar)) {
                int b = *posBig;
                ans = min(ans, mx + abs(nums2[i] - b) - abs(nums2[i] - nums1[i]));
            }else if (posBig == end(ar)) {
                posBig--;
                int l = *posBig;
                ans = min(ans, mx + abs(l - nums2[i]) - abs(nums2[i] - nums1[i]));
            }else {
                int b = *posBig;
                posBig--;
                int l = *posBig;
                ans = min({ans, mx + abs(b - nums2[i]) - abs(nums2[i] - nums1[i]), mx + abs(l - nums2[i]) - abs(nums2[i] - nums1[i])});
            }
        }
        return ans% MOD;
    }
};
