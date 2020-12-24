#include <iostream>

using namespace std;

long t, x;
string s;
bool valid(string& w) {
    for(int i=0;i<s.size();i++) {
        if(s[i]=='0') continue;
        bool match = false;
        if(i-x>=0 && w[i-x]=='1') match = true;
        else if(i+x<s.size() && w[i+x]=='1') match = true;
        if(!match) return false;
    }
    return true;
}

int main(){
    
    cin>>t;
    while(t--) {
        cin>>s>>x;
        string w(s.size(), '1');
        for(int i=0;i<s.size();i++) {
            if(s[i]=='1') continue;
            if(i-x>=0) w[i-x] = '0';
            if(i+x<s.size()) w[i+x] = '0';
        }
        cout<<(valid(w)?w:"-1")<<endl;
    }
    return 0;
}