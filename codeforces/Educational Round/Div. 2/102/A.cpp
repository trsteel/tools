#include <iostream>
#include <queue>
using namespace std;
int t, n, d, a;

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>d;
        int x = 101, y = 101, ma = 0;
        for(int i=0;i<n;i++) {
            cin>>a;
            if(a < y || a < x) {
                x = y; y = a;
                if(x<y) swap(x, y);
            }
            // cout<<x<<" "<<y<<endl;
            ma = max(ma, a);
        }
        int sum = 0;
        if(x!=101) sum+=x;
        if(y!=101) sum+=y;
        // cout<<sum<<x<<y<<endl;
        cout<<((ma <= d || sum<=d)?"YES":"NO")<<endl;
    }
    return 0;
}