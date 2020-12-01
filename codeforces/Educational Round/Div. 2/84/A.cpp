#include <iostream>

using namespace std;

bool solve(long long n, long long k) {
    k *= k;
    return n >= k && (n-k)%2==0;
}

int main(){
    long long t, n, k; cin>>t;
    while(t--) {
        cin>>n>>k;
        cout<<(solve(n, k)?"YES":"NO")<<endl;
    }
    return 0;
}