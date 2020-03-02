#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];
    int cnt=0, sum=0, num;
    for(int i=0;i<n;i++) {
        cin>>num;
        if(num==vec[i]) continue;
        sum += num, cnt += vec[i];
    }
    if(cnt==0) {cout<<-1<<endl; return 0;}
    int res = sum/cnt;
    while(res*cnt<=sum) res++;
    cout<<res<<endl;
    return 0;
}