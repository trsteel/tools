#include <iostream>
#include <set>
#include <vector>
using namespace std;

string decode(string& s, int l, int r) {
    if(l>=r) return "";
    if(l+1==r) return s.substr(l, r-l+1);
    vector<string> ans;
    int last=l+1, dep1=0, dep2=0;
    for(int i=l+1;i<r;i++) {
        switch(s[i]) {
        case '[': dep1++; break;
        case ']': dep1--; break;
        case '{': dep2++; break;
        case '}': dep2--; break;
        }
        if(dep1==0&&dep2==0){
            ans.push_back(decode(s, last, i));
            last = i+1;
        }
    }
    string res = "";
    res += s[l];
    if(s[l]=='{') {
        set<string> st(ans.begin(), ans.end());
        for(set<string>::iterator it=st.begin();it!=st.end();it++) {
            res += *it;
        }
    } else {
        for(vector<string>::iterator it=ans.begin();it!=ans.end();it++) {
            res += *it;
        }
    }
    res += s[r];
    return res;
}

int main(){
    int t; cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;
        cout<<(decode(s1, 0, s1.size()-1)==decode(s2, 0, s2.size()-1)?"YES":"NO")<<endl;
    }
    return 0;
}