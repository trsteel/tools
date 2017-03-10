/*
 * 螺旋队列 RA
 * 思路：给定坐标(x,y)，若x>0,
 * if(y>x) n=(2*y+1)^2-y+x;
 * else if(x>-y) n=(2*x+1)^2+x-y;
 * else n=(2*y-1)^2+|y|-x;
 * 若x<0,
 * if(y<x) n=(2*|y|+1)^2+y-x;
 * else if(y<-x) n=(2*|x|+1)^2+|y|-|x|;
 * else n=(2*y+1)^2+y-|x|;
 */
int foo(int x, int y){
    n=(max(abs(x), abs(y))*2+1)^2+abs(y)-abs(x);
}
