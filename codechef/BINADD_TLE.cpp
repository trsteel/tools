#include <iostream>
#include <algorithm>
using namespace std;

string XOR(string& a, string& b) {
    int i = a.size()-1, j = b.size()-1;
    string res = "";
    while(i>=0 && j>=0) {
        char c = ((a[i--]-'0')^(b[j--]-'0')) + '0';
        res.push_back(c);
    }
    while(i>=0) res.push_back(a[i--]);
    while(j>=0) res.push_back(b[j--]);
    reverse(res.begin(), res.end());
    return res;
}

string AND(string& a, string& b) {
    int i = a.size()-1, j = b.size()-1;
    string res = "";
    while(i>=0 && j>=0) {
        char c = ((a[i--]-'0')&(b[j--]-'0')) + '0';
        res.insert(res.begin(), c);
    }
    return res;
}

bool is_zero(string& s) {
    for(char c: s) if(c!='0') return false;
    return true;
}

int cal(string& a, string& b) {
    // cout<<a<<b<<endl;
    int res = 0;
    string u, v;
    while(!is_zero(b)) {
        // cout<<a<<" "<<b<<endl;
        u = XOR(a, b);
        v = AND(a, b);
        a = move(u);
        b = v + "0";
        // cout<<a<<" "<<b<<endl;
        res++;
    }
    return res;
}

int main(){
    int t; cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2; 
        cout<<cal(s1, s2)<<endl;
    }
    return 0;
}