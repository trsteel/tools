class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int changes = 0, res = 0;
        do {
            changes = refreshOranges(grid);
            if(changes>0) res++;
            // cout<<res<<" "<<changed<<endl;
        } while(changes!=0); // 没有状态更新就终止
        return isAllRotten(grid) ? res : -1;
    }

    // 一分钟后的状态
    int refreshOranges(vector<vector<int>>& g1) {
        vector<vector<int>> g2(g1.size(), vector<int>(g1[0].size(), 0));
        // 记录有状态更新的个数
        int res = 0;
        for(int i=0;i<g1.size();i++) {
            for(int j=0;j<g1[i].size();j++) {
                g2[i][j] = judgStatus(g1, i, j);
                if(g2[i][j]!=g1[i][j]) res++;
            }
        }
        g1 = g2;
        return res;
    }
    
    // 判断每个位置下一分钟的状态
    int judgStatus(vector<vector<int>>& g, int i, int j) {
        if(g[i][j]!=1) return g[i][j];
        if(i>0&&g[i-1][j]==2) return 2;
        if(i<g.size()-1 && g[i+1][j]==2) return 2;
        if(j>0&&g[i][j-1]==2) return 2;
        if(j<g[i].size()-1 && g[i][j+1]==2) return 2;
        return g[i][j];
    }

    // 是否所有都是坏的
    bool isAllRotten(vector<vector<int>>& g) {
        for(auto &v: g) for(auto &v1: v) if(v1==1) return false;
        return true;
    }
};