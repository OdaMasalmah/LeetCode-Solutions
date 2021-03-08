class Solution {
public:
    int beautySum(string s) {
        int n= s.size(), answer= 0;
        for (int i= 0; i< n; i++) {
            vector<int> freq(27, 0);
            for (int j= i; j< n; j++) {
                freq[s[j]- 'a']+= 1;
                int mn= n, mx= 0;
                for (int ch = 0; ch<= 26; ch++) {
                    mx= max(mx, freq[ch]);
                    mn= min(mn, freq[ch]> 0? freq[ch]: mn);
                }
                answer+= mx> mn? (mx- mn): 0;
            }
        }
        return answer;
    }
};
