#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
const long maxn = 129, maxb = 1025;
long n, b, c[maxn], d[maxn], w[maxb], m;
vector<long> a[maxn];
vector<pair<long, long> > path;
stack<long> st1, st2; // st1为上升栈, st2为下降栈

long suit(long i) {
    while (!st1.empty() && st1.top() > i) {
        st2.push(st1.top());
        st1.pop();
        path.emplace_back(2, 3);
    }
    while (!st2.empty() && st2.top() < i) {
        st1.push(st2.top());
        st2.pop();
        path.emplace_back(3, 2);
    }
}

// 第二/三个为S，其余为B
void solve() {
    // 把栈中所有数字集中到第一个
    queue<long> qu;
    for (long j : a[0]) qu.push(j);
    reverse(a[1].begin(), a[1].end());
    reverse(a[2].begin(), a[2].end());
    for (int i = 1; i <= 2; i++) {
        for (long j: a[i]) {
            path.emplace_back(i + 1, 1);
            qu.push(j);
        }
    }
    while (!qu.empty()) {
        long x = qu.front();
        qu.pop();
        suit(x);
        st1.push(x);
        path.emplace_back(1, 2);
    }
//    cout<<"here"<<" "<<path.size()<<endl;
    for (int i = 3; i < n; i++) {
        for (long j: a[i]) {
            suit(j);
            st1.push(j);
            path.emplace_back(i + 1, 2);
        }
    }
    suit(maxb);
}

int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < b; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        cin >> m;
        a[i] = vector<long>(m);
        for (long &j: a[i]) cin >> j;
    }
    // 第二/三个为S，其余为B
    string str(n, 'B');
    str[1] = str[2] = 'S';
    cout << str << endl;
    solve();
    cout << path.size() << endl;
    for (auto &p: path) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
