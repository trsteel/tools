#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int limit = 50 * maxn;
int h[maxn], link[maxn], idx[maxn], ptr=0;

struct LazySegTree {
    struct node {
        int l=0, r=0, data=0, lazy=0;
    };
    vector<node> tree;
    LazySegTree(int n) {
        tree.resize(n);
    }
    void addLeft(int i) {
        tree[++ptr] = tree[tree[i].l];
        tree[i].l = ptr;
    }
    void addRight(int i) {
        tree[++ptr] = tree[tree[i].r];
        tree[i].r = ptr;
    }
    void update(int i, int L, int R, int l, int r, int val) {
        if(l==L && r==R) {
            tree[i].lazy += val; return;
        }
        int M = (L+R)>>1;
        if(r <= M) {
            addLeft(i);
            update(tree[i].l, L, M, l, r, val);
        } else if(l > M) {
            addRight(i);
            update(tree[i].r, M+1, R, l, r, val);
        } else {
            addLeft(i), addRight(i);
            update(tree[i].l, L, M, l, M, val);
            update(tree[i].r, M+1, R, M+1, r, val);
        }
        tree[i].data = max(tree[tree[i].l].data+tree[tree[i].l].lazy, tree[tree[i].r].data+tree[tree[i].r].lazy);
    }

    int query(int i, int L, int R, int l, int r) {
        if(l==L && r==R) return tree[i].data + tree[i].lazy;
        int M = (L+R)>>1, res;
        if(r <= M) res = query(tree[i].l, L, M, l, r);
        else if(l > M) res = query(tree[i].r, M+1, R, l, r);
        else res = max(query(tree[i].l, L, M, l, M), query(tree[i].r, M+1, R, M+1, r));
        return res + tree[i].lazy;
    }
};

int main() {
    long n, q, s, x, y, l, r, last=0;
    scanf("%ld %ld %ld", &n, &q, &s);
    h[0] = limit;
    for(long i=1;i<=n;i++) {
        scanf("%d", &(h[i]));
        int ans = i - 1;
        while(h[ans] < h[i]) ans = link[ans];
        link[i] = ans;
    }
    LazySegTree seg(limit);
    for(long i=1;i<=n;i++) {
        idx[i] = ++ptr;
        seg.tree[idx[i]] = seg.tree[idx[i-1]];
        seg.update(idx[i], 1, n, link[i]+1, i, 1);
    }
    while(q--) {
        scanf("%ld %ld", &x, &y);
        l = (x + s*last - 1)%n + 1;
        r = (y + s*last - 1)%n + 1;
        if(l > r) swap(l, r);
        last = seg.query(idx[r], 1, n, l, r);
        printf("%ld\n", last);
    }
    return 0;
}
