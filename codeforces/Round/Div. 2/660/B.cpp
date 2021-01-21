#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        string s(n, '9');
        for(int i=0;i*4+1<=n;i++) {
            s[i] = '8';
        }
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }
    return 0;
}