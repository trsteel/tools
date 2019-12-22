#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        string s; cin>>s;
        int d = n;
        vector<int> vec(26, -1);
        for(int i=0;i<n;i++) {
            int last = vec[s[i]-'a'];
            if(last>=0) d = min(d, i-last);
            vec[s[i]-'a'] = i;
            // cout<<i<<d<<endl;
        }
        cout<<(n-d)<<endl;
    }
    return 0;
}