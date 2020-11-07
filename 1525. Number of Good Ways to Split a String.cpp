class Solution {
public:
    int numSplits(string s) {
        vector<int> freq1(27, 0), freq2(27, 0);
        int n= s.size();
        for (int i= 0; i< n; i++) 
            freq1[s[i]- 'a']++;
        
        int ans= 0;
        for (int i= 0; i< n; i++) {
            --freq1[s[i]- 'a'];
            ++freq2[s[i]- 'a'];
            int an1= 0, an2= 0;
            for (int j= 0; j< 26; j++) {
                if (freq1[j]) an1++;
                if (freq2[j]) an2++;
            }
            if (an1== an2) ans++;
        }
        return ans;
    }
};
