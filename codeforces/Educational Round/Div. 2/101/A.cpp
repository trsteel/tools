#include <iostream>

using namespace std;

bool cal(string& s) {
    return !(s.size()%2||s[0]==')'||s.back()=='(');
}

int main(){
    long t;
    string s;
    cin>>t;
    while(t--) {
        cin>>s;
        cout<<(cal(s)?"Yes":"No")<<endl;
    }
    return 0;
}