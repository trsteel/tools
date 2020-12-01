// https://www.cnblogs.com/xyq0220/p/13881139.html
#include <iostream>

using namespace std;

int main() {
    long long t,a , b, c, d;
    cin>>t;
    while(t--) {
        cin>>a>>b>>c>>d;
        if(a>b*c) {cout<<-1<<endl; continue;}
        long long k = a/(b*d), ans = 0;
        ans = max(ans, (k+1)*a-(1+k)*k/2*b*d);
        k++;
        ans = max(ans, (k+1)*a-(1+k)*k/2*b*d);
        cout<<ans<<endl;
    }
    return 0;
}
