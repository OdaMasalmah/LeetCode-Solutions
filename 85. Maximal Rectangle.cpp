class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size()== 0) return 0;
        int n= matrix.size();
        int m= matrix[0].size();
        vector<int> v(m, 0);
        
        auto calc= [](vector<int> v) {
            stack<int> st;
            int n= v.size();
            vector<int> s1(n+ 1, 0);
            vector<int> s2(n+ 1, 0);
            
            for (int i= 0; i< n; i++) {
                    while (st.size() > 0 && v[st.top()] >= v[i]) st.pop();
                    if (st.size() == 0) s2[i] = -1;
                    else { s2[i] = st.top(); }
                    st.push(i);
            }
            while (st.size()) st.pop();
            for (int i = n - 1; i >= 0; i--) {
                    while (st.size() > 0 && v[st.top()] >= v[i]) st.pop();
                    if (st.size() == 0) s1[i] = -1;
                    else { s1[i] = st.top(); }
                    st.push(i);
            }
            while (st.size()) st.pop();

            int mx= 0;
            for (int i= 0; i< n; i++) {
                    int l= (s2[i]== -1? 0: s2[i]+ 1);
                    int r= (s1[i]== -1? n- 1: s1[i]- 1);
                    mx= max(mx, (r- l+ 1)* v[i]);
             }
            return mx;
        };
        
        int mx= INT_MIN;
        
        for (int i= 0; i< n; i++) {
            for (int j= 0; j< m; j++) {
                if (matrix[i][j]== '1') v[j]+= 1;
                else v[j]= 0;
            }
            mx= max(mx, calc(v));
        }
        
        return mx;
    }
};
