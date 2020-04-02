#include <iostream>

using namespace std;

int main(){
    long k; cin>>k;
    long ans = 1;
    while(ans<=k) ans<<=1;
    cout<<3<<" "<<2<<endl;
    cout<<(ans+k)<<" "<<k<<endl;
    cout<<ans<<" "<<(ans+k)<<endl;
    cout<<ans<<" "<<k<<endl;
    return 0;
}