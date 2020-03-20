#include <iostream>

using namespace std;

int main(){
    long t, n; cin>>t;
    while(t--) {
        cin>>n;
        if(n==1) cout<<-1<<endl;
        else {
            cout<<'2';
            for(int i=0;i<n-1;i++) cout<<'3';
            cout<<endl;
        }
    }
    return 0;
}