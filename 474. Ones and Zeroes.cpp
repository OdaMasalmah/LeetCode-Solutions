class Solution {
    int dp[601][101][101];
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N= strs.size();
        vector<int> o(N), z(N);
        
        for (int i= 0; i< N; i++) {
            int one= 0;
            for (auto x: strs[i]) one+= (x- '0');
            o[i]= one;
            z[i]= strs[i].size()- one;
        }
        
        memset(dp, -1, sizeof dp);
        
        function<int(int, int, int)> calc= [&](int idx, int wn, int wm)->int{
            if (wn> n || wm> m) return -1e9;
            if (idx>= N) return 0;
            
            int &ret= dp[idx][wn][wm];
            if (ret!= -1) return ret;
            ret= 0;
            
            ret= max(ret, calc(idx+ 1, wn+ o[idx], wm+ z[idx])+ 1);
            ret= max(ret, calc(idx+ 1, wn, wm));
            return ret;
        };
        
        return calc(0, 0, 0);
    }
};
