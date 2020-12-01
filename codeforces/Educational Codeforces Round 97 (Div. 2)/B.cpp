#include <iostream>
 
using namespace std;
 
int main(){
    long t, n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>s;
        long ans = 0;
        for(int i=1;i<n;i++) if(s[i]==s[i-1]) ans++;
        cout<<(ans+1)/2<<endl;
    }
    return 0;
}