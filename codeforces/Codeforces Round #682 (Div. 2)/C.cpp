#include <iostream>
#include <vector>
#include <map>
using namespace std;

const long maxn = 101;
long a[maxn][maxn];

int main(){
    long t, n, m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
            cin>>a[i][j]; if((i+j)%2==a[i][j]%2) a[i][j]++;
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}