class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st;
        st.insert(1);
        vector<long long> ans;
        while (ans.size()<= n) {
            long long x= *st.begin();
            st.erase(st.begin());
            ans.push_back(x);
            st.insert(x* 2);
            st.insert(x* 3);
            st.insert(x* 5);
        }
        return ans[n- 1];
    }
};
