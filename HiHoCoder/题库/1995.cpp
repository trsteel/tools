#include <stdio.h>
#include <iostream>
#include <vector>
#include<limits.h>
#include <unordered_map>
using namespace std;

int main() {
    int n, q;
    cin>>n>>q;
    vector<int> parent(n+1, -1);
    vector<int> weight(n+1, -1);
    int p, w;
    for(int i=0;i<n;i++) {
        cin>>p>>w;
        if(p==0) w = INT_MAX;
        parent[i+1] = p;
        weight[i+1] = w;
    }
    vector<unordered_map<int,int>> m(n+1);
    for(int i=1;i<=n;i++) {
        int x = i, w = INT_MAX;
        while(x>0 && parent[x]>=0) {
            w = min(w, weight[x]);
            m[i][parent[x]] = w;
            x = parent[x];
        }
    }
    int u, v;
    while(q--) {
        cin>>u>>v;
        if(u==v){cout<<0<<endl; continue;}
        if(m[u].find(v)!=m[u].end()) {
            cout<<m[u][v]<<endl; continue;
        }
        if(m[v].find(u)!=m[v].end()) {
            cout<<m[v][u]<<endl; continue;
        }
        for(auto& it: m[u]) {
            if(m[v].find(it.first)==m[v].end()) continue;
            cout<<min(it.second, m[v][it.first])<<endl;
            break;
        }
    }
    return 0;
}