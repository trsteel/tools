#include <iostream>
using namespace std;

int main(){
    long t, n, m, x;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        long neg = 0, sum = 0, mi = 101;
        for(int i=0;i<n*m;i++) {
            cin>>x;
            if(x < 0) neg++, x=-x;
            mi = min(mi, x);
            sum += x;
        }
        if(neg%2) sum -= 2*mi;
        cout<<sum<<endl;
    }
    return 0;
}