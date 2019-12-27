#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > cal(vector<int>& vec) {
    int n = vec.size();
    vector<bool> vis(n, false);
    vector<vector<int> > res;
    while(true) {
        int start = -1;
        for(int i=0;i<n;i++) {
            if(!vis[i]) {start = i; break; }
        }
        if(start == -1) break;
        vector<bool> tmp(n, false);
        vector<int> ans;
        while(!tmp[start]) {
            tmp[start] = true;
            vis[start] = true;
            ans.push_back(start+1);
            start = vec[start]-1;
        }
        ans.push_back(start+1);
        res.push_back(ans);
    }
    return res;
} 

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    auto res = cal(vec);
    cout<<res.size()<<endl;
    for(auto& v: res) {
        for(int i: v) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}