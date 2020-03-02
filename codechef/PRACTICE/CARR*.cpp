#include <iostream>

using namespace std;

int mod = 1e9 + 7;

struct Mat {
    long long a, b, c, d;
    Mat() {}
    Mat(long long a, long long b, long long c, long long d) : a(a), b(b), c(c), d(d) {}
    friend Mat operator*(const Mat &X, const Mat &Y) {
        return Mat((X.a * Y.a + X.b * Y.c)%mod, (X.a * Y.b + X.b * Y.d)%mod,
                   (X.c * Y.a + X.d * Y.c)%mod, (X.c * Y.b + X.d * Y.d)%mod);
    }
};

Mat MatPower(Mat M, long long y){
  Mat id(1,0,0,1);
  while(y){
    if(y&1) id=id*M;
    M=M*M; y>>=1;
  }
  return id;
}

int main(){
    long long t, n, m; cin>>t;
    while(t--) {
        cin>>n>>m;
        m %= mod;
        Mat temp=MatPower(Mat(m-1,m-1,1,0),n-1);
        cout<<((m*(temp.a+temp.c))%mod)<<endl;
    }
    return 0;
}