class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int N= arr.size();
        vector<int> v;
        const int MOD= 1e9+ 7;
        long long sm= 0, maxpref= 0, pref= 0, suf= 0, maxsuf= 0;
        
        for (auto X: arr) sm+= X;
        
        for (auto X: arr) {
            pref+= X;
            maxpref= max(maxpref, pref);
        }
        reverse(begin(arr), end(arr));
        for (auto X: arr) {
            suf+= X;
            maxsuf= max(maxsuf, suf);
        }
        
        reverse(begin(arr), end(arr));
        if (sm> 0&& k>= 2) {
            sm= ((k- 2)% MOD* sm% MOD)% MOD;
            sm= (sm%MOD +maxpref%MOD+ maxsuf%MOD + MOD)% MOD;
            return sm;
        }
        
        for (auto X: arr) v.push_back(X);
        
        if (k> 1) {
            for (auto X: arr) v.push_back(X);
            N*= 2;
        }
        long long cnt= 0, mx= 0;
        
        for (int i= 0; i< N; i++) {
            cnt= max((long long)v[i], cnt+ v[i]);
            if (cnt> mx) {
                mx= cnt;
            }
        }

        return mx;
    }
};
