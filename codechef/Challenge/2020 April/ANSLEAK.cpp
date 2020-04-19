#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const long maxn = 501;
const long maxk = 5001;
long nums[maxn][maxk];

int main(){
    long long t, n, m, k, num; cin>>t;
    while(t--) {
        cin>>n>>m>>k;       
        for(long i=0;i<n;i++) for(long j=0;j<k;j++) {
            cin>>nums[i][j];
        }
        for(long i=0;i<n;i++) cout<<nums[i][i%k]<<" ";
        cout<<endl;
    }
    return 0;
}