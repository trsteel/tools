class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& g) {
        for(int i=0;i<g.size();i++) {
            for(int j=0;j<g[i].size();j++) {
                if(g[i][j]==1) {
                    int ans = 0;
                    if(i>0) ans+=backstrap(g, i-1,j);
                    if(i<g.size()-1) ans+=backstrap(g, i+1,j);
                    if(j>0) ans+=backstrap(g, i, j-1);
                    if(j<g[i].size()-1) ans+=backstrap(g, i, j+1);
                    return ans;
                }
            }
        }
        return 0;
    }
    int backstrap(vector<vector<int>>& g, int x, int y) {
        if(g[x][y]==2) return is_valid(g)?1:0;
        if(g[x][y]==1 || g[x][y]==-1) return 0;
        int ans = 0;
        g[x][y] = -1;
        if(x>0) ans += backstrap(g, x-1, y);
        if(x<g.size()-1) ans += backstrap(g, x+1, y);
        if(y>0) ans += backstrap(g, x, y-1);
        if(y<g[x].size()-1) ans += backstrap(g, x, y+1);
        g[x][y] = 0;
        return ans;
    }
    bool is_valid(vector<vector<int>>& g) {
        int start = 0, end = 0;
        for(int i=0;i<g.size();i++) {
            for(int j=0;j<g[i].size();j++) {
                switch(g[i][j]) {
                case 0: return false;
                case 1:
                    if(start++>0) return false;
                    break;
                case 2:
                    if(end++>0) return false;
                    break;
                default: break;
                }
            }
        }
        return start==1 && end==1;
    }
};