
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int near_y_cnt(vector<vector<char> >& grid, int x, int y) {
    int res = 0, n = grid.size();
    for(int i=0;i<4;i++) {
        int a=x+direct[i][0], b=y+direct[i][1];
        if(a>=0&&a<n&&b>=0&&b<n&&grid[a][b]=='Y') res++;
    }
    return res;
}

bool fill_y(vector<vector<char> >& grid) {
    int n = grid.size();
    map<pair<int,int>, int> m;
    for(int i=0;i<n;i++) for(int j=0; j<n;j++) {
        if(grid[i][j]=='Y') m[make_pair(i, j)] = near_y_cnt(grid, i, j);
    }
    
    return true;
}

int main(){
    int n, x, y; cin>>n;
    vector<vector<char> > grid(n, vector<char>(n, ' '));
    map<pair<int, int>, pair<int, int> > m;
    for(int i=0;i<n;i++) for(int j=0; j<n;j++) {
        cin>>x>>y;
        if(x==-1 && y==-1) grid[i][j]='Y';
        else {
            x--, y--;
            if(x==i&&y==j) grid[i][j]='X';
            else m[make_pair(i, j)] = make_pair(x, y);
        }
    }

    return 0;
}