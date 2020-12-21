#include <iostream>

using namespace std;

int main(){
    long long T, n, t, x;
    cin>>T;
    while(T--) {
        long long pos = 0, tm, tpos, res = 0;
        cin>>n>>tm>>tpos;
        for(int i=1;i<n;i++){
            cin>>t>>x;
            long long d = t - tm;
            if(pos <= tpos && pos+d>=tpos) {
                res++;
            } else if(pos > tpos && pos-d<=tpos) {
                res++;
            }
            if(pos == tpos) {
                tm = t, tpos = x;
            } else if(pos < tpos) {

            }
        }
    }
    return 0;
}