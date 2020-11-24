#include <iostream>
using namespace std;

int main(){
    long long t, n, num;
    cin>>t;
    while(t--) {
        cin>>n;
        long long sum = 0, ma = 0;
        for(int i=0;i<n;i++) {
            cin>>num;
            sum += num;
            ma = max(ma, num);
        }
        long long d = ma * (n-1);
        if (d < sum) {
            long long k = sum - d;
            k /= n - 1;
            d += k * (n-1);
            if(d < sum) d += n-1;
        }
        cout<<(d-sum)<<endl;
    }
    return 0;
}