class Solution {
public:
    vector<int> st, en, val;
    vector<vector<int>> dp;
    int n;
    
    int solve(int idx, int k) {
        if (k== 0) return 0;
        if (idx>= n) return 0;
        int &ret= dp[idx][k];
        if (ret!= -1) return ret;
        ret= 0;
        ret= max(ret, solve(idx+ 1, k));
        int neidx= upper_bound(begin(st), end(st), en[idx])- begin(st);
        ret= max(ret, solve(neidx, k- 1)+ val[idx]);
        return ret;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        n= events.size();
        sort(begin(events), end(events), [&](vector<int> a, vector<int> b)->bool{
            if (a[0]== b[0]) return a[1]< b[1];
            else return a[0]< b[0];
        }); 
        for (auto x: events) {
            st.push_back(x[0]);
            en.push_back(x[1]);
            val.push_back(x[2]);
        }
        dp.resize(n+ 1);
        for (int i= 0; i<= n; i++) {
            for (int j= 0; j<= k; j++) dp[i].push_back(-1);
        }
        return solve(0, k);
    }
};
