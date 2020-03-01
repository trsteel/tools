#include <iostream>
#include <math.h>
using namespace std;

int cal(int n) {
    int d = 0;
    if(n > 250000) d += (min(n, 500000)-250000)/20;
    if(n > 500000) d += (min(n, 750000)-500000)/10;
    if(n > 750000) d += (min(n, 1000000)-750000)*15/100;
    if(n > 1000000) d += (min(n, 1250000)-1000000)/5;
    if(n > 1250000) d += (min(n, 1500000)-1250000)/4;
    if(n > 1500000) d += (n-1500000)*30/100;
    return n - d;
}

int main(){
    int t, n; cin>>t;
    while(t--) {
        cin>>n;
        cout<<cal(n)<<endl;
    }
    return 0;
}