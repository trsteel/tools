#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int s, int p, int k, vector<int>& ans, vector<int>& res) {
    if(k==0) {
        if(s==0 && p==1) res = ans;
        return;
    }
    int end = min(p, s);
    for(int i=1;i<=end;i++) {
        if(p%i>0) continue;
        ans.push_back(i);
        dfs(s-i, p/i, k-1, ans, res);
        ans.pop_back();
        if(!res.empty()) return;
    }
}

vector<int> cal(int s, int p, int k) {
    vector<int> ans, res;
    dfs(s, p, k, ans, res);
    return res;
}

int main(){
    int s, p, k;
    cin>>s>>p>>k;
    auto res = cal(s, p, k);
    if(res.empty()) cout<<"NO"<<endl;
    else {
        for(int i: res) cout<<i<<" ";
    }
    return 0;
}