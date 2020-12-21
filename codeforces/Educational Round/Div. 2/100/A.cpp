#include <iostream>

using namespace std;

long long t, a, b, c;

bool cal() {
    if((a+b+c)%9) return false;
    long long d = (a+b+c)/9;
    return a >= d && b >= d && c >= d;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>a>>b>>c;
        cout<<(cal()?"YES":"NO")<<endl;
    }
    return 0;
}