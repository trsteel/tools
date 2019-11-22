#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin>>s;
    long res=0, cnt=0, same=0;
    char last = ' ';
    for(int i=0;i<s.size();i++) {
        char c=s[i];
        if(c!=last){cnt++, same=1, last=c; continue;}
        if(same==2) {
            res = max(res, cnt);
            cnt=1, same=1, last = c;
            i--;
            continue;
        }
        cnt++, same++;
    }
    res = max(res, cnt);
    cout<<res<<endl;
    return 0;
}