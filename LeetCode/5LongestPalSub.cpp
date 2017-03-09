/*
 *求最长对称子串
 *思路：遍历
 */
class Solution {
public:
    bool isPalindromz(string s){
         if(s=="" || s.size()==1) return true;
         for(auto i=0;i<=s.size()/2;i++){
             if(s[i]!=s[s.size()-i-1]) return false;
         }
         return true;
     }
     string longestPalindrome(string s) {
         if(s=="" || s.size()==1) return s;
         int start=0, len=0;
         for(auto i=0;i<s.size();i++){
             for(auto j=s.size();j>i+len;j--){
                 if(s[i]==s[j-1] && isPalindromz(s.substr(i+1,j-i-2)))
                     if(j-i>len){
                         start = i;
                         len = j-i;
                     }
             }
         }
         return s.substr(start, len);
     }
};
