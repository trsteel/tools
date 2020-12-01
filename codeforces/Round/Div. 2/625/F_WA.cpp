/**
 * Wrong answer on test 9
 **/
#include <iostream>
#include <vector>
using namespace std;

char get_rvt_char(char c, bool rvt) {
    if(rvt) c = ((c-'0')^1)+'0';
    return c;
}

bool cal(string& s, vector<bool>& rvt, int l1, int l2, int len) {
    if(len==0) return true;
    char a = get_rvt_char(s[l1], rvt[l1]);
    if(a==s[l2]) return cal(s, rvt, l1+1, l2+1, len-1);
    if(len>2) {
        char b = get_rvt_char(s[l1+1], rvt[l1+1]);
        char c = get_rvt_char(s[l1+2], rvt[l1+2]);
        if(a!=c&&b=='1') {
            rvt[l1+2] = !rvt[l1+2];
            return cal(s, rvt, l1+1, l2+1, len-1);
        }
    }
    a = get_rvt_char(s[l1+len-1], rvt[l1+len-1]);
    if(a==s[l2+len-1]) return cal(s, rvt, l1, l2, len-1);
    if(len>2) {
        char b = get_rvt_char(s[l1+len-2], rvt[l1+len-2]);
        char c = get_rvt_char(s[l1+len-3], rvt[l1+len-3]);
        if(a!=c&&b=='1') {
            rvt[l1+len-3] = !rvt[l1+len-3];
            return cal(s, rvt, l1, l2, len-1);
        }
    }
    return false;
}

int main(){
    int n, q, l1, l2, len; cin>>n;
    string s; cin>>s>>q;
    while(q--) {
        cin>>l1>>l2>>len;
        vector<bool> rvt(s.size(), false);
        cout<<(cal(s, rvt, l1-1, l2-1, len)?"YES":"NO")<<endl;
    }
    return 0;
}