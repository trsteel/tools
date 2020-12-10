/*
 * Create at 20170308 23:04 by steel
 */
class Solution{
public:
  int reverse(int x){
    if(x>-10 && x<10) return x; //个位数直接返回
    if(x==(1<<32)) return -63556; //若为-65536，则返回对应值
    bool isNeg = false; //若x为负数，则取反视为正数
    if(x<0){
      isNeg = true;
      x = -x;
    }
    int iRes = 0, iResPre = 0;
    while(x>0){
      iRes = iResPre*10+(x%10);
      if(iRes/10!=iResPre) return 0;
      iResPre = iRes;
      x /= 10;
    }
    if(isNeg) iRes = -iRes;
    return iRes;
  }
}
