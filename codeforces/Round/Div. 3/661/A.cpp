#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long t, n, a[51];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        bool res = true;
        for(int i=1;i<n;i++) {
            if(a[i]>a[i-1]+1) {
                res = false; break;
            }
        }
        cout<<(res?"YES":"NO")<<endl;
    }
    return 0;
}