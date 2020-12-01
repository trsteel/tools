#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    long long t, p, q;
    cin>>t;
    while(t--) {
        cin>>p>>q;
        long long res = 0;
        for(long long i=1;i*i<=q;i++) if(q%i==0) {
            if(i != 1) {
                long long tmp = p;
                while(tmp % q==0) tmp /= i;
                res = max(res, tmp);
            }
            long long tmp = p;
            while(tmp%q==0) tmp /= q/i;
            res = max(res, tmp);
        }
        cout<<res<<endl;
    }
    return 0;
}