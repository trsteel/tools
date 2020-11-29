#include <iostream>
#include <set>
using namespace std;

const long maxn = 200001;

int high_bit(long x) {
    int res = 0;
    while(x) res++, x>>=1;
    return res;
}

int main(){
    long n, a[maxn];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    long res = 0;
    set<pair<long, long>> us;
    for(long l=0;l<n;l++) {
        long r = l+1, sum = 0, ma = 1L<<(high_bit(a[l]+1));
        while(r+1<n && sum <= ma) {
            sum += a[r++];
            if((a[l]^a[r])==sum) {
                res++, us.insert({l, r});
            }
        }
    }
    for(long r=n-1;r>=0;r--) {
        long l = r-1, sum = 0, ma = 1L<<(high_bit(a[r]+1));
        while(l-1>=0 && sum <= ma) {
            sum += a[l--];
            if((a[l]^a[r])==sum && us.count({l, r})==0) {
                res++, us.insert({l, r});
            }
        }
    }
    cout<<res<<endl;
    return 0;
}