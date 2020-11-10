class Solution {
struct edge{
    int co, fr, to;
    edge(int a, int b, int d) {
        co= d;
        fr= a;
        to= b;
    }
    bool operator<(const edge& p) const{
        return co< p.co;
    }
    
};
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        auto dist= [&](int x, int y, int x1, int y1){
            return abs(x- x1)+ abs(y- y1);  
        };
        int n= p.size(), cost= 0;
        vector<edge> v;
        for (int i= 0; i< n- 1; i++) {
            for (int j= i+ 1; j< n; j++) {
                v.push_back(edge(i, j, dist(p[i][0], p[i][1], p[j][0], p[j][1])));
            }
        }
        sort(begin(v), end(v));
        vector<int> f(n+ 1);
        for (int i= 0; i<= n; i++) f[i]= i;
        function<int(int)> get= [&](int p)-> int{
            if (p== f[p])
                return p;
            return f[p]= get(f[p]);
        };
        for (int i= 0; i< (int)v.size(); i++) {
            int x= v[i].fr, y= v[i].to;
            x= get(x), y= get(y);
            if (x== y) continue;
            else {
                cost+= v[i].co;
                f[y]= x;
            }
        }
        return cost;
    }
};
