#include <iostream>

using namespace std;

int main(){
    long t, n, m, x;
    cin>>t;
    while(t--) {
        cin>>n;
        long res = 0, sum = 0, ans = 0;
        for(int i=0;i<n;i++) {
            cin>>x; sum += x;
            ans = max(ans, sum);
        }
        res += max(0L, ans);
        sum = 0, ans = 0;
        cin>>m;
        for(int i=0;i<m;i++) {
            cin>>x; sum += x;
            ans = max(ans, sum);
        }
        res += max(0L, ans);
        cout<<res<<endl;
    }
    return 0;
}   