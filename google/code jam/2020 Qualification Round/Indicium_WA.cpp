#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cal(long long n, long long d) {
    for(long long i=0;i<n;i++) {
        cout<<(((d+i)%n)+1)<<" ";
    }
    cout<<endl;
}

int main(){
    long long T, n, k; cin>>T;
    for(long long t=1;t<=T;t++) {
        cin>>n>>k;
        if(n==2 && k==3) {
            cout<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"Case #"<<t<<": "<<"POSSIBLE"<<endl;
        long long a = k/n, b = k%n;
        for(long long i=0;i<b;i++) {
            cal(n, a+1+i);
        }
        for(long long i=b;i<n;i++) {
            cal(n, a+i);
        }
    }
    return 0;
}