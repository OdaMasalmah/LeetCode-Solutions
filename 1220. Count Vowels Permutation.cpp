class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD= 1e9+ 7;
        vector<vector<int>> dp(n, vector<int> (6, -1));
        
        auto ADD= [&](int &x, int y)->void{
            if (x> MOD) x-= MOD;
            if (y> MOD) y-= MOD;
            x+= y;
            if (x> MOD) x-= MOD;
        };
        
        function<int(int, int)> calc= [&](int idx, int last)->int{
            if (idx== n){
                return 1;
            }
            
            int &ret= dp[idx][last];
            if (ret!= -1) return ret;
            ret= 0;
            
            if (last== 1) { // a
                
                ADD(ret, calc(idx+ 1, 2));
                
            }else if(last== 2) { // e
                
                ADD(ret, calc(idx+ 1, 1));
                ADD(ret, calc(idx+ 1, 3));
                
            }else if (last== 3) { // i
                
                for (int i= 1; i<= 5; i++) {
                    if (i!= 3) {
                        ADD(ret, calc(idx+ 1, i));
                    }
                }
                
            }else if (last== 4) { // o
                ADD(ret, calc(idx+ 1, 3));
                ADD(ret, calc(idx+ 1, 5));
            } else if (last== 5) { // u
                ADD(ret, calc(idx+ 1, 1));
            }
            
            return ret;
        };
        
        int ans= 0;
        for (int i= 1; i<= 5; i++) ADD(ans, calc(1, i));
        
        return ans;
    }
};
