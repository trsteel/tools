#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <stdio.h>
using namespace std;

const int maxn = 100001;
const long maxi = 2*maxn;
long seg[maxi];

long lowbit(long x) {
	return x&(-x);
}

void modify(long x,long y) {
    // cout<<x<<" "<<y<<"mod"<<endl;
	for (long i=x;i<maxi;i+=lowbit(i)) seg[i]+=y;
}

long query(long x) {
	long ans=0;
	for (long i=x;i>0;i-=lowbit(i)) ans+=seg[i];
	return ans;
}

long belong[maxn], nums[maxn], res[maxn];
struct Cmd {
    long l, r, y, id;
    friend bool operator < (const Cmd& a, const Cmd& b) {
        if(belong[a.l]==belong[b.l]) return a.r < b.r;
        return belong[a.l] < belong[b.l];
    }
} cmd[maxn];

void add(int idx) {
    long x = nums[idx], y = nums[idx+1];
    if(x>y) {long z = x; x = y; y = z;}
    // cout<<x<<" "<<y<<"add"<<endl;
    modify(x, 1); modify(y+1, -1);
}

void del(int idx) {
    long x = nums[idx], y = nums[idx+1];
    if(x>y) {long z = x; x = y; y = z;}
    // cout<<x<<" "<<y<<"del"<<endl;
    modify(x, -1); modify(y+1, 1);
}

void solve(int n, int m) {
    int L = 1, R = 1;
    memset(seg, 0, sizeof(seg));
    for(int i=1;i<=m;i++) {
        for(;R<cmd[i].r;R++) add(R);
        for(;L>cmd[i].l;L--) add(L-1);
        for(;R>cmd[i].r;R--) del(R-1);
        for(;L<cmd[i].l;L++) del(L);
        res[cmd[i].id] = query(cmd[i].y);
        // cout<<cmd[i].id<<"idx"<<res[cmd[i].id]<<endl;
    }
    for(int i=1;i<=m;i++) printf("%ld\n", res[i]);
}

int main(){
    int t, n, q; cin>>t;
    int x1, x2, y;
    while(t--) {
        cin>>n>>q;
        int sq = sqrt(n);
        set<long> st;
        for(int i=1;i<=n;i++) {
            scanf("%ld", &(nums[i]));
            st.insert(nums[i]);
            belong[i] = (i-1)/sq + 1;
        }
        for(int i=1;i<=q;i++) {
            scanf("%ld%ld%ld", &cmd[i].l, &cmd[i].r, &cmd[i].y);
            st.insert(cmd[i].y);
            cmd[i].id = i;
        }
        unordered_map<long, long> um;
        long idx = 1;
        for(long i: st) um[i] = idx++;
        for(int i=1;i<=n;i++) nums[i] = um[nums[i]];
        for(int i=1;i<=q;i++) cmd[i].y = um[cmd[i].y];
        sort(cmd+1,cmd+q+1);
        solve(n, q);
    }
    return 0;
}