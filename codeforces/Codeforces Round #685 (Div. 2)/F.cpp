// https://blog.csdn.net/qq_41765114/article/details/109976481

#include <iostream>
#include <string.h>
using namespace std;

int xorsum[201];

int main() {
    int t, n, m, num;
    cin>>t;
    while(t--) {
        memset(xorsum, 0, sizeof(xorsum));
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
            cin>>num;
            xorsum[i+j] ^= num;
        }
        bool win = false;
        for(int i=0;i<n+m;i++) if(xorsum[i]) {
            win = true; break;
        }
        cout<<(win?"Ashish":"Jeel")<<endl;
    }
}