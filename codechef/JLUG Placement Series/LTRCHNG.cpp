
#include <iostream>

using namespace std;

int main(){
    long t; cin>>t;
    string s;
    while(t--) {
        cin>>s;
        string res = "";
        for(char c: s) {
            char ch = c=='z'?'a':(c+1);
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') {
                ch += 'A'-'a';
            }
            res.push_back(ch);
        }
        cout<<res<<endl;
    }
    return 0;
}