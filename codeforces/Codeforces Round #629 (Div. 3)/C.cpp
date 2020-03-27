#include <iostream>

using namespace std;

int main(){
    long long t, n; cin>>t;
    string s;
    while(t--) {
        cin>>n>>s;
        string a="1", b="1";
        for(long long i=1;i<n;i++) {
            if(a==b) {
                if(s[i]=='0') {
                    a.push_back('0');
                    b.push_back('0');
                } else if(s[i]=='1') {
                    a.push_back('1');
                    b.push_back('0');
                } else if(s[i]=='2') {
                    a.push_back('1');
                    b.push_back('1');
                }
            } else if(a>b) {
                a.push_back('0');
                b.push_back(s[i]);
            } else {
                a.push_back(s[i]);
                b.push_back('0');
            }
        }
        cout<<a<<endl<<b<<endl;
    }
    return 0;
}