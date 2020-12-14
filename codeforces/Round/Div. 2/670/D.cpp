#include <iostream>

using namespace std;
const long maxn = 100001;
long long n, q, a[maxn], d[maxn], l, r, x;

struct Node {
    long l, r, sum;

    Node(long ll, long rr, long s) {
        l = ll, r = rr, sum = s;
    }
};

Node *seg[maxn * 4];

void build(long v, long l, long r) {
    if (l == r) {
        seg[v] = new Node(l, r, d[l]);
        return;
    }
    long m = (l + r) >> 1;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    seg[v] = new Node(l, r, seg[v * 2]->sum + seg[v * 2 + 1]->sum);
}

void update(long v, long l, long r, long pos) {
    if (l == r) {
        seg[v]->sum = d[l];
        return;
    }
    long m = (l + r) >> 1;
    if (pos <= m) update(v * 2, l, m, pos);
    else if (pos > m) update(v * 2 + 1, m + 1, r, pos);
    seg[v]->sum = seg[v * 2]->sum + seg[v * 2 + 1]->sum;
}

long query(long v, long l, long r) {
    if (l > r) return maxn;
    if (seg[v]->l == l && seg[v]->r == r) {
        return seg[v]->sum;
    }
    long m = (seg[v]->l + seg[v]->r) >> 1;
    if (r <= m) return query(v * 2, l, r);
    if (l > m) return query(v * 2 + 1, l, r);
    return min(query(v * 2, l, m), query(v * 2 + 1, m + 1, r));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    d[0] = a[0];
    for (int i = 1; i < n; i++) {
        d[i] = max(0LL, a[i] - a[i - 1]);
    }
    build(1, 0, n - 1);
    cout << (query(1, 0, n - 1) + 1) / 2 << endl;
    cin >> q;
    while (q--) {
        cin >> l >> r >> x;
        d[l - 1] += x;
        if (l > 1 && d[l - 1] < 0) d[l - 1] = 0;
        update(1, 0, n - 1, l - 1);
        if (r < n) {
            d[r] = max(0LL, d[r] - x);
            update(1, 0, n - 1, r);
        }
//        for (int i = 0; i < n; i++) cout << d[i] << " ";
//        cout << endl;
        cout << (query(1, 0, n - 1) + 1) / 2 << endl;
    }
    return 0;
}
