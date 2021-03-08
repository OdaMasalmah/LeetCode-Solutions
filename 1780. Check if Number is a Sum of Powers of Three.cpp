class Solution {
public:
    bool checkPowersOfThree(int n) {
        int val = 1;
        for (int i= 0; i<= 18; i++)
            val*= 3;
        for (int i= 18; i>= -1; i--) {
            n= (n>= val? n- val: n);
            val/= 3;
        }
        return (n== 0);
    }
};
