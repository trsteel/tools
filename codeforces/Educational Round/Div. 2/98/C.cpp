#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    string s;
    while(t--) {
        cin>>s;
        int a = 0, b = 0, ans = 0;
        for(char c: s) {
            if(c=='(') a++;
            else if(c=='[') b++;
            else if(c==')') {
                if(a > 0) ans++, a--;
            } else if(c==']') {
                if(b > 0) ans++, b--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}