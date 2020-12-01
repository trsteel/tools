#include <iostream>

using namespace std;

int main() {
    long t, n, a[101];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i+=2) {
            cout<<a[i+1]<<" "<<(-a[i])<<" ";
        }
        cout<<endl;
    }
    return 0;
}