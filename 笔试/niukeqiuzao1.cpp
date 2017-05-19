#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i=0;i<n;i++) cin>>vec[i];
    int ans=1;
    int pre = 0;
    for(int i=1;i<n;i++){
        if((pre==1 && vec[i]<vec[i-1]) || (pre==-1 && vec[i]>vec[i-1])){
            pre  = 0;
            ans++;
        }else if(vec[i]<vec[i-1]){
            pre = -1;
        }else if(vec[i]>vec[i-1]){
            pre = 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
