#include<bits/stdc++.h>

using namespace std;

int cal(vector<pair<int, int> >& vec, int n) {
    int res = n, start=0, end=0;
    for(auto& p: vec) {
        start += p.first;
        end += p.second;
        if(end>0 && start<n) {
            res = min(res, start - end);
            if(res==0) return 0;
        }
    }
    return res == n ? -1 : res;
}

int cal(map<int, pair<int, int>>& m, int n) {
    int res = n, start=0, end=0;
    for(auto& it: m) {
        start += it.second.first;
        end += it.second.second;
        if(end>0 && start<n) {
            res = min(res, start - end);
            if(res==0) return 0;
        }
    }
    return res == n ? -1 : res;
}

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        unordered_map<int, pair<int, int>> um;
        int s, e, mi;
        for(int i=0;i<n;i++) {
            cin>>s>>e;
            um[s].first++;
            um[e].second++;
            mi = max(mi, e);
        }
        if(mi<=1000000) {
            vector<pair<int, int>> vec(mi+1, {0, 0});
            for(auto& it: um) {
                vec[it.first].first+=it.second.first;
                vec[it.first].second+=it.second.second;
            }
            cout<<cal(vec, n)<<endl;
        } else {
            map<int, pair<int, int>> m(um.begin(), um.end());
            cout<<cal(m, n)<<endl;
        }
    }
    return 0;
}