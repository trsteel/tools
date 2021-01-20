#include <iostream>

using namespace std;
long long t, n, a[51], b[51];

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        long long mina = 1e9, minb = 1e9;
        for(int i=0;i<n;i++) {
            cin>>a[i]; mina = min(mina, a[i]);
        }
        for(int i=0;i<n;i++) {
            cin>>b[i]; minb = min(minb, b[i]);
        }
        long long res = 0;
        for(int i=0;i<n;i++) {
            res += max(a[i]-mina, b[i]-minb);
        }
        cout<<res<<endl;
    }
    return 0;
}