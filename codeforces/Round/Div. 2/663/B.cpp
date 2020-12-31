#include <iostream>

using namespace std;

int main(){
    long t, n, m;
    string g[101];
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>g[i];
        long res = 0;
        for(int i=n-1;i>=0;i--) {
            for(int k=m-1;k>=0;k--) {
                if(i==n-1 && k==m-1) continue;
                if(g[i][k]=='D' && i==n-1) res++;
                else if(g[i][k]=='R' && k==m-1) res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}