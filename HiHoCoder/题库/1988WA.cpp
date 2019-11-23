// WA
#include <iostream>

using namespace std;

int gbc(int a, int b) {
    if(a==1 || b==1) return 1;
    if(a%b==0) return a;
    if(b%a==0) return b;
    return a>b?gbc(a%b, b):gbc(a, b%a);
}

int main() {
    long n;
    cin>>n;
    if(n==1) {cout<<1<<endl; return 0;}
    if((n+1)%4!=0) {cout<<0<<endl; return 0;}
    long ans = (n+1)/4 + 1, res = 0;
    for(int i=1;i<ans;i++) {
        if(gbc(i, ans-i)==1) res++;
    }
    cout<<res<<endl;
    return 0;
}