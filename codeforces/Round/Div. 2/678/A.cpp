#include <iostream>

using namespace std;

int main() {
    long t, n, m, x;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>x; m -= x;
        }
        cout<<(m==0?"YES":"NO")<<endl;
    }
    return 0;
}
