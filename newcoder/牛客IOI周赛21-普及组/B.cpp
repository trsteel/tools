#include <iostream>
#include <algorithm>
using namespace std;
const long maxn = 1001;
long n, a[maxn], score[maxn][maxn], q, l, r, k, p;

long find(long num, long c) {
    long rank = upper_bound(score[c], score[c]+a[c], num) - score[c];
    // cout<<num<<" "<<c<<"=>"<<rank<<endl;
    return a[c] - rank;
}

long find(long num, long l, long r) {
    long res = 1;
    for(long i=l;i<=r;i++) {
        res+=find(num, i);
        // cout<<num<<" "<<i<<" "<<res<<endl;
    }
    return res;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        for(int j=0;j<a[i];j++) {
            cin>>score[i][j];
        }
        sort(score[i], score[i]+a[i]);
    }
    cin>>q;
    while(q--) {
        cin>>l>>r>>k>>p;
        k--;
        cout<<find(score[k][a[k]-p], l-1, r-1)<<endl;
    }
    return 0;
}