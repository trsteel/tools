#include <iostream>

using namespace std;

int main(){
    long t, n, m;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        cout<<(n%m==0?"YES":"NO")<<endl;
    }
    return 0;
}