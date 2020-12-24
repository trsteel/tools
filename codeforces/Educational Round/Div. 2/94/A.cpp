#include <iostream>

using namespace std;

int main(){
    long t, n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>s;
        string res(n, ' ');
        for(int i=0;i<n;i++) {
            res[i] = s[i*2];
        }
        cout<<res<<endl;
    }
    return 0;
}