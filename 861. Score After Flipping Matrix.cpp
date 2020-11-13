class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int N= A.size();
        int M= A[0].size();
        
        for (int i= 0; i< N; i++) {
            if (A[i][0]== 0) {
                for (int j= 0; j< M; j++) {
                    A[i][j]^= 1;
                }
            }
        }
        
        for (int i= 1; i< M; i++) {
            int z= 0, o= 0;
            for (int j= 0; j< N; j++) o+= A[j][i];
            z= N- o;
            if (z> o) {
                for (int j= 0; j< N; j++) A[j][i]^= 1;
            }
        }
        
        int ans= 0;
        
        for (int i= 0; i< N; i++) { 
            int pw= 1;
            for (int j= M- 1; j>= 0; j--) {
                if (A[i][j]) {
                    ans+= pw;
                }
                pw= pw<< 1;
            }
                
        }
        return ans;
    }
};
