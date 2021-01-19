#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <unordered_set>
using namespace std;
long t, n, a, pre[100001];
map<long, long> cnt;
map<long, unordered_set<long> > freq;

bool check(map<long, unordered_set<long> > m, int x) {
    memset(pre, -1, sizeof(pre));
    // for(auto& it: m) {
    //     cout<<it.first<<":";
    //     for(long d: it.second) cout<<d<<" ";
    //     cout<<endl;
    // }
    for(int i=0;i<n;i++) {
        bool find = false;
        for(auto it=m.end(); it!=m.begin();) {
            --it;
            long c = it->first, hit = -1;
            for(long d: it->second) {
                if(pre[d]==-1 || pre[d]+x<i) {
                    hit = d; break;
                }
            }
            if(hit != -1) {
                find = true;
                m[c].erase(hit);
                if(c>1) m[c-1].insert(hit);
                // cout<<x<<" "<<hit<<" "<<pre[hit]<<" "<<i<<endl;
                pre[hit] = i;
                break;
            }
        }
        if(!find) return false;
    }
    return true;
}

long cal() {
    long l = 0, r = n, res = 0;
    while(l<=r) {
        long mid = (l+r)>>1;
        if(check(freq, mid)) {
            res = max(res, mid);
            l = mid+1;
        } else r = mid-1;
    }
    return res;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        cnt.clear();
        for(int i=0;i<n;i++) {
            cin>>a; cnt[a]++;
        }
        freq.clear();
        for (auto& it: cnt) {
            freq[it.second].insert(it.first);
        }
        cout<<cal()<<endl;
    }
    return 0;
}