#include <iostream>
#include <vector>
using namespace std;
long long n;
string s;

int main(){
    cin>>n;
    cin>>s;
    vector<long long> lc(n+1, 0), rw(n+1, 0);
    for(long i=0;i<n;i++) lc[i+1] = lc[i] + (s[i]=='C');
    for(long i=n-1;i>=0;i--) rw[i] = rw[i+1] + (s[i]=='W');
    long long res = 0;
    for(long i=1;i<n-1;i++) {
        if(s[i]=='O') res += lc[i]*rw[i+1];
    }
    cout<<res<<endl;
    return 0;
}