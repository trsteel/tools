#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s; cin>>s;
    int l=0, r = s.size()-1;
    vector<int> res;
    while(l<r) {
        while(l<r && s[l]!='(') l++;
        while(l<r && s[r]!=')') r--;
        if(l<r) {
            res.push_back(l++);
            res.push_back(r--);
        }
    }
    if(res.empty()) {cout<<0<<endl; return 0;}
    cout<<1<<endl<<res.size()<<endl;
    sort(res.begin(), res.end());
    for(int i: res) cout<<(i+1)<<" ";
    return 0;
}