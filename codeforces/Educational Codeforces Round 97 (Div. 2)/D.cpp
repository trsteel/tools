#include <iostream>

using namespace std;

int main(){
    long t, n, a[200001];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        long d = 0, size = 1, next=0;
        for(int i=1;i<n;i++) {
            next++;
            while(i+1<n&&a[i]<a[i+1]) i++, next++;
            if(--size==0) {
                d++, size = next;
                next = 0;
            }
            // cout<<i<<" "<<d<<" "<<size<<endl;
        }
        if(next > 0) d++;
        cout<<d<<endl;
    }
    return 0;
}   