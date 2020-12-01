#include <iostream>
#include <vector>
using namespace std;

void cal(vector<int>& vec, int n) {
    for(int i=0;i<n;i++) {
        if(vec[i]%2==0) {
            cout<<1<<endl<<(i+1)<<endl;
            return;
        }
    }
    for(int i=1;i<n;i++) {
        if(vec[i]%2==1) {
            cout<<2<<endl;
            cout<<1<<" "<<(i+1)<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main(){
    int t, n; cin>>t;
    while(t--) {
        cin>>n;
        vector<int> vec(n);
        for(int& i: vec) cin>>i;
        cal(vec, n);
    }
    return 0;
}