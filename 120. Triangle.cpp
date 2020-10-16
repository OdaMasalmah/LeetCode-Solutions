class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int vis[triangle.size() + 1][triangle[triangle.size() - 1].size() + 1] = {};
        bool viss[triangle.size() + 1][triangle[triangle.size() - 1].size() + 1] = {};
        
        vis[0][0] = triangle[0][0];
        viss[0][0] = 1;
        
        for (int i = 0; i < triangle.size(); i++) {
            if (i == triangle.size() - 1) {
                int mn = 1e9;
                for (int j = 0; j < triangle[i].size(); j++) mn = min(mn,  vis[i][j]);
                return mn;
            }
            
            for (int j = 0; j < triangle[i].size(); j++) {
                if (viss[i + 1][j]) {
                    vis[i + 1][j] = min(vis[i + 1][j], vis[i][j] + triangle[i + 1][j]);
                } else vis[i + 1][j] = vis[i][j] + triangle[i + 1][j];
                
                if (viss[i + 1][j + 1]) {
                    vis[i + 1][j + 1] = min(vis[i + 1][j], vis[i][j] + triangle[i + 1][j + 1]);
                } else vis[i + 1][j + 1] = vis[i][j] + triangle[i + 1][j + 1];
                viss[i + 1][j] = 1;
                viss[i + 1][j + 1] = 1;
            }
            
        }        
        return 0;
    }

};
