#include <iostream>

using namespace std;
long q;
string s, t;

long gcd(long a,long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

string cal() {
    int m = s.size(), n = t.size();
    int d = gcd(m, n);
    string ans = "", ans1 = "";
    for(int i=0;i<n/d;i++) {
        ans += s;
    }
    for(int i=0;i<m/d;i++) {
        ans1 += t;
    }
    if(ans==ans1) return ans;
    return "-1";
}

int main(){
    cin>>q;
    while(q--) {
        cin>>s>>t;
        cout<<cal()<<endl;
    }
    return 0;
}