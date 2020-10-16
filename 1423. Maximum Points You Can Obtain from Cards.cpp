class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        vector<int> pref(n+ 1, 0);
        
        int ans= 0;
        
        for (int i= 1; i<= n; i++) {
            pref[i]= pref[i- 1] + cardPoints[i- 1];
            if (i<= k) ans= max(ans, pref[i]);
        }
        
        int suf= 0;
        k--;
        for (int i= n- 1; i>= 0; i--) {
            suf+= cardPoints[i];
            ans= max(ans, pref[k]+ suf);
            if (k== 0) break;
            k--;
        }
        return ans;
    }
};
