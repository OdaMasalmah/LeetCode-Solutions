class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& per, vector<vector<int>>& p) {
        int answer= 0;
        auto ck= [&](int a, int b, int x, int y)-> bool{
            for (int i= 0; i< per[a].size(); i++) {
                if (per[a][i]== b) return false;
                if (per[a][i]== x) break;        
            }
            for (int i= 0; i< per[x].size(); i++) {
                if (per[x][i]== y) return false;
                if (per[x][i]== a) return true;
            }
            return false;
        };
        vector<int> vis(n+ 1, 0);
        int m= p.size();
        for (int i= 0; i< m; i++) {
            for (int j= 0; j< m; j++) {
                if (i== j) continue;
                if (!vis[p[i][0]]&& (ck(p[i][0], p[i][1], p[j][0], p[j][1])|| ck(p[i][0], p[i][1], p[j][1], p[j][0]))) {
                    answer+= 1;
                    vis[p[i][0]]= 1;
                }
                if (!vis[p[i][1]]&& (ck(p[i][1], p[i][0], p[j][0], p[j][1])|| ck(p[i][1], p[i][0], p[j][1], p[j][0]))){
                    answer+= 1;
                    vis[p[i][1]]= 1;
                }
            }
        }
        return answer;
    }
};
