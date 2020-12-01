#include <iostream>
using namespace std;

long n, a[100001];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i] ^= a[i-1];
    for(int k=3;k<=n;k++) for(int i=0;i+k<=n;i++) {
        for(int j=i+1;j<i+k;j++) if((a[j]^a[i])>(a[j]^a[i+k])) {
           cout<<(k-2)<<endl; return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}