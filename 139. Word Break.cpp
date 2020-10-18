class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.size(), m= wordDict.size();
        // dp[i]= can i get string from 0 to i from the list?
        vector<bool> dp(n+ 1, 0);
        // empty string 
        dp[0]= 1;
        
        for (int i= 1; i<= n; i++) {
            for (int j= 0; j< m; j++) {
                if (i>= wordDict[j].size()) {
                    bool ok= 1;
                    for (int ind= 0; ind< wordDict[j].size(); ind++) {
                        if (wordDict[j][ind]!= s[i- wordDict[j].size()+ ind]) {
                            ok= 0;
                        }
                    }
                    if (ok) dp[i]= dp[i]| dp[i- wordDict[j].size()];
                }
            }
        }
        
        return dp[n];
    }
};
