class Solution {
public:
    int climbStairs(int n) {
        long long an= 1, f1= 1, f2= 1;
        for (int i= 2; i<= n; i++) {
            an= f1+ f2;
            f2= f1;
            f1= an;
        }
        return an;
    }
};
