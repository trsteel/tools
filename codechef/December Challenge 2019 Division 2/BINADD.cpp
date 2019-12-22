#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string ADD(string& s1, string& s2) {
    string res = "";
    int i = s1.size()-1, j = s2.size()-1, d=0;
    while(i>=0 && j>=0) {
        d += (s1[i--]-'0') + (s2[j--]-'0');
        res.push_back((d%2)+'0');
        d >>= 1;
    }
    while(i>=0) {
        d += (s1[i--]-'0');
        res.push_back((d%2)+'0');
        d >>= 1;
    }
    while(j>=0) {
        d += (s2[j--]-'0');
        res.push_back((d%2)+'0');
        d >>= 1;
    }
    while(d>0) {
        res.push_back((d%2)+'0');
        d >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

int PROCESS(string& s) {
    int n = s.size();
    for(int i=0;i<n;i++) {
        if(s[i]=='1') return n-i;
    }
    return 0;
}

int ONE(string& s) {
    int res = 0;
    for(char c: s) if(c=='1') res++;
    return res;
}

string XOR(string& a, string& b) {
    int i = a.size()-1, j = b.size()-1;
    string res = "";
    res.reserve(max(a.size(), b.size()));
    while(i>=0 && j>=0) {
        char c = ((a[i--]-'0')^(b[j--]-'0')) + '0';
        res.push_back(c);
    }
    while(i>=0) res.push_back(a[i--]);
    while(j>=0) res.push_back(b[j--]);
    while(res.size()>1 && res.back()=='0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

string AND(string& a, string& b) {
    int i = a.size()-1, j = b.size()-1;
    string res = "";
    res.reserve(min(a.size(), b.size()));
    while(i>=0 && j>=0) {
        char c = ((a[i--]-'0')&(b[j--]-'0')) + '0';
        res.push_back(c);
    }
    while(res.size()>1 && res.back()=='0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

bool is_zero(string& s) {
    for(char c: s) if(c!='0') return false;
    return true;
}

int calculate(string& s1, string& s2) {
    int y = PROCESS(s2);
    if(y == 0) return 0;
    int n = s1.size(), res=0;
    while(n-y-res>=0 && s1[n-y-res]=='1') res++;
    return res+1;
}

int cal(string& a, string& b) {
    if(is_zero(b)) return 0;
    int res = 0;
    string u, v;
    while(ONE(b) > 1) {
        u = XOR(a, b);
        v = AND(a, b);
        a = move(u);
        b = v + "0";
        res++;
    }
    return calculate(a, b) + res;
}

int main(){
    long t; cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2; 
        cout<<cal(s1, s2)<<endl;
    }
    return 0;
}