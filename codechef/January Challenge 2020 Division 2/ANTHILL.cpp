#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
    int n, m, a, r;
    cin>>n>>m>>a>>r;
    vector<vector<int> > edges(m, vector<int>(2));
    for(int i=0;i<m;i++) {
        scanf("%d", &edges[i][0]);
        scanf("%d", &edges[i][1]);
    }
    cout<<m<<endl;
    for(int i=0;i<m;i++) {
        printf("1 1 %d %d\n", edges[i][0], edges[i][1]);
    }
    return 0;
}