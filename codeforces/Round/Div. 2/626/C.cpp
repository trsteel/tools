#include <iostream>

using namespace std;

int main(){
    long n; string s;
    cin>>n>>s;
    long left = 0;
    for(char c: s) if(c=='(') left++;
    if(left*2!=n) {cout<<-1<<endl; return 0;}
    long res = 0;
    for(long i=0;i<n;) {
        if(s[i++]=='(') {
            long d = 1;
            while(d>0) d += s[i++]=='(' ? 1 : -1;
        } else {
            long d = -1;
            res++;
            while(d<0) {
                d += s[i++]=='(' ? 1 : -1;
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}