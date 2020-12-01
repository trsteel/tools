#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long n, k;

int main() {
    cin >> n >> k;
    vector<long> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.rbegin(), c.rend());
    vector<long long> vec;
    long long ans = 0, sum = 0, pos = n;
    for (int i = 0; i < n; i++) {
        ans += sum;
        sum += c[i];
        if (sum < 0) {
            vec.push_back(sum);
            pos = i + 1; break;
        }
    }
    for (long i = pos; i < n; i++) vec.push_back(c[i]);
    sort(vec.begin(), vec.end());
    for (long i = 0; i < vec.size(); i++) {
        ans += vec[i] * (i / (k+1));
    }
    cout<<ans<<endl;
    return 0;
}