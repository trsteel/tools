#include <iostream>

using namespace std;

int main(){
    long t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        cout<<(n<=k?(k-n):(n-k)%2)<<endl;
    }
    return 0;
}