#include <iostream>
using namespace std;

long long factor(long long n) {
    long long res = 0;
    for(long long i=2;i*i<=n;i++) if(n%i==0) {
        while(n%i==0) res++, n/=i;
    }
    if(n>1) res++;
    return res;
}

int main() {
	// your code goes here
	long long t, n, k;
	cin>>t;
	while(t--) {
	    cin>>n>>k;
	    long long ans = factor(n);
	   // cout<<ans<<endl;
	    cout<<(ans>=k)<<endl;
	}
	return 0;
}
