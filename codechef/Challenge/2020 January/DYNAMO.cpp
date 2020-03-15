/**
 * 关键点: 比较难理解输入输出的方式
 **/
#include <iostream>

using namespace std;

int main(){
    int t; cin>>t;
    long n, s, a, b, c, d, e, p, res;
    while(t--) {
        cin>>n>>a;
        p = 1; for(int i=0;i<n;i++) p*=10;
        s = p*2+a; cout<<s<<endl;
        cin>>b; c = p-b; cout<<c<<endl;
        cin>>d; e = p-d; cout<<e<<endl;
        cin>>res; if(res==-1) break;
    }
    return 0;
}