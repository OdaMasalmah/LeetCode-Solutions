class Solution {
    struct edge{
        int to, w;
        bool operator<(const edge &e) const{
            return e.w< w;
        }
    };
    const int MOD = 1e9+ 7;
    vector<edge> adj[20001];
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        for (auto x: edges) {
            adj[x[0]].push_back({x[1], x[2]});
            adj[x[1]].push_back({x[0], x[2]});
        }
        priority_queue<edge> pq;
        vector<int> dist(n+ 1, 1e9);
        vector<int> dp(n+ 1, 0);
        dist[n]= 0;
        dp[n]= 1;
        pq.push({n, 0});
        while (pq.size()) {
            edge e = pq.top();
            pq.pop();
            if (dist[e.to]< e.w) continue;
            for (auto x: adj[e.to]) {
                if (x.w + e.w< dist[x.to]) {
                    dist[x.to]= (x.w+ e.w);
                    pq.push({x.to, x.w+ e.w});
                }
                if (e.w< dist[x.to]) {
                    if (e.to== n&& x.to== 1) dp[x.to] = dp[e.to];
                    else dp[x.to]= (dp[x.to] + dp[e.to])% MOD;
                }
            }
        }
        return dp[1];
    }
};
