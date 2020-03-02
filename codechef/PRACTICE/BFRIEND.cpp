#include <iostream>

using namespace std;

int main(){
    long t, n, a, b, c, f; cin>>t;
    while(t--) {
        cin>>n>>a>>b>>c;
        if(a>b) swap(a, b);
        long res = 4*1e9;
        while(n--) {
            cin>>f;
            if(a<=f && b>=f) res = min(res, b-a+c);
            else if(f<a) res = min(res, b+a-2*f+c);
            else if(f>b) res = min(res, 2*f-a-b+c);
        }
        cout<<res<<endl;
    }
    return 0;
}