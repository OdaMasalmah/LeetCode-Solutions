class Solution {
    
struct Cell{
    int x, y, c;
    Cell(int a, int b, int co) {
        x= a;
        y= b; 
        c= co;
    }
    Cell(){}
    bool operator<(const Cell &p)const {
        return p.c< c;
    }
};
    
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int r= h.size(), c= h[0].size();
        const int inf= 1e9;
        int dx[]= {1, -1, 0, 0}, dy[]= {0, 0, 1, -1};
        vector<vector<int>> dis(r+ 1, vector<int> (c+ 1, inf));
        vector<vector<bool>> vis(r+ 1, vector<bool> (c+ 1, 0));
        priority_queue<Cell> pq;
        pq.push(Cell(0, 0, 0));
        dis[0][0]= 0;
        
        while (pq.size()) {
            Cell pik= pq.top();
            pq.pop();
            if (pik.x== r- 1&& pik.y== c- 1) 
                return pik.c;
            if (dis[pik.x][pik.y]< pik.c) 
                continue;
            vis[pik.x][pik.y]= 1;
            for (int i= 0; i< 4; i++) {
                int tox= pik.x+ dx[i], toy= pik.y+ dy[i];
                if (tox>= 0&& tox< r&& toy>= 0&& toy< c&& !vis[tox][toy]) {
                    pq.push(Cell(tox, toy, max(pik.c, abs(h[tox][toy]- h[pik.x][pik.y]))));
                    dis[tox][toy]= max(pik.c, abs(h[tox][toy]- h[pik.x][pik.y]));
                }
            }
        }
        return 0;
    }
};
