class Solution {
    int dp[501];
    int calc(int idx, int k, vector<int>&A) {
        if (idx== A.size())
            return 0;
        
        int &ret= dp[idx];
        if (ret!= -1) return ret;
        ret= 0;
        
        int mx= 0;
        for (int i= idx, wh= 1; i< min(idx+ k, (int)A.size()); i++, wh++) {
            mx= max(mx, A[i]);
            ret= max(ret, calc(i+ 1, k, A)+ (mx* wh));
        }
        return ret;
        
    }
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        memset(dp, -1, sizeof dp);
        return calc(0, K, A);
    }
};
