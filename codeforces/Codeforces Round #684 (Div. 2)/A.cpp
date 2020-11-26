#include <iostream>
using namespace std;

int main(){
    long t, n, a, b, h;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>a>>b>>h;
        cin>>s;
        long zero = 0, one = 0;
        for(char c: s) {
            if(c=='0') zero++;
            else one++;
        }
        if(a > b+h) {
            cout<<((b+h)*zero+b*one)<<endl;
        } else if(b > a+h) {
            cout<<(a*zero+(a+h)*one)<<endl;
        } else {
            cout<<(a*zero + b*one)<<endl;
        }
    }
    return 0;
}