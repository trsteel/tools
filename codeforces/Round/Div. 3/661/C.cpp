#include <iostream>

using namespace std;
const long maxn = 51;
long t, n, w[maxn], cnt[maxn*2];

long find(long sum) {
    long res = 0;
    for(long i=1;i<sum;i++) {
        res += min(cnt[i], cnt[sum-i]);
    }
    return res/2;
}

long cal() {
    long res = 0;
    for(long i=1;i<=2*n;i++) {
        res = max(res, find(i));
    }
    return res;
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<maxn*2;i++) {
            cnt[i] = 0;
        }
        for(int i=0;i<n;i++) {
            cin>>w[i]; cnt[w[i]]++;
        }
        cout<<cal()<<endl;
    }
    return 0;
}