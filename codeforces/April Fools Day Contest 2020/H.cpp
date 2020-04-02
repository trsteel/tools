#include <iostream>

using namespace std;

int main(){
    long long num; cin>>num;
    long long n = num/1000, mod = num%1000, res = 1;
    while(n>0) {
        res = (res*n)%mod; n-=2;
    }
    cout<<res<<endl;
    return 0;
}