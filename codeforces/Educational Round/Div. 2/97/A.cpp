#include <iostream>

using namespace std;

int main(){
    long t, l, r;
    cin>>t; while(t--){
        cin>>l>>r;
        cout<<(l*2>=(r+1)?"YES":"NO")<<endl;
    }
    return 0;
}