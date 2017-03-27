/*
 * network is bad, test torrow
 * 20170328 02:20
 */
class Solution {
public:
    int getMoney(int low, int high){
        switch(high-low){
            case 0:return 0;
            case 1:return high;
            case 2:return low+1;
            case 3:return 2*low+2;
            case 4:return 2*low+4;
            default:
                return getMoney((low+high)/2+1,high)+(low+high)/2;
        }
    }
    int getMoneyAmount(int n) {
        return getMoney(1,n);
    }
};
