#include <iostream>
#include <vector>
using namespace std;

pair<int, int> find(vector<bool>& p, vector<bool>& k) {
    for(int i=1;i<p.size();i++) {
        if(p[i]) continue;
        for(int j=1;j<k.size();j++) {
            if(!k[j]) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int main(){
    long long t, n, m, num; cin>>t;
    while(t--) {
        cin>>n;
        vector<bool> p(n+1, false), k(n+1, false);
        for(int i=1;i<=n;i++) {
            cin>>m;
            while(m--) {
                cin>>num;
                if(!p[i] && !k[num]) {
                    p[i] = k[num] = true;
                }
            }
        }
        auto pp = find(p, k);
        if(pp.first==-1) {
            cout<<"OPTIMAL"<<endl;
        } else {
            cout<<"IMPROVE"<<endl<<pp.first<<" "<<pp.second<<endl;
        }
    }
    return 0;
}