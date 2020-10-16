class Solution {
public:
    int numDecodings(string s) {
        int n= s.size();
        vector<int> dp(n+ 1, -1);
        
        function<int(int)> calc= [&](int idx) -> int{
            if (idx>= n) {
                return 1;
            }
            
           int &ret= dp[idx];
           if (ret!= -1) return ret;
           ret= 0;
                
            int nm= 0;
            for (int i= idx; i< min(idx+ 2, n); i++) {
                nm= nm* 10+ (s[i]- '0');
                if (nm> 26|| nm<= 0) break;
                ret+= calc(i+ 1);
            }
            return ret;
        };
        return calc(0);
    }
};
