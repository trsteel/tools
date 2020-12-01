#include <iostream>
using namespace std;

long t, n, k, c[100001];

long cal(int a) {
    long i = 0, res = 0;
    while(i<n) {
        while(i<n && c[i]==a) i++;
        if(i==n) break;
        i += k, res++;
    }
    return res;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>c[i];
        long res = n;
        for(int i=1;i<=100;i++) {
            res = min(res, cal(i));
        }
        cout<<res<<endl;
    }
    return 0;
}