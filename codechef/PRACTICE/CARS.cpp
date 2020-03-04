/**
 * 关键点: -0要用字符串进行处理
 **/
#include <iostream>

using namespace std;

int main(){
    int n, t, l; cin>>t;
    while(t--) {
        cin>>l>>n;
        int res = 0;
        string s;
        while(n--) {
            cin>>s;
            int ans = 0;
            if(s[0]=='-') {
                for(int i=1;i<s.size(); i++) ans = ans*10 + s[i]-'0';
                res = max(res, ans);
            } else {
                for(char c: s) ans = ans*10+c-'0';
                res = max(res, l-ans);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}