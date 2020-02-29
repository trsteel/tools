#include <iostream>

using namespace std;

int cal(int n, string& s) {
    int al=0, ar=n, bl=0, br=n;
    for(int i=0;i<s.size();i++) {
        if(s[i]=='0') {
            if(i%2==0) ar--;
            else br--;
        } else {
            if(i%2==0) al++;
            else bl++;
        }
        if(al>br || bl>ar) return i+1;
    }
    return s.size();
}

int main(){
    int t, n; cin>>t;
    string s;
    while(t--) {
        cin>>n; cin>>s;
        cout<<cal(n, s)<<endl;
    }
    return 0;
}