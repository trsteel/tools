#include <iostream>

using namespace std;
int n;
string s;

int valid(int x) {
    int ans = 0, res = 0;
    for(char c: s) {
        ans += c-'0';
        if(ans > x) return -1;
        if(ans==x) {
            res++, ans = 0;
        }
    }
    if(ans != 0) return -1;
    return res;
}


int main(){
    cin>>n>>s;
    int ans = 0, res = -1;
    for(char c: s) {
        ans += c-'0';
        res = max(res, valid(ans));
    }
    if(res==1) res = -1;
    cout<<res<<endl;
    return 0;
}