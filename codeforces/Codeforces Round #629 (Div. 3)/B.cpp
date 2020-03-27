#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long t, n, k; cin>>t;
    while(t--) {
        cin>>n>>k;
        long long a=sqrt(k), b=0;
        while(a*(a+1)/2<=k) a++;
        while(a*(a-1)/2>=k) a--;
        b = k - a*(a-1)/2 - 1;
        // cout<<a<<b<<endl;
        string s(n, 'a');
        s[n-1-a] = 'b';
        s[n-1-b] = 'b';
        cout<<s<<endl;
    }
    return 0;
}