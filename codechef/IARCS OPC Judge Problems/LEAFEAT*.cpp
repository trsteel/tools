/**
 * TLE 没有通过最后一个测试用例
 **/
#include <iostream>
#include <bitset>
#include <vector>
#include <set>
using namespace std;

long long gcd(long long a, long long b) {
    if(a%b==0) return b;
    if(b%a==0) return a;
    return a<b ? gcd(b, a) : gcd(b, a%b);
}

long long lcm(vector<long long>& vec, int n) {
    long long ans = vec[0];
    for(int i=1;i<vec.size();i++) {
        ans = (ans*vec[i])/gcd(ans, vec[i]);
        if(ans >= n) break;
    }
    return ans;
}

int main(){
    long long n, k; cin>>n>>k;
    vector<int> vec(k);
    for(int i=0;i<k;i++) cin>>vec[i];
    long long ans = 1;
    for(int i=1;i<(1<<k);i++) {
        vector<long long> dp;
        for(int j=0;j<k;j++) {
            if(i&(1<<j)) dp.push_back(vec[j]);
        }
        long long lc = lcm(dp, n);
        ans += dp.size()%2==1 ? (n-1)/lc : (1-n)/lc;
    }
    cout<<n-ans<<endl;
    return 0;
}