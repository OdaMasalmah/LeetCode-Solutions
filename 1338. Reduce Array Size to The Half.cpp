class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (auto X: arr) {
            mp[X]++;
        }
        vector<int> v;
        int sm= 0;
        for (auto X: mp) {
            v.push_back(X.second);
            sm+= X.second;
        }
        sort(rbegin(v), rend(v));
        int sub= 0;
        for(int i= 0; i< v.size(); i++) {
            sub+= v[i];
            if (sm- sub<= sm/ 2) return i+ 1;
        }
        
        return -1;
    }
};
