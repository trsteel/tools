#include <iostream>

using namespace std;

bool large(string& a, string& b) {
    int i=0, j=0, m = a.size(), n = b.size();
    while(i<m&&j<n) {
        if(a[i]!=b[j]) return a[i]>b[i];
        else i++, j++;
    }
    return m > n;
}

bool bfs(string& a, string& b, int i, int j, string ans, string& res) {
    if(j==b.size()) {
        if(i<a.size()) ans += a.substr(i);
        if(res.empty() || large(res, ans)) res = ans;
        return true;
    }
    if(i==a.size()) return false;
    bool bres = bfs(a, b, i+1, j, ans+a[i], res);
    if(a[i]==b[j]) bres = bfs(a, b, i+1, j+1, ans, res) || bres;
    return bres;
}

int main(){
    string a, b;
    cin>>a>>b;
    string res = "";
    if(!bfs(a, b, 0, 0, "", res)) 
        cout<<-1<<endl;
    else cout<<res<<endl;
    return 0;
}