#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long t, n, m; cin>>t;
    while(t--) {
        cin>>n>>m;
        long long your=0, sum=0, ans;
        cin>>your;
        for(int i=1; i<n; i++) {
            cin>>ans; sum += ans;
        }
        cout<<your+min(m-your, sum)<<endl;
    }
    return 0;
}