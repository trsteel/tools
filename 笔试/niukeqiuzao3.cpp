#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i=0;i<n;i++) cin>>vec[i];
    int ans=1;
    for(int i=0;i<n;i++){
        //cout<<i<<endl;
        if(ans>n-i) break;
        bool isChanged = false;
        int j = i+1;
        for(;j<n;j++){
            if(vec[j-1]<vec[j]) continue;
            else if(!isChanged){
                if(j+1<n && vec[j+1]>(vec[j-1]+1))
                    isChanged = true;
                else{
                    break;
                }
            }else{
                break;
            }
        }
        ans = max(ans,j-i);
    }
    cout<<ans<<endl;
    return 0;
}
