/**
 * 关键点: 用scanf/printf代替cin/cout，否则最后两个测试用例超时
 **/
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int m, n; scanf("%d%d",&m,&n);
    int dp[1001][1001];
    int num;
    for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
        scanf("%d",&num);
        dp[i+1][j+1] = dp[i+1][j]+dp[i][j+1]+num-dp[i][j];
    }
    int t; cin>>t;
    int a, b, c, d;
    while(t--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", dp[a-1][b-1]+dp[c][d]-dp[a-1][d]-dp[c][b-1]);
    }
    return 0;
}