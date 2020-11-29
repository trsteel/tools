#include <iostream>
#include <unordered_set>
using namespace std;

const long maxn = 100001;

int main(){
    long n, a[maxn];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n%2==0) {
        long xorsum = 0;
        for (int i = 0; i < n - 1; i++) xorsum ^= a[i];
        if (xorsum != a[n - 1]) {
            cout << "NO" << endl;
            return 0;
        }
        n--;
    }
    cout<<"YES"<<endl;
    cout<<(n-2)<<endl;
    for(int i=1;i<n-1;i+=2) {
        cout<<i<<" "<<(i+1)<<" "<<(i+2)<<endl;
    }
    for(long i=n-2;i>2;i-=2) {
        cout<<i<<" "<<(i-1)<<" "<<(i-2)<<endl;
    }
    return 0;
}