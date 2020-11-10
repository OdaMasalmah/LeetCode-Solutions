class Solution {
const int mod= 1e9+ 7;
typedef long long ll;
public:
    int maxProfit(vector<int>& ar, int orders) {
        int lo= 0, hi= 1e9+ 1;
        auto can= [&](ll md)->bool{
            ll sm= 0;
            for (auto x: ar) {
                sm+= max(0LL, x- md+ 1);
            }
            if (sm<= orders) return 1;
            return 0;
        };
        auto add= [&](ll &sm, ll a, ll b) {
            ll ad= ((a* (a+ 1))/ 2);
            ad -= (b* (b+ 1)/ 2);
            ad= (ad+ mod)% mod;
            sm= (sm% mod+ ad% mod)% mod;
        };
        while (hi- lo> 1) {
            int md= (hi+ lo)/ 2;
            if (can(md)) {
                hi= md;
            }else lo= md;
        }
        ll sm= 0;
        priority_queue<int> q;
        for (auto &y: ar) {
            if (y>= hi) {
                add(sm, y, hi- 1);
                orders-= (y- hi+ 1);
            }
            y= min(y, hi- 1);
            q.push(y);
        }
        while (orders>= 1) {
            ll x= q.top();
            q.pop();
            sm= (sm% mod+ x% mod)% mod;
            q.push(x- 1);
            orders-= 1;
        }
        return (int)(sm% mod);
    }
};
