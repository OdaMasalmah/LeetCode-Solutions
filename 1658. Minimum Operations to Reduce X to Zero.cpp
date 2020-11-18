class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        vector<int> pref(n+ 1, 0), suf(n+ 1, 0);
        for (int i= 1; i<= n; i++) pref[i]= pref[i- 1]+ nums[i- 1];
        for (int i= n- 1; i>= 0; i--) suf[i]= suf[i+ 1]+ nums[i];
        map<int, int> mp;
        for (int i= 0; i< n; i++) mp[suf[i]]= n- i;
        int mn= 1e9;
        for (int i= 0; i<= n; i++) {
            if (pref[i]== x) {
                mn= min(mn, i);
            } else {
                int target= x- pref[i];
                if (mp.count(target)) {
                    if(i+ mp[target]<= n)
                        mn= min(mn, i+ mp[target]);
                }
            }
        }
        return (mn== 1e9? -1: mn);
    }
};
