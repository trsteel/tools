/*
 * 思路：寻找下标对应
 * Runtime Error
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(s.size()<=numRows || numRows<2) return s;
        string sRes(s.size(), '0');
        int oneRound = 2*numRows-2;
        auto totalRounds = s.size()/oneRound;
        auto outR = s.size()%oneRound+1;
        for(int i=0;i<s.size();i++){
            int curRound = i/oneRound;
            int curRow=i%oneRound;
            if(curRow==0)sRes[curRound]=s[i];
            else if(curRow<numRows) sRes[(2*curRow-1)*totalRounds+2*curRound+(curRow<outR?1:0)]=s[i];
            else sRes[(2*(oneRound-curRow)-1)*totalRounds+2*curRound+1+(curRow<outR?1:0)]=s[i];
        }
        return sRes;
    }
};
