#include <iostream>

using namespace std;

int main(){
    long long t, x, y, k;
    cin>>t;
    while(t--) {
        cin>>x>>y>>k;
        long long d = (y+1)*k - 1;
        long long res = d/(x-1);
        if(d%(x-1)) res++;
        res += k;
        cout<<res<<endl;
    }
    return 0;
}   