#include <iostream>
#include <math.h>
using namespace std;


int main(){
    long long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        long long x = 0, cnt = 0, m = n;
        for(long long i=2;i<=sqrt(n);i++) {
            int ans = 0;
            while(n%i==0) {
                n /= i; ans++;
            }
            if(ans > cnt) {
                x = i, cnt = ans;
            }
        }
        cout<<max(cnt, 1LL)<<endl;
        for(int i=1;i<cnt;i++) {
            cout<<x<<" "; m /= x;
        }
        cout<<m<<endl;
    }
    return 0;
}