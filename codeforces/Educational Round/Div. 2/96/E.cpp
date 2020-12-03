#include <iostream>

using namespace std;

long long cal(string& s, int l, int r) {
    if(l >= r) return 0;
    if(s[l]==s[r]) return cal(s, l+1, r-1);
    if(s[l+1]==s[r] || s[l]==s[r-1]) {
        return r-l + cal(s, l+1, r-1);
    }
    return 2*(r-l)-1+cal(s, l+1, r-1);
}

int main(){
    int n; string s;
    cin>>n>>s;
    cout<<cal(s, 0, n-1)<<endl;
    return 0;
}