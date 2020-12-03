#include <iostream>

using namespace std;

int main(){
    long t, n;
    string s;
    cin>>t;
    while(t--) {
        cin>>n>>s;
        
        int l = 0, r = 0, res = 0;
        while(l<n) {
            if(r < l) r = l;
            while(r<n-1&&s[r]!=s[r+1]) r++;
            l++; while(l<n&&s[l]==s[l-1]) l++;
            if(r==n-1) {
                l++; while(l<n&&s[l]==s[l-1]) l++;
            } else r++;
            res++;
            // cout<<l<<" "<<r<<" "<<res<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}