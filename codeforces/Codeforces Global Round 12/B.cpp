#include <iostream>

using namespace std;

long t, n, k, x[101], y[101];

bool cal() {
    for(int i=0;i<n;i++) {
        bool valid = true;
        for(int j=0;j<n;j++) {
            if(abs(x[i]-x[j])+abs(y[i]-y[j]) > k) {
                valid = false; break;
            }
        }
        if(valid) return true;
    }
    return false;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>x[i]>>y[i];
        cout<<(cal() ? 1 : -1)<<endl;
    }
    return 0;
}