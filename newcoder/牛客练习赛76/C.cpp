#include <stdio.h>

using namespace std;
const long mod = 1e9 + 7;
long t, n, m;

long long q_pow(long long base, long long n) {
    long long res = 1;
    while(n > 0) {
        if(n&1) res = res*base%mod;
        n >>= 1, base = base*base%mod;
    }
    return res;
}

long cal() {
    if(m==1) return 0;
    long res = m*(m-1)/2*3%mod*(n-1)%mod;
    res = res*q_pow(m, n-2)%mod;
    return res;
}

int main(){
    scanf("%ld", &t);
    while(t--) {
        scanf("%ld %ld", &n, &m);
        printf("%ld\n", cal());
    }
    return 0;
}