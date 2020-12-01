#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
const long maxn = 1e5 + 1;
long n, data[maxn], mex[maxn], seg[4*maxn];

void update(int v, int l, int r, int pos, int val) {
    if(l==r) {seg[v] = val; return;}
    int mid = (l+r)>>1;
    if(pos <= mid) update(v*2, l, mid, pos, val);
    else update(v*2+1, mid+1, r, pos, val);
    seg[v] = min(seg[v*2], seg[v*2+1]);
}

long query(int v, int l, int r, int L, int R) {
    if(R<l || L>r) return INT_MAX;
    if(L<=l && R>=r) return seg[v];
    int mid = (l+r)>>1;
    return min(query(v*2, l, mid, L, R), query(v*2+1, mid+1, r, L, R));
}

int main() {
    cin >> n;
    bool missOne = true;
    for(int i=1;i<=n;i++) {
        cin>>data[i];
        if(data[i]!=1) missOne = false;
    }
    if(missOne) {
        cout<<1<<endl;
        return 0;
    }
    mex[1] = 1;
    for(int i=1;i<=n;i++) {
        if(data[i]==1) {
            update(1, 1, n+1, data[i], i); continue;
        }
        if(query(1, 1, n+1, 1, data[i]-1) > query(1, 1, n+1, data[i], data[i])) mex[data[i]] = 1;
        update(1, 1, n+1, data[i], i);
    }
    for(int i=2;i<=n+1;i++) {
        if(query(1, 1, n+1, 1, i-1) > query(1, 1, n+1, i, i)) mex[i] = 1;
    }
    for(int i=1;i<=n+2;i++) if(mex[i]==0) {
        cout<<i<<endl; break;
    }

    return 0;
}
