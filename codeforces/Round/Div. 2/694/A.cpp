#include <iostream>

using namespace std;

int main(){
    long long t,n,x,a;
    cin>>t;
    while(t--){
        cin>>n>>x;
        long long l = 0, r = 0;
        for(int i=0;i<n;i++) {
            cin>>a;
            l+=a;
            r += (a/x)+(a%x>0);
        }
        l = l/x + (l%x>0);
        cout<<l<<" "<<r<<endl;
    }
    return 0;
}