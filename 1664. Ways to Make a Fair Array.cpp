class Solution {
public:
    int waysToMakeFair(vector<int>& arr) {
        int n= arr.size();
        vector<int> prefodd(n+ 1, 0), prefeven(n+ 1, 0);
        for (int i= 1; i<= n; i++) {
            prefodd[i]= prefodd[i- 1];
            prefeven[i]= prefeven[i- 1];
            if (i% 2== 0) {
                prefodd[i]= prefodd[i- 1]+ arr[i- 1];
            }else prefeven[i]= prefeven[i- 1]+ arr[i- 1];
        }
        int an= 0;
        for (int i= 1; i<= n; i++) {
            int odd= prefodd[i- 1]+ prefeven[n]- prefeven[i];
            int even= prefeven[i- 1]+ prefodd[n]- prefodd[i];
            if (odd== even) an+= 1;
        }
        return an;
    }
};
