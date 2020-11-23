#include <iostream>

using namespace std;

bool cal(string& s, int n, int l, int r) {
    for(int i=0;i<l;i++) if(s[i]==s[l]) {
        return true;
    }
    for(int i=r+1;i<n;i++) if(s[i]==s[r]) {
        return true;
    }
    return false;
}

int main(){
    int t, n, q, l, r;
    cin>>t;
    string s;
    while(t--) {
        cin>>n>>q;
        cin>>s;
        while(q--) {
            cin>>l>>r;
            cout<<(cal(s, n, l-1, r-1)?"YES":"NO")<<endl;
        }
    }
    return 0;
}