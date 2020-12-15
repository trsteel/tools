#include <iostream>

using namespace std;
const long long maxn = 100001;
long long n, q, a[maxn], d[maxn], l, r, x;

struct Node {
    long long l, r, sum;

    Node(long long ll, long long rr, long long s) {
        l = ll, r = rr, sum = s;
    }
};

Node *seg[maxn * 4];

void build(long long v, long long l, long long r) {
    if (l == r) {
        long long x = d[l];
        if(l > 0 && d[l] < 0) x = 0; 
        seg[v] = new Node(l, r, x);
        return;
    }
    long long m = (l + r) >> 1;
    build(v * 2, l, m);
    build(v * 2 + 1, m + 1, r);
    seg[v] = new Node(l, r, seg[v * 2]->sum + seg[v * 2 + 1]->sum);
}

void update(long long v, long long l, long long r, long long pos) {
    if (l == r) {
        long long x = d[l];
        if(l > 0 && d[l] < 0) x = 0; 
        seg[v]->sum = x;
        return;
    }
    long long m = (l + r) >> 1;
    if (pos <= m) update(v * 2, l, m, pos);
    else if (pos > m) update(v * 2 + 1, m + 1, r, pos);
    seg[v]->sum = seg[v * 2]->sum + seg[v * 2 + 1]->sum;
}

long long query(long long v, long long l, long long r) {
    if (l > r) return maxn;
    if (seg[v]->l == l && seg[v]->r == r) {
        return seg[v]->sum;
    }
    long long m = (seg[v]->l + seg[v]->r) >> 1;
    if (r <= m) return query(v * 2, l, r);
    if (l > m) return query(v * 2 + 1, l, r);
    return min(query(v * 2, l, m), query(v * 2 + 1, m + 1, r));
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    d[0] = a[0];
    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
    }
    build(1, 0, n - 1);
    long long ans = query(1, 0, n - 1);
    if(ans%2) ans++;
    cout << ans / 2 << endl;
    cin >> q;
    while (q--) {
        cin >> l >> r >> x;
        d[l - 1] += x;
        update(1, 0, n - 1, l - 1);
        if (r < n) {
            d[r] -= x;
            update(1, 0, n - 1, r);
        }
//        for (int i = 0; i < n; i++) cout << d[i] << " ";
//        cout << endl;
        ans = query(1, 0, n - 1);
        if(ans%2) ans++;
        cout << ans / 2 << endl;
    }
    return 0;
}
