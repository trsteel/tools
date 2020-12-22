/**
 * 约瑟夫问题：https://oi-wiki.org/misc/josephus/
 **/
#include <iostream>

using namespace std;

long long josephus(long long n, long long k) {
    if (n == 1 || k == 1) return n - 1;
    if (k > n) return (josephus(n - 1, k) + k) % n;
    long long res = josephus(n - n / k, k) - n % k;
    return res + (res < 0 ? n : res / (k - 1));
}

int main() {
    cout << josephus(1000, 1000) << endl;
    return 0;
}
