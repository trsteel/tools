#include <iostream>

using namespace std;

bool cal(int n) {
    for(int i=0;i*3<=n;i++) for(int j=0;j*5<=n;j++) {
        int d = n-i*3-j*5;
        if(d%7==0) {
            cout<<i<<" "<<j<<" "<<(d/7)<<endl;
            return true;
        }
        if(d<0) break;
    }
    return false;
}

int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        if(!cal(n)) cout<<-1<<endl;
    }
    return 0;
}