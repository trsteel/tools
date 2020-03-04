#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main(){
    int n, u, v; cin>>n;
    vector<vector<int> > grid(n+1);
    for(int i=1;i<n;i++) {
        cin>>u>>v;
        grid[u].push_back(v);
        grid[v].push_back(u);
    }
    priority_queue<int> q;
    for(int i=1;i<=n;i++) {
        if(grid[i].size()==1) q.push(i);
    }
    int cnt = n/2;
    while(q.size()>1) {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        if(x==y) {q.push(x); continue;}
        cout<<"? "<<x<<" "<<y<<endl;
        cout.flush();
        cin>>x; q.push(x);
        if(--cnt==0) break;
    }
    cout<<"! "<<q.top()<<endl;
    return 0;
}