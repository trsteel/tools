class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> index(26,0);
        for(int i=0;i<26;i++) {
            index[order[i]-'a'] = i;
        }
        for(int i=0;i<words.size()-1;i++) {
            if(!isSort(index, words[i], words[i+1])) return false;
        }
        return true;
    }
    bool isSort(vector<int>& index, string& a, string& b) {
        for(int i=0;i<a.size();i++) {
            if(b.size()<=i) return false;
            if(index[a[i]-'a']>index[b[i]-'a']) return false;
            else if(index[a[i]-'a']<index[b[i]-'a']) return true;
        }
        return a.size()<=b.size();
    }
};