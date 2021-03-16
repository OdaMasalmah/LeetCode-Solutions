class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double an= 0;
        auto calc= [](pair<int, int> &a)-> double{
            return (1.0* (a.first+ 1)/ (a.second+ 1)- 1.0* a.first/ a.second);
        };
        auto compare = [&](pair<int, int> a, pair<int, int> b) { 
            return calc(a)< calc(b);
        };
        priority_queue <pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        for (auto x: classes) {
            pq.push({x[0], x[1]});
        }
        while (extraStudents--) {
            pair<int, int> cur= pq.top();
            pq.pop();
            cur.first+= 1;
            cur.second+= 1;
            pq.push(cur);
        } 
        while (pq.size()) {
            pair<int, int> cur= pq.top();
            an+= 1.0* cur.first/ cur.second;
            pq.pop();
        }
        an/= classes.size();
        return an;
    }
};
