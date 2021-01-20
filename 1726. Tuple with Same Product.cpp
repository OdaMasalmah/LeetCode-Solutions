class Solution {
public:
    int tupleSameProduct(vector<int>& ar) {
        int n= ar.size();
        map<int, int> mp;
        long long ans= 0;
        for (int i= 0; i< n- 1; i++) {
            for (int j= i+ 1; j< n; j++) {
                int x= ar[i]* ar[j];
                mp[x]+= 1;
            }
        }
        for (auto x: mp) 
            ans+= x.second* (x.second- 1)/ 2* 8;
        return ans;
    }
};
