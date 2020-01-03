/**
 * 关键点: 问题转化为求有向图最长路径，需要细致处理判断两个单词相邻的条件
 **/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool search_gt(string& a, int i, char c) {
    while(i<a.size()) {
        if(a[i++]==c) return true;
    }
    return false;
}

bool one_less(string& a, string& b) {
    int m = a.size(), n = b.size();
    int i=0, j=0, d=0;
    while(i<m && j<n) {
        if(a[i]!=b[j]) {
            j++, d++;
            if(d>1) return false;
        } else {
            i++, j++;
        }
    }
    d += n-j+m-i;
    return d==1;
}

bool near(string& a, string& b) {
    int m = a.size(), n = b.size();
    if(abs(m-n)>1) return false;
    if(m < n) return false;
    if(m==n) {
        int diff = 0;
        for(int i=0;i<m;i++) if(a[i]!=b[i]) {
            if(++diff>1 || a[i]>b[i]) return false;
            if(!search_gt(a, i+1, b[i])) return false;
        }
        return diff == 1;
    }
    return one_less(b, a);
}

void dfs(vector<vector<int> >& grid, vector<bool>& vis, int i, int ans, int& res) {
    if(vis[i]) return;
    res = max(res, ans);
    vis[i] = true;
    for(int j : grid[i]) {
        dfs(grid, vis, j, ans+1, res);
    }
    vis[i] = false;
}

int cal(vector<string>& vec) {
    int n = vec.size();
    vector<vector<int> > grid(n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        if(i!=j && near(vec[i], vec[j])) grid[i].push_back(j);
    }
    int res = 0;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++) {
        dfs(grid, vis, i, 0, res);
    }
    return res;
}

int main(){
    int n; cin>>n;
    unordered_set<string> ust;
    string s;
    for(int i=0;i<n;i++) {
        cin>>s; ust.insert(s);
    }
    vector<string> vec(ust.begin(), ust.end());
    cout<<cal(vec)<<endl;
    return 0;
}