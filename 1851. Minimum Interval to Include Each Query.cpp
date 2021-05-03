class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> ans(queries.size(), -1);
        vector<pair<int, int>> vb;
        vector<vector<int>> ind(queries.size() + 1);
        
        for (int i = 0; i < queries.size(); i++) 
            vb.push_back({queries[i], i});
        
        sort(begin(vb), end(vb));
        
        for (int i = 0; i < queries.size(); i++) 
            queries[i] = vb[i].first;
        
        for (int i = 0; i < intervals.size(); i++) {
            int idx = lower_bound(begin(queries), end(queries), intervals[i][0]) - begin(queries);
            if (idx < queries.size())
                ind[idx].push_back(i);
        }
        
        auto cmp = [](pair<int, int> a, pair<int, int> b) { 
            return a.second > b.second;
        };
        
        priority_queue< pair<int, int>, vector<pair<int, int>> , decltype(cmp)> q(cmp);
        
        for (int i = 0; i < queries.size(); i++) {
            for (auto x: ind[i]) q.push({x, intervals[x][1] - intervals[x][0] + 1});
            while (q.size() && queries[i] > intervals[q.top().first][1]) q.pop();
            if (q.size()) ans[vb[i].second] = q.top().second;
        }
        
        return ans;
    }
};
