class Solution {
    int dp[100001][2][2];
public:
    int maxProduct(vector<int>& v) {
        int n= v.size();
        
        for (int i= 0; i<= n; i++)
        for (int j= 0; j< 2; j++)
        for (int k= 0; k< 2; k++)
                dp[i][j][k]= -1;
        
        function<int(int, int, int)> calc= [&](int idx, int b, int e)->int{
            if (idx== n) {
                    return 1;
            }
            
            int &ret= dp[idx][b][e];
            if(ret!= -1) return ret;
            ret= INT_MIN;
            
            if (e== 1) {
                ret= max(ret, calc(idx+ 1, b, e));
            } else {
                if (b== 0) {
                    if (idx!= n-1)ret= max(ret, calc(idx+ 1, 0, 0));
                    ret= max(ret, calc(idx+ 1, 1, 0)* v[idx]);
                } else {
                    ret= max(ret, calc(idx+ 1, 1, 0)* v[idx]);
                    return ret;
                }
            }
            return ret;
        };
        
        return calc(0, 0, 0);
    }
};
