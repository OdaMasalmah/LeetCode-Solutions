class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> pref(nums.size()+ 2, 0);
        map<int, int> mp;
        
        if (k== 0) {
            for (int i= 1; i< (int)nums.size(); i++) {
                if (nums[i]== nums[i- 1]&& nums[i]== 0) return true;
            }

            return false;
        }
        
        mp[0]= 1;
        
        for (int i= 1; i<= (int)nums.size(); i++) {
            pref[i]= (nums[i- 1]+ pref[i- 1])% k;
            
            if (i> 1&& mp.count(pref[i])) {
                return true;
            }
            if (i> 1) mp[pref[i- 1]]++;
        }
        
        return false;
    }
};
