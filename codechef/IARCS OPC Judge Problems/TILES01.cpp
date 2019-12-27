#include <iostream>
#include <vector>
using namespace std;

int cal(int n) {
    if(n<=0) return 0;
    if(n<3) return n;
    int mod = 15746;
    int a = 1, b = 2, c;
    for(int i=3;i<=n;i++) {
        c = (a+b) % mod;
        a = b;
        b = c;
    }
    return c;
}

int main(){
    int n; cin>>n;
    cout<<cal(n)<<endl;
    return 0;
}