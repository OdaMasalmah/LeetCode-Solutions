class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<string, int> vis;
        int n= tiles.size(), answer= 0;
        
        auto get= [](int a) {
            int an= 1;
            for (int i= 1; i<= a; i++)
                an*= i;
            return an;
        };
        
        for (int i= 1; i< (1<< n); i++) {
            string str= "";
            for (int j= 0; j< n; j++) if (i& (1<< j)) {
                str+= tiles[j];
            }
            sort(begin(str), end(str));
            
            if (vis.count(str)) continue;
            int f[27]= {};
            
            for (int j= 0; j< str.size(); j++) f[str[j]- 'A']++;
            int ad= get(str.size());
            for (int j= 0; j< 26; j++) ad/= get(f[j]);
            vis[str]= 1;
            answer+= ad;
        }
        return answer;
    }
};
