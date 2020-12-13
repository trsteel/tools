#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long n, a[100001], b[100001];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int idx = 0;
    for (int i = 1; i < n; i += 2) b[i] = a[idx++];
    for (int i = 0; i < n; i += 2) b[i] = a[idx++];
    int res = 0;
    for (int i = 1; i < n - 1; i++) if (b[i] < b[i + 1] && b[i] < b[i - 1]) res++;
    cout << res << endl;
    for (int i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
    return 0;
}
