#include <iostream>

using namespace std;

int main() {
    string s;
    cin>>s;
    long n = s.size();
    bool valid = true;
    for(int i=0;i<=n/2;i++) if(s[i]!=s[n-i-1]) {
        valid = false; break;
    }
    if(valid) {
        cout<<0<<endl;
    } else {
        cout<<3<<endl;
        cout<<"L 2"<<endl;
        cout<<"R 2"<<endl;
        cout<<"R "<<(2*n-1)<<endl;
    }
    return 0;
}
