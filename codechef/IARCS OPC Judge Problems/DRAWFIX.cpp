#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> cal(map<int, vector<int> >& m, vector<int>& vec) {
    int n = vec.size();
    vector<int> res(n, 0);
    int win = 0;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++) {
        auto it = m.upper_bound(vec[i]);
        if(it==m.end()) continue;
        res[it->second.back()] = i+1;
        it->second.pop_back();
        if(it->second.empty()) m.erase(it);
        win++;
        vis[i] = true;
    }
    int i = 0;
    for(auto& it : m) {
        for(int j : it.second) {
            while(vis[i]) i++;
            res[j] = i+1;
            vis[i++] = true;
        }
    }
    res.insert(res.begin(), win);
    return res;
}
int main(){
    int n; cin>>n;
    map<int, vector<int> > m;
    int num;
    for(int i=0;i<n;i++) {
        cin>>num; m[num].push_back(i);
    }
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    auto res = cal(m, vec);
    for(int i: res) cout<<i<<endl;
    return 0;
}