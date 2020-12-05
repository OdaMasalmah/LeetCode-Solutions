class Solution {
public:
    int minimumMountainRemovals(vector<int>& ar) {
        int n= ar.size();
        vector<int> dpL(n+ 1, 1), dpR(n+ 1, 1);
        for (int i= 1; i< n; i++) {
            for (int j= 0; j< i; j++) {
                if (ar[j]< ar[i]) {
                    dpL[i]= max(dpL[j]+ 1, dpL[i]);
                }
            }
        }
        for (int i= n- 2; i>= 0; i--) {
            for (int j= n- 1; j> i; j--) {
                if (ar[j]< ar[i]) {
                    dpR[i]= max(dpR[j]+ 1, dpR[i]);
                }
            }
        }
        int answer= n;
        for (int i= 1; i< n- 1; i++) {
            if (dpL[i]!= 1&& dpR[i]!= 1)
                answer= min(answer, n- (dpR[i]+ dpL[i]- 1));
        }
        return answer;
    }
};
