#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    long t; cin>>t;
    while(t--) {
        long long cnt = 0, idx = 0, d=0, num=0;
        double sum = 0;
        while(num!=-1) {
            cin>>num; if(num==-1) break;
            idx++; if(num>30) cnt++;
            if(num%2==0) sum += idx*num, d += idx;
        }
        double res = d==0?0:(sum/d);
        printf("%lld %.2f\n", cnt, res);
    }
    return 0;
}   