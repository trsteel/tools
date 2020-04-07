#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rev(string& s) {
    for(char& c: s) c = ((c-'0')^1)+'0';
}

string get_str(int l, int len, bool rev) {
    string s(len, ' ');
    if(rev) {
        for(long i=len-1;i>=0;i--) {
            cout<<(l+i+1)<<endl;
            cin>>s[i];
        }
    } else {
        for(long i=0;i<len;i++) {
            cout<<(l+i+1)<<endl;
            cin>>s[i];
        }
    }
    return s;
}

int main(){
    long long T, n; cin>>T>>n;
    string a, b, c;
    for(long long t=1;t<=T;t++) {
        string res(n, '0');
        bool front = true;
        for(long i=0;i<n/2;i+=5) {
            if(front) {
                a = get_str(i, 5, false);
                b = get_str(n-i-5, 5, true);
                c = get_str(i, 5, false);
                for(int j=0;j<5;j++) {
                    res[i+j]=a[j];
                    res[n-i-1-j]=b[j];
                }
                if(a!=c&&b!=c) {
                    rev(c); rev(res);
                }
                if(b==c) reverse(res.begin(), res.end());
            } else {
                c = get_str(i, 5, false);
                a = get_str(i, 5, false);
                b = get_str(n-i-5, 5, true);
                if(a!=c&&b!=c) {
                    rev(c); rev(res);
                }
                if(b==c) reverse(res.begin(), res.end());
                for(int j=0;j<5;j++) {
                    res[i+j]=a[j];
                    res[n-i-1-j]=b[j];
                }
            }
            front = !front;
        }
        cout<<res<<endl;
        char c; cin>>c;
        if(c!='Y') break;
    }
    return 0;
}