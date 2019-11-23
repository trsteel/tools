#include <iostream>

using namespace std;

bool less_(string& s, int n, int i, int j) {
    char a, b;
    for(int k=0;k<n;k++) {
        a = s[(i+k)%n], b = s[(j+k)%n];
        if(a!=b) return a<b;
    }
    return true;
}

int main(){
    string s; cin>>s;
    int n = s.size();
    int res = 0;
    for(int i=1;i<n;i++) {
        if(s[i]!=s[i-1] && less_(s, n, i, res)) res = i;
    }
    cout<<s.substr(res)+s.substr(0, res)<<endl;
    return 0;
}