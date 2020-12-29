#include <iostream>

using namespace std;

long cal(string& s, int n) {
    long k = -1;
    for(int i=1;i<n;i++) {
        if(s[i]!=s[0]) {k=i; break;}
    }
    if(k==-1) {
        if(n<=2) return 0;
        else if(n==3) return 1;
        else return n/3 + (n%3>0);
    }
    long ans = 0, last = k, cnt = 0;
    for(long i=k;i<n+k;i++) {
        if(s[i%n]==s[last%n]) cnt++;
        else {
            ans += cnt/3;
            cnt = 1, last = i;
        }
    }
    return ans + cnt/3;
}

int main(){
    long t, n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<cal(s, n)<<endl;
    }
    return 0;
}