#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long t, n, k; cin>>t;
    string s;
    for(long tt=1;tt<=t;tt++) {
        cin>>n>>k>>s;
        int ans = 0;
        for(int i=0;i<n/2;i++) {
            if(s[i]!=s[n-i-1]) ans++;
        }
        cout<<"Case #"<<tt<<": "<<abs(k-ans)<<endl;
    }
    return 0;
}