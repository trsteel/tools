//智力竞赛 40% WA

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        vector<int> a(n,0);
        for(int i=0;i<n;i++) cin>>a[i];
        int cnt=0;
        if(t>=s){
            for(int i=0;i<n;i++){
                int tmp = ceil((double)a[i]/t);
                cnt+=tmp;
            }
            if(cnt>m)cout<<"No"<<endl;
            else cout<<"0"<<endl;
            return 0;
        }
        vector<pair<int,int>> nvec(n,pair<int,int>{0,0});
        for(int i=0;i<n;i++){
            int tmp = ceil((double)a[i]/s);
            nvec[i].first=tmp*s-a[i];
            nvec[i].second = tmp;
            cnt+=tmp;
        }
        if(cnt>m) cout<<"No"<<endl;
        else{
            int right=cnt;
            while(right>0 && cnt<=m){
                sort(nvec.begin(),nvec.end(),[](pair<int,int> p1,pair<int, int> p2){
                    return p1.first<p2.first;
                });
                int i=n-1;
                for(;i>=0;i--){
                    if(nvec[i].second==0) continue;
                    //减少一道正确题
                    int tmp = ceil((double)(s-nvec[i].first)/t);
                    if(tmp<=m-cnt+1){
                        right--;
                        cnt=cnt-1+tmp;
                        nvec[i].first=tmp*t-s+nvec[i].first;
                        nvec[i].second--;
                        break;
                    }else{
                        cnt=m+1;break;
                    }
                }
                if(i<0) break;
            }
            cout<<right<<endl;
        }
    }
    return 0;
}
