#include <iostream>

using namespace std;

bool same(string& a, string& b, int l, int r, bool reverse) {
    for(int i=0;i<b.size();i++) {
        char c = reverse ? a[r-i] : a[l+i];
        if(c != b[i]) return false;
    }
    return true;
}

bool match(string& a, string& b, int l, int r, bool reverse) {
    int len = r-l+1;
    if(len<b.size()) return false;
    if(len==b.size()) {
        return same(a, b, l, r, reverse);
    }
    if(reverse) {
        if(a[r]=='B' && match(a, b, l, r-1, !reverse)) return true;
        if(a[l]=='A' && match(a, b, l+1, r, reverse)) return true;
    } else {
        if(a[l]=='B' && match(a, b, l+1, r, !reverse)) return true;
        if(a[r]=='A' && match(a, b, l, r-1, reverse)) return true;
    }
    return false;
}

int main(){
    string a, b;
    cin>>a>>b;
    cout<<(match(b, a, 0, b.size()-1, false) ? "Possible" : "Impossible") <<endl;
    return 0;
}