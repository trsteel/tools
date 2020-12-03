#include <iostream>
#include <unordered_map>
using namespace std;

long long n, mod = 1e9 + 7;

long long q_pow(long long base, long long n) {
    long long res = 1;
    while(n > 0) {
        if(n&1) res = res*base%mod;
        n >>= 1, base = base*base%mod;
    }
    return res;
}

int main() {

    string s;
    cin>>n>>s;
    unordered_map<char, long long> um, left;
    for(char c: s) um[c]++;
    long long res = 0, cnt = um['?'];
    for(char c: s) {
        um[c]--;
        if(c=='b' || c=='?') {
            long long tmp = cnt + (c=='?'?-1:0);
            res = (res+left['a']*um['c']*q_pow(3, tmp))%mod;
            res = (res+left['?']*um['c']*q_pow(3, tmp-1))%mod;
            res = (res+left['a']*um['?']*q_pow(3, tmp-1))%mod;
            res = (res+left['?']*um['?']*q_pow(3, tmp-2))%mod;
        }
        left[c]++;
    }
//    cout<<res<<" "<<cnt<<endl;
    cout<<res<<endl;
    return 0;
}
