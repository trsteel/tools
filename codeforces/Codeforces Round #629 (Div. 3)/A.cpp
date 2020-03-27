#include <iostream>

using namespace std;

int main(){
    long long t, a, b; cin>>t;
    while(t--) {
        cin>>a>>b;
        long long res = a/b;
        if(res*b<a) res++;
        cout<<(res*b-a)<<endl;
    }
    return 0;
}