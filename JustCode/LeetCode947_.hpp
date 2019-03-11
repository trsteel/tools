class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, unordered_set<int>> xs, ys;
        for(auto& it: stones){
            xs[it[0]].insert(it[1]);
            ys[it[1]].insert(it[0]);
        } 
        int ans = 0;
        while(!xs.empty()) {
            for(auto it: xs) {
                dfs_x(xs, ys, it.first);
                ans++;
                break;
            }
        }
        while(!ys.empty()) {
            for(auto it: ys) {
                dfs_y(xs, ys, it.first);
                ans++;
                break;
            }
        }
        return stones.size()-ans;
    }
    void dfs_x(unordered_map<int, unordered_set<int>>& xs, unordered_map<int, unordered_set<int>>& ys, int x) {
        if(xs.find(x) == xs.end()) return;
        for(auto& it: xs[x]) {
            xs[x].erase(it);
            if(xs[x].empty()) xs.erase(x);
            dfs_y(xs, ys, it);
        }
    } 
    void dfs_y(unordered_map<int, unordered_set<int>>& xs, unordered_map<int, unordered_set<int>>& ys, int y) {
        if(ys.find(y) == ys.end()) return;
        for(auto& it: ys[y]) {
            ys[y].erase(it);
            if(ys[y].empty()) ys.erase(y);
            dfs_x(xs, ys, it);
        }
    } 
};