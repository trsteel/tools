#include <iostream>
#include <queue>
using namespace std;

long long t, x, y, c[7];
long long cal_x(long long x) {
    return x > 0 ? c[2]*x : c[5]*(-x);
}

long long cal_y(long long y) {
    return y > 0 ? c[6]*y : c[3]*(-y);
}

int main() {
    cin>>t;
    while(t--) {
        cin>>x>>y;
        swap(x, y);
        for(int i=1;i<=6;i++) cin>>c[i];
        long long res = 1LL<<62;
        if (x < 0) {
            res = min(res, c[5]*(-x)+cal_y(y));
            res = min(res, c[4]*(-x)+cal_y(y-x));
        } else {
            res = min(res, c[2]*x+cal_y(y));
            res = min(res, c[1]*x+cal_y(y-x));
        }
        if(y < 0) {
            res = min(res, c[3]*(-y)+cal_x(x));
            res = min(res, c[4]*(-y)+cal_x(x-y));
        } else {
            res = min(res, c[6]*y+cal_x(x));
            res = min(res, c[1]*y+cal_x(x-y));
        }
        cout<<res<<endl;
    }
    return 0;
}
