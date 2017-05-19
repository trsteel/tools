#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(3*n,0);
    for(int i=0;i<3*n;i++) cin>>vec[i];
    sort(vec.begin(),vec.end(),[](int i, int j){return i>j;});
    long ans = 0;
    for(int i=1;i<=2*n;i+=2){
        ans+=vec[i];
    }
    cout<<ans<<endl;
    return 0;
}
