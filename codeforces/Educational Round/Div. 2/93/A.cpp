#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long t, n, a[50001];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        if(a[0]+a[1] <= a[n-1]) {
            cout<<1<<" "<<2<<" "<<n<<endl;
        } else cout<<-1<<endl;
    }
    return 0;
}