#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;
bool dfs(vector<string> vec, int r, int d, vector<vector<bool>> vi, int x, int y, int* pre){
    if(x==vec.size()-1 && y==vec[0].size()-1) return true;
    if(x<0 || x>=vec.size() || y<0 || y>=vec[0].size()
       || vi[x][y] || vec[x][y]=='#') return false;
    vi[x][y]=true;
    int ans = INT_MAX;
    int cur = *pre+1;
    if(dfs(vec,r,d,vi,x+1,y, &cur)){ans = min(ans, cur);}
    cur = *pre+1;
    if(dfs(vec,r,d, vi, x-1,y, &cur)){ans = min(ans, cur);}
    cur = *pre+1;
    if(dfs(vec,r,d, vi, x,y-1, &cur)){ans = min(ans, cur);}
    cur = *pre+1;
    if(dfs(vec,r,d, vi, x,y+1, &cur)){ans = min(ans, cur);}
    cur = *pre+1;
    if(dfs(vec,r,d, vi, x+r,y+d, &cur)){ans = min(ans, cur);}
    if(ans<INT_MAX){
        *pre = ans;
        return true;
    }
    return false;
}
int main(){
    int h,w,d,r;
    cin>>h>>w>>d>>r;
    vector<string> vec(h, "");
    vector<vector<bool>> reachable(h, vector<bool>(w,false));
    for(int i=0;i<h;i++){
        cin>>vec[i];
    }
    int ans = 0;
    if(dfs(vec, r, d, reachable, 0, 0, &ans)) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
