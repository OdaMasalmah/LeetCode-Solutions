class Solution {                        
public:
    int totalHammingDistance(vector<int>& nums) {
        int answer= 0;
        for (int i= 30; i>= 0; i--) {
            int one= 0, zero= 0;
            for (auto x: nums) {
                if (x& 1<< i) {
                    one++;
                }else zero++;
            }
            answer+= (one* zero);
        }
        return answer;
    }
};
