#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main(){
    int t, a, b, c; cin>>t;
    int A, B, C, res;
    while(t--) {
        cin>>a>>b>>c;
        if(b%a==0&&c%b==0) {cout<<0<<endl<<a<<" "<<b<<" "<<c<<endl; continue;}
        res = b+c-2*a, A=a, B=a, C=a;
        for(int i=1;i<=20000;i++) for(int j=i;j<=20000;j+=i) for(int k=j;k<=20000;k+=j) {
            int ans = abs(i-a)+abs(j-b)+abs(k-c);
            if(ans<res) res=ans, A=i, B=j, C=k;
        }
        cout<<res<<endl<<A<<" "<<B<<" "<<C<<endl;
    }
    return 0;
}