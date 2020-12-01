#include <iostream>
using namespace std;

int main(){
    int t, n, m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        if(n > m) swap(n, m);
        int ans = m + n;
        if(m-n>1) ans += m-n-1;
        cout<<ans<<endl;
    }
    return 0;
}