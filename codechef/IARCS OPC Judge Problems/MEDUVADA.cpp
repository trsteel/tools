#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<string>& maze, vector<vector<bool> >& vis, int x, int y) {
    int m = maze.size(), n = maze[0].size();
    x = (m+x)%m, y = (n+y)%n;
    if(maze[x][y]=='D') return true;
    if(vis[x][y] || maze[x][y]=='#') return false;
    vis[x][y] = true;
    if(maze[x][y]=='.') maze[x][y] = 'x';
    if(dfs(maze, vis, x-1, y) || dfs(maze, vis, x+1, y) 
        || dfs(maze, vis, x, y-1) || dfs(maze, vis, x, y+1)) {
        return true;
    }
    if(maze[x][y]=='x') maze[x][y] = '.';
    return false;
}

bool cal(vector<string>& maze) {
    int m = maze.size(), n = maze[0].size();
    vector<vector<bool> > vis(m, vector<bool>(n, false));
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
        if(maze[i][j]=='M') return dfs(maze, vis, i, j);
    }
    return false;
}

int main(){
    int r, c; cin>>r>>c;
    vector<string> maze(r);
    for(int i=0;i<r;i++) cin>>maze[i];
    bool res = cal(maze);
    if(res) {
        cout<<"YES"<<endl;
        for(int i=0;i<r;i++) {
            cout<<maze[i]<<endl;
        }
    } else {
        cout<<"NO"<<endl;
    }
    return 0;
}