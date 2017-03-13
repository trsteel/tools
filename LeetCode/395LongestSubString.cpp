class Solution {
public:
    int splitSubString(string s, int k){
        if(s.size()<k) return 0;
        int* charFre = new int[26]{0};
        for(char chr:s) charFre[chr-'a']+=1;
        int start = 0,end =0, maxlen=0;
        for(;end<s.size();end++){
            if(charFre[s[end]-'a']<k){
                if(end-start+1>=k){
                    int iRes=splitSubString(s.substr(start,end), k);
                    if(iRes>maxlen) maxlen=iRes;
                }
                start=end+1;
            }
        }
        if(start==0) return s.size();
        else if(end-start+1>=k){
            int iRes=splitSubString(s.substr(start,end), k);
            if(iRes>maxlen) maxlen=iRes;
        }
        return maxlen;
    }
    int longestSubstring(string s, int k) {
        if(s.size()<k || k<1) return 0;
        if(k==1) return s.size();
        return splitSubString(s,k);
    }
};
