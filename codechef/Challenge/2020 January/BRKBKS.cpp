#include <iostream>

using namespace std;

int cal(int s, int a, int b, int c) {
    if(a+b+c<=s) return 1;
    if(a+b<=s || b+c<=s) return 2;
    return 3;
}

int main(){
    int t; cin>>t;
    int s, a, b, c;
    while(t--) {
        cin>>s>>a>>b>>c;
        cout<<cal(s, a, b, c)<<endl;
    }
    return 0;
}