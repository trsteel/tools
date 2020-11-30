#include <iostream>
#include <map>
using namespace std;


int main(){
    long t, a, b;
    cin>>t;
    string s;
    while(t--) {
        cin>>a>>b;
        cin>>s;
        int n = s.size();
        int i = 0, j = n-1;
        while(i<n&&s[i]=='0') i++;
        if(i==n) {cout<<0<<endl; continue;}
        map<int, int> mp;
        int cnt = 0, res = 0;
        while(i<n) {
            cnt++;
            while(i<n&&s[i]=='1') i++;
            if(i>j) break;
            int ans = 0;
            while(i<n&&s[i]=='0') ans++, i++;
            if(i<n) mp[ans]++;
        }
        while(cnt > 1 && !mp.empty()) {
            int x = mp.begin()->first;
            if(x*b>=a) break;
            res += x*b, cnt--;
            if(--mp[x]==0) mp.erase(x);
        }
        cout<<(res+cnt*a)<<endl;
     }
    return 0;
}