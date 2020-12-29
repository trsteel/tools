#include <stdio.h>
#include <vector>
using namespace std;
const long maxn = 1e6 + 1;
long n, q, s, w, l, r;
vector<long> a;
vector<long> xors;

struct Node {
    long l, r, val;

    Node(long ll, long rr, long v) {
        l = ll, r = rr, val = v;
    }
};

Node* seg[maxn*4];

void build(long v, long l, long r) {
    if (l == r) {
        seg[v] = new Node(l, r, a[l]^s);
        return;
    }
    long m = (l + r) >> 1;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    seg[v] = new Node(l, r, max(seg[v*2]->val, seg[v*2+1]->val));
}

long query(long v, long l, long r) {
    if (l > r) return -1;
    if (seg[v]->l == l && seg[v]->r == r) {
        return seg[v]->val;
    }
    long m = (seg[v]->l + seg[v]->r) >> 1;
    if (r <= m) return query(v * 2, l, r);
    if (l > m) return query(v * 2 + 1, l, r);
    return max(query(v * 2, l, m), query(v * 2 + 1, m + 1, r));
}

long cal() {
    // 查找最大的k
    long k = query(1, l, r);
    // 计算异或值S
    long S = xors[r+1]^xors[l]^s^k;
    // cout<<l<<" "<<r<<" "<<S<<endl;
    // 找最大的S^W
    long res = 0, ans = 0;
    for(int i=30;i>=0;i--) {
        long mask = 1<<i;
        if(S&mask) {
            res |= mask;
        } else {
            if(ans + mask <= w) {
                ans |= mask;
                res |= mask;
            }
        }
    }
    return res;
}

int main(){
    scanf("%ld %ld %ld %ld", &n, &q, &s, &w);
    a = vector<long>(n, 0);
    xors = vector<long>(n+1, 0);
    for(int i=0;i<n;i++) {
        scanf("%ld", &(a[i]));
        xors[i+1] = xors[i]^a[i];
    }
    build(1, 0, n-1);
    while(q--) {
        scanf("%ld %ld", &l, &r);
        l--, r--;
        printf("%ld\n", cal());
    }
    return 0;
}