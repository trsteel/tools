#include <iostream>

using namespace std;

int cal(int a, int b) {
    if(a==b) return 0;
    if(a<b) return (b-a)%2==1?1:2;
    return (a-b)%2==0?1:2;
}

int main(){
    int t, a, b; cin>>t;
    while(t--) {
        cin>>a>>b;
        cout<<cal(a, b)<<endl;
    }
    return 0;
}