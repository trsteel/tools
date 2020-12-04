#include <iostream>

using namespace std;

int main() {
    long t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        if(2*k<=n) {
            for(int i=1;i<=n;i++) {
                if(k==0 || i%2==1) cout<<-i<<" ";
                else {cout<<i<<" "; k--;}
            }
        } else {
            k = n-k;
            for(int i=1;i<=n;i++) {
                if(k==0 || i%2==1) cout<<i<<" ";
                else {cout<<-i<<" "; k--;}
            }
        }
        cout<<endl;
    }
    return 0;
}
