#include <iostream>
#include <unordered_set>

using namespace std;

void find(unordered_set<long> &res, long n) {
    for (long i = 0; i <= n; i++) {
        res.insert(n - 2 * i);
    }
}

long cal(long n) {
    if (n == 1 || n == 2) return 4;
    long a = n / 2, b = n - n / 2;
    unordered_set<long> x, y;
    find(x, a), find(y, b);
    unordered_set<long> us;
    for(auto i: x) for(auto j: y) {
        us.insert((i+1001) * 1001 + j);
        us.insert((j+1001) * 1001 + i);
    }
    return us.size();
}

int main() {
    long n;
    cin >> n;
    cout << cal(n) << endl;
    return 0;
}
