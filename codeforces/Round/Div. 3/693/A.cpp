#include <iostream>

using namespace std;

long cal(long x) {
    long res = 1;
    while(x%2==0) {
        x >>= 1, res<<=1;
    }
    return res;
}

int main(){
    long t, w, h, n;
    cin>>t;
    while(t--) {
        cin>>w>>h>>n;
        cout<<(cal(w)*cal(h)>=n?"YES":"NO")<<endl;
    }
    return 0;
}