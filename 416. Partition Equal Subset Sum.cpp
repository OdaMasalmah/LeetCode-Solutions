class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm = 0;
        for (int i = 0; i < nums.size(); i++) sm += nums[i];
        if (sm % 2 == 0) {
            sm /= 2;
            bool arr[nums.size() + 1][sm + 1] = {};
            for (int i = 0; i < nums.size(); i++) 
                arr[i][0] = 1;
            for (int i = 1; i <= sm; i++)
                arr[0][i] = 0;
            for (int i = 1; i <= nums.size(); i++) {
                for (int j = 1; j <= sm; j++) {
                    if (j < nums[i - 1]) {
                        arr[i][j] = arr[i - 1][j];
                    } else arr[i][j] = arr[i - 1][j] || arr[i - 1][j-nums[i - 1]];
                }
            }
            return arr[nums.size()][sm];
            
        } else return false;
    }
};
