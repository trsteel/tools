#include <iostream>
using namespace std;

int main(){
    long t, n, m, r, c;
    cin>>t;
    while(t--) {
        cin>>n>>m>>r>>c;
        long res = max(r+c-2, n+m-r-c);
        res = max(res, abs(r-1)+abs(c-m));
        res = max(res, abs(r-n)+abs(c-1));
        cout<<res<<endl;
    }
    return 0;
}