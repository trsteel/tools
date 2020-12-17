#include <iostream>

using namespace std;

long long t, n, k;
string s;

bool cal() {
    for(int i=0;i+k<n;i++) {
        if(s[i] == s[i+k]) continue;
        if(s[i] != '?' && s[i+k] != '?') return false;
        if(s[i] == '?') s[i] = s[i+k];
        else if(s[i+k] == '?') s[i+k] = s[i];
    }
    // cout<<s<<endl;
    int one = 0, zero = 0, w = 0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') one++;
        else if(s[i]=='0') zero++;
        else w++;
        if(i >= k) {
            if(s[i-k]=='1') one--;
            else if(s[i-k]=='0') zero--;
            else w--;
        }
        if(i >= k-1) {
            if(abs(one-zero) > w) return false;
        }
    }
    return true;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>k>>s;
        cout<<(cal()?"YES":"NO")<<endl;
    }
    return 0;
}