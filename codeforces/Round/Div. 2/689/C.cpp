#include <iostream>
#include <iomanip>
using namespace std;

long t, n, m, a[100001], b[100001], r;
double p;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>a[i]; b[i] = 0;
        }
        b[n] = 1;
        for(int i=n-1;i>=0;i--) {
            if(a[i]!=i+1) break;
            b[i] = 1;
        }
        // for(int i=0;i<n;i++) cout<<b[i]<<" ";
        // cout<<endl;
        double res = 1;
        for(int i=0;i<m;i++) {
            cin>>r>>p;
            if(b[r]==1) res *= 1-p;
        }
        if(b[0]==1) res = 0;
        cout<<fixed<<setprecision(6)<<(1-res)<<endl;
    }
    return 0;
}