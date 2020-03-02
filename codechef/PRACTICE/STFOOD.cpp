#include <iostream>

using namespace std;

int main(){
    int t, n, s, p, v; cin>>t;
    while(t--) {
        cin>>n;
        int res = 0;
        while(n--) {
            cin>>s>>p>>v;
            res = max(res, p/(s+1)*v);
        }
        cout<<res<<endl;
    }
    return 0;
}   