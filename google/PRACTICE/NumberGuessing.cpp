#include <iostream>
using namespace std;

int main() {
    long long t, a, b, n, mid; cin>>t;
    string s;
    while(t--) {
        cin>>a>>b>>n;
        a++;
        while(true) {
            mid = (a+b)>>1;
            cout<<mid<<endl;
            cin>>s;
            if(s=="CORRECT") {
                a = mid; break;
            } else if(s=="TOO_SMALL") {
                a = mid+1;
            } else if(s=="TOO_BIG") {
                b = mid-1;
            } else return 0;
        }
        // cout<<a<<endl;
    }
    return 0;
}