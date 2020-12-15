#include <iostream>
#include <vector>
using namespace std;

int main(){
    long t, n, a[1001];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        vector<long> res;
        for(int i=0;i+3<=n;i+=3) {
            int zero = 0, one = 0;
            for(int j=0;j<3;j++) {
                if(a[i+j]==0) zero++;
                else one++;
            }
            if(zero>=2) {
                res.push_back(0);
                res.push_back(0);
            } else {
                res.push_back(1);
                res.push_back(1);
            }
        }
        if(n%3==2) {
            if(a[n-1]==a[n-2]) {
                res.push_back(a[n-2]);
                res.push_back(a[n-1]);
            } else res.push_back(0);
        }
        cout<<res.size()<<endl;
        for(int i: res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}