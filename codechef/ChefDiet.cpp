#include <iostream>

using namespace std;

int main(){
    int t; cin>>t;
    while(t-->0) {
        int n, k; cin>>n>>k;
        int ans = 0, cur, fail=0;
        for(int i=1;i<=n;i++) {
            cin>>cur; ans+=cur;
            if(ans<k && fail==0) fail = i;
            ans -= k;
        }
        if(fail>0) cout<<"NO "<<fail<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}