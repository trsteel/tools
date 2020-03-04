#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
using namespace std;

long mod = 2*(1e9) + 100;

void inc(unordered_map<long, int>& m, long i, int delta) {
    for(i+=mod/2; i<mod; i |= i+1) m[i]+=delta;
}

int sum(unordered_map<long, int>& m, long i) {
    int ans = 0;
    for(i+=mod/2; i>=0; i=(i&(i+1))-1) ans+=m[i];
    return ans;
}

long cal(vector<pair<int , int> >& segs) {
    sort(segs.begin(), segs.end());
    long pre = mod, ans = 0;
    unordered_map<long, int> m;
    for(int i=segs.size()-1; i>=0; i--) {
        int l = segs[i].first, r = segs[i].second;
        int f = sum(m, r);
        if (l != pre) {
            ans += f++;
            inc(m, l + 1 , 1);
            inc(m, r + 1, -1);
        } else ans += f-1;
        inc(m, r , -f);
        inc(m, r + 1 , f);
        pre = l;
    }
    return ans + segs.size() + 1;
}

int main(){
    int t, n; cin>>t;
    while(t--) {
        cin>>n;
        vector<pair<int , int> > segs(n);
        for(int i=0;i<n;i++) scanf("%d%d", &(segs[i].first), &(segs[i].second));
        cout<<cal(segs)<<endl;
    }
    return 0;
}