#include <iostream>

using namespace std;

int main(){
    long a; cin>>a;
    for(long i=2;i*i<=a;i++) if(a%i==0) {
        cout<<i<<(a/i)<<endl; return 0;
    }
    cout<<a<<endl;
    return 0;
}