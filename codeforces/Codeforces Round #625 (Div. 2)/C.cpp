
#include <iostream>
#include <queue>
#include <math.h>
#include <unordered_set>
using namespace std;

void remove(string& s, char c) {
    bool change = true;
    while(change) {
        change = false;
        for(int i=0;i<s.size();i++) {
            if(s[i]!=c) continue;
            if((i>0&&s[i-1]+1==c)||(i<s.size()-1&&s[i+1]+1==c)) {
                s = s.substr(0, i)+s.substr(i+1);
                change = true; break;
            }
        }
    }
}

int main(){
    int n; cin>>n;
    string s; cin>>s;
    vector<bool> vis(n, false);
    for(char c='z'; c>'a'; c--) {
        remove(s, c);
    }
    cout<<(n-s.size())<<endl;
    return 0;
}