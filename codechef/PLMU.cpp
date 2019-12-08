#include <iostream>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int cnt = 0, zero=0, i;
        while(n--) {
            cin>>i;
            if(i==2) cnt++;
            if(i==0) zero++;
        }
        int res = 0;
        if(cnt>1) res += cnt*(cnt-1)/2;
        if(zero>1) res += zero*(zero-1)/2;
        cout<<res<<endl;
    }
    return 0;
}