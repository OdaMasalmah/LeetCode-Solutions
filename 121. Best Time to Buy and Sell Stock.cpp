class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) 
            return 0;
        
        int ans = -1, bst = prices[prices.size() - 1];
        
        for (int i = prices.size() - 2; i >= 0; i--) {
            ans = max(ans, bst - prices[i]);
            bst = max(bst, prices[i]);
        }
        
        return (ans>=0)?ans:0;
    }
};
