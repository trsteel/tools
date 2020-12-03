#include <iostream>

using namespace std;

int main() {
    long t, n, x;
    cin>>t;
    while(t--) {
        cin>>n>>x;
        if(n <= 2) cout<<1<<endl;
        else cout<<(1+(n-2+x-1)/x)<<endl;
    }
    return 0;
}
