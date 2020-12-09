#include <iostream>

using namespace std;


int main(){
    long t, x, i, s;
    cin>>t;
    while(t--) {
        cin>>x;
        for(s=i=1;s<x;s+=++i);
        cout<<i+(s==x+1)<<endl;
    }
    return 0;
}