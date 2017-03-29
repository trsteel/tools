/*
 * 完美世界笔试编程第二题：简单弹球游戏
 * 问题描述：给定宽为w，高为h的矩形范围，以左下角为原点，弹球从坐标(x,0)处出发，向右上方45度角弹射出去，
 *         遇到矩形边界则完全碰撞，遇到矩形角落则原路折回
 *         输出小球前n次回到起始边时的横坐标
 * 通过率：33.3%
 * 20170330 01:45
 */

#include <stdio.h>
void ball(int w, int h, int x, int n)
{
    //implement your code here
    int sumT=w;
    int trace = x;
    int round=0;
    while (true) {
        while(sumT<=trace){
            round++;
            sumT+=round%2==0?w:h;
        }
        trace = 2*sumT-trace;
        if(round%4==3) printf("%d ",trace%(2*(w+h)));
        if(round/4>=n)break;
    }
}
int main()
{
    int w, h, x, n;
    while(scanf("%d%d%d%d", &w, &h, &x, &n) != EOF) {
        ball(w, h, x, n);
    }
}
