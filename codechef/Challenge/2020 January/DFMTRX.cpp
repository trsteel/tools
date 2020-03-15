/**
 * 关键点: 先暴力再找规律
 **/
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void cal(int n) {
    if(n>1 && n%2==1) {
        cout<<"Boo"<<endl; return;
    }
    vector<vector<int> > grid(n, vector<int>(n, -1));
    for(int i=1;i<=n;i++) {
        // 最左列
        grid[i-1][0] = i;
        // 反斜线
        int x = i-2, y = 1;
        while(x>=0 && y<x) {
            grid[x][y] = i; x--, y++;
        }
        // 对角线
        if (i>1) grid[i-1][i-1] = 1;
    }
    // 处理最后一行
    for(int i=1;i<n/2; i++) grid[n-1][i] = 2*i+1;
    for(int i=n/2;i<n-1;i++) grid[n-1][i] = 2*(i+1-n/2);
    // 处理倒数几行
    for(int k=2;k<n/2;k++) {
        for(int i=k;i<n-k;i++) grid[n-k][i] = i-k+2;
    }
    printf("Hooray\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            printf("%d ", i>=j?grid[i][j]:(grid[j][i] + n-1));
        }
        printf("\n");
    }
}

int main(){
    int t; scanf("%d", &t);
    int n;
    while(t--) {
        scanf("%d", &n); cal(n);
    }
    return 0;
}