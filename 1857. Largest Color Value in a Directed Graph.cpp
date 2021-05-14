class Solution {
    int color[100001][27];
    vector<int> adj[100001];
    int vis[100001];
    string co;
    int dfs(int u) {
        if (vis[u] == 2) 
            return 1;
        if (vis[u] == 1) 
            return 0;
        color[u][co[u] - 'a'] += 1;
        vis[u] = 2;
        bool ret = 0;
        for (auto x: adj[u]) {
            ret |= dfs(x);
            for (int i = 0; i < 26; i++) {
                color[u][i] = max(color[x][i] + (i == (co[u] - 'a') ? 1 : 0), color[u][i]);
            }
        }
        vis[u] = 1;
        return ret;
    }
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        co = colors;
        for (auto x: edges) adj[x[0]].push_back(x[1]);
        for (int i = 0; i < colors.size(); i++) {
            if (vis[i] == 0 && dfs(i)) return -1;
            
        }
        int mx = 0;
        for (int i = 0; i < colors.size(); i++) {
            for (int j = 0; j < 26; j++) 
                mx = max(mx, color[i][j]);
        }
        return mx;
    }
};
