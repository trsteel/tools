//未提交
//判断胡牌的函数couldWin有错

#include <iostream>
#include <vector>
using namespace std;
void gene14(vector<string> a,vector<bool> visited, int s, int e, int vCnt, vector<vector<string>>& vec ){
    if(e-s<vCnt || e<s) return;
    if(e-s==vCnt){
        vector<string> tmp;
        for(int i=0;i<s;i++) if(visited[i]) tmp.push_back(a[i]);
        for(int i=s;i<e;i++)tmp.push_back(a[i]);
        vec.push_back(tmp);
        return;
    }
    gene14(a, visited, s+1,e,vCnt,vec);
    visited[s]=true;
     gene14(a, visited, s+1,e,vCnt-1,vec);
}
vector<vector<string>> get14(vector<string> a){
    vector<vector<string>> vec;
    if(a.size()<14) return vec;
    vector<bool> visited(a.size(),false);
    gene14(a,visited,0,(int)a.size(),14,vec);
    return vec;
}
bool couldWin(vector<string> a){
    sort(a.begin(),a.end());
    for(int i=0;i<a.size();){
        if(a[i]==a[i+1]){
            if((a.size()-i-2)%3==0){
                bool cWin = true;
                for(int j=i+2;j<a.size();j+=3){
                    if(a[j][0]==a[j+1][0] && a[j][0]==a[j+2][0]
                       && ((a[j][1]+1==a[j+1][1] && a[j][1]+2==a[j+1][2])
                           || (a[j][1]==a[j+1][1] && a[j][1]==a[j+1][2])))
                        continue;
                    else{
                        cWin = false;
                        break;
                    }
                }
                if(cWin) return true;
            }
        }
            if(a[i][0]==a[i+1][0] && a[i][0]==a[i+2][0]
               && ((a[i][1]+1==a[i+1][1] && a[i][1]+2==a[i+1][2])
                   || (a[i][1]==a[i+1][1] && a[i][1]==a[i+1][2])))
                continue;
            else return false;
    }
    return false;
}
bool win(vector<string> a){
    vector<vector<string>> vec = get14(a);
    for(vector<string> v:vec){
        if(couldWin(v)) return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<string> a(14,"");
    vector<string> b(n,"");
    for(int i=0;i<14;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    int ans=0;
    bool w=false;
    while(!(w=win(a)) && ans<n){
        a.push_back(b[ans]);
        ans++;
        cout<<ans<<endl;
    }
    if(w)cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
