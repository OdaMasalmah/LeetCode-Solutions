class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B){
        vector<string> str;
        vector<vector<int>> freq(A.size(), vector<int> (26, 0));
        for (int i= 0; i< A.size(); i++) {
            for (int j= 0; j< A[i].size(); j++)
                freq[i][A[i][j]- 'a']++;
        }
        vector<int> freq2(26, 0);
        vector<bool> ans(A.size(), 1);
        for (int i= 0; i< B.size(); i++) {
            vector<int> f(26, 0);
            for (int j= 0; j< B[i].size(); j++) {
                f[B[i][j]- 'a']++;
            }
            for (int i= 0; i< 26; i++) freq2[i]= max(freq2[i], f[i]);
        }
        for (int i= 0; i< A.size(); i++) {
            for (int k= 0; k< 26; k++) {
                if (freq2[k]> freq[i][k]) ans[i]= 0;
            }
        }
        for (int i= 0; i< A.size(); i++) if (ans[i]) str.push_back(A[i]);
        return str;
    }
};
