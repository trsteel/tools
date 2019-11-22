#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin>>s;
    int cnt = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i]>'2') {cout<<0<<endl; return 0;}
        if(s[i]=='1') cnt++;
    }
    if(cnt>0) cnt--;
    if(cnt==0) {cout<<1<<endl; return 0;}
    // 主要难点在于数字会越界，需要转成字符串表示
    string res = "1";
    while(cnt--) {
        int d = 0;
        for(int i=res.size()-1;i>=0;i--) {
            d += (res[i]-'0')*2;
            res[i] = d%10 + '0';
            d /= 10;
        }
        if(d>0) res.insert(res.begin(), d+'0');
    }
    cout<<res<<endl;
    return 0;
}