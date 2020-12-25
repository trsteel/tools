#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e6+10,up=1e6;
struct BIT{
    int n,tr[N];
    void init(int _n){
        n=_n;
        memset(tr,0,sizeof tr);
    }
    void add(int x,int v){
        for(int i=x;i<=n;i+=i&-i)
            tr[i]+=v;
    }
    int sum(int x){
        int ans=0;
        for(int i=x;i;i-=i&-i)
            ans+=tr[i];
        return ans;
    }
}tr;
struct node{
    int y,pos,op;
    bool operator<(node &x)const{
        return pos<x.pos || (pos==x.pos && op>x.op);
    }
}f[N<<1];
struct edge{
    int x,l,r;
    bool operator<(edge &y)const{
        return x<y.x;
    }
}e[N];
ll cal(ll l,ll r){
    return tr.sum(r)-tr.sum(l-1);
}
int n,m,c,d,l,r,x,y,cnt[N];
ll ans;
int main(){
    scanf("%d%d",&n,&m);
    //不考虑四条边线 答案=1+长为1e6的横线+竖线+横纵交点数
    ans=1;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&y,&l,&r);
        if(l==0 && r==up)ans++;
        f[++c]=node{y+1,l,1};
        f[++c]=node{y+1,r+1,-1};
    }
    tr.init(up+1);
    sort(f+1,f+c+1);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&x,&l,&r);
        e[i]=edge{x,l+1,r+1};
    }
    sort(e+1,e+m+1);
    int now=1;
    for(int i=1;i<=m;++i){
        while(now<=c && f[now].pos<=e[i].x){
            tr.add(f[now].y,f[now].op);
            now++;
        }
        ans+=cal(e[i].l,e[i].r);
        if(e[i].l==1 && e[i].r==up+1)ans++;
    }
    printf("%lld\n",ans);
    return 0;
}