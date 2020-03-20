#include <iostream>
#include <vector>
#include <set>
using namespace std;

const long maxn = 300001;

struct node {
    long long sum, mssm;
} segs[maxn*4];

node merge(node& a, node& b) {
    node res;
    res.sum = a.sum+b.sum;
    res.mssm = max(a.mssm+b.sum, b.mssm);
    return res;
}

void update(int v, int i, int j, int idx, int val) {
    if(i==j) {
        segs[v].sum += val;
        segs[v].mssm += val;
        return;
    }
    int mid = (i+j)>>1;
    if(idx<=mid) update(2*v, i, mid, idx, val);
    else update(2*v+1, mid+1, j, idx, val);
    segs[v] = merge(segs[2*v], segs[2*v+1]);
}

int main(){
    long n, q; cin>>n;
    vector<long> p(n+1), idx(n+1);
    for(int i=1;i<=n;i++) {
        cin>>p[i]; idx[p[i]] = i;
    }
    int ans = n;
    update(1, 1, n, idx[ans], 1);
    for(int i = 1; i <= n; i++){
		while(segs[1].mssm<=0){
			ans--; update(1,1,n,idx[ans],1);
		}
		cout<<ans<<" ";
        cin>>q;
		update(1,1,n,q,-1);
	}
    return 0;
}