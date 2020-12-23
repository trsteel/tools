#include <iostream>
#include <queue>

using namespace std;

long t, n, a[101];

bool cal() {
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) pq.push(a[i]);
    while (true) {
        int t1 = pq.top();
        pq.pop();
        if (pq.empty()) return true;
        int t2 = pq.top();
        pq.pop();
        if (t1 > 1) pq.push(t1 - 1);
        if (t2 > 1) pq.push(t2 - 1);
        if (pq.empty()) return false;
    }
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (cal() ? "T" : "HL") << endl;
    }
    return 0;
}
