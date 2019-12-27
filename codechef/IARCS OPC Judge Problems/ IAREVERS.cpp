#include <iostream>
#include <vector>
 #include <algorithm>
using namespace std;

bool is_letter(char c) {
    return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

string cal(string& s) {
    string res = "", ans = "";
    for(char c: s) {
        if(is_letter(c)) ans+=c;
        else if(!ans.empty()) {
            if(!res.empty()) res = " "+res;
            res = ans + res;
            ans.clear();
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    cin.ignore();
    vector<string> vec;
    string ans;
    while(n--) {
        getline(cin,ans);
        vec.push_back(ans);
    }
    reverse(vec.begin(), vec.end());
    for(string s : vec) {
        cout<<cal(s)<<endl;
    }
    return 0;
}