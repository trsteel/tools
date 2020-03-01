/**
 * 关键点: 斐波拉契第n项矩阵快速求值
 **/
#include <iostream>
#include <vector>
using namespace std;
long mod = 1e9+7;

vector<vector<long> > matrix_multi(vector<vector<long> >& m1, vector<vector<long> >& m2) {
    vector<vector<long> > res(2, vector<long>(2, 0));
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) {
        res[i][j] = (res[i][j]+m1[i][k]*m2[k][j])%mod;
    }
    return res;
}

vector<vector<long> > matrix_power(vector<vector<long> >& base, long n) {
    vector<vector<long> > res(2, vector<long>(2, 0));
    for(int i=0;i<2;i++) res[i][i] = 1;
    auto tmp = base;
    for(; n != 0; n>>=1) {
        if((n&1)!=0) res = matrix_multi(res, tmp);
        tmp = matrix_multi(tmp, tmp);
    }
    return res;
}

long fib(long n) {
    if(n<1) return 0;
    if(n==1 || n==2) return 1;
    vector<vector<long> > base(2, vector<long>(2, 1));
    base[1][1] = 0;
    auto res = matrix_power(base, n-2);
    return (res[0][0]+res[1][0])%mod;
}

int main(){
    long t, n; cin>>t;
    char g;
    while(t--) {
        cin>>g>>n;
        if(g=='m') n--;
        cout<<fib(n+2)<<endl;
    }
    return 0;
}