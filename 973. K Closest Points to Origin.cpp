class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto cmp= [&](vector<int> &v, vector<int> &v1)->bool{
            return ((v[0]* v[0] + v[1]* v[1]))< ((v1[0]* v1[0] + v1[1]* v1[1]));
        };
        
        sort(begin(points), end(points), cmp);
        
        vector<vector<int>> ans;
        
        for (int i= 0; i< k; i++) ans.push_back(points[i]);
                
        return ans;
    }
};
