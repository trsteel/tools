#include <iostream>

using namespace std;

long gcd(long a,long b){
    if(b==0) return a;
    return gcd(b,a%b);
 }

int main(){
    long n, x, y, z; cin>>n>>x;
    cin>>y; z = abs(x-y);
    for(long i=1;i<n;i++) {
        cin>>y; z = gcd(z, abs(x-y));
    }
    cout<<z<<endl;
    return 0;
}