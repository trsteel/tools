#include <iostream>

using namespace std;

int main(){
    long long t, x1, y1, z1, x2, y2, z2;
    cin>>t;
    while(t--) {
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        long long res = 0;
        long long d = min(z1, y2);
        z1 -= d, y2 -= d, res += d*2;
        if(z1 > 0) {
            d = min(z1, z2);
            z1 -= d, z2 -= d;
        }
        if(z1 > 0) {
            d = min(z1, x2);
            z1 -= d, x2 -= d;
        }
        if(y1 > 0) {
            d = min(y1, y2);
            y1 -= d, y2 -= d;
        }
        if(y1 > 0) {
            d = min(y1, x2);
            y1 -= d, x2 -= d;
        }
        if(y1 > 0) {
            d = min(y1, z2);
            res -= d*2;
        }
        cout<<res<<endl;
    }
    return 0;
}