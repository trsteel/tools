#include <iostream>

using namespace std;

int main(){
    long t; cin>>t;
    string s;
    while(t--) {
        cin>>s;
        long long res = 0, p = 1;
        for(long long i=s.size()-1;i>=0;i--) {
            long long ans = s[i]>='A'?(s[i]-'A'+10):(s[i]-'0');
            res += ans*p; p*=16;
        }
        cout<<res<<endl;
    }
    return 0;
}