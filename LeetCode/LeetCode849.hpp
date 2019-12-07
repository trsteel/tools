// 考虑边界条件
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int last_pos = -1;
        for(int i=0;i<seats.size();i++) {
            if(seats[i]==1) {
                int d = (i - last_pos);
                if (last_pos>-1) d>>=1;
                else d-=1;
                if(d > ans) ans = d;
                last_pos = i;
            }
        }
        if(seats.size()-1-last_pos > ans)
        	ans = seats.size()-1-last_pos;
        return ans;
    }
};