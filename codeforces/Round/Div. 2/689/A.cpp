#include <iostream>

using namespace std;

int main(){
    long t, n, k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        string res(k, 'a');
        for(int i=k;i<n;i++) {
            char c = res.back()=='c' ? 'a' : res.back()+1;
            res.push_back(c);
        }
        cout<<res<<endl;
    }
    return 0;
}