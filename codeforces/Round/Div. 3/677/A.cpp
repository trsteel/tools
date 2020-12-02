#include <iostream>

using namespace std;

int main() {
    long t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        long res = (s[0]-'1')*10;
        for(int i=1;i<=s.size();i++) res+=i;
        cout<<res<<endl;
    }
    return 0;
}
