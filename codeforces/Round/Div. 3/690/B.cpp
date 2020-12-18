#include <iostream>

using namespace std;

long t, n;
string s;

bool cal() {
    if(n < 4) return false;
    for(int i=0; i<=4;i++) {
        string ans = s.substr(0, i) + s.substr(n+i-4, 4-i);
        // cout<<ans<<endl;
        if(ans == "2020") return true;
    }
    return false;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<(cal()?"YES":"NO")<<endl;
    }
    return 0;
}