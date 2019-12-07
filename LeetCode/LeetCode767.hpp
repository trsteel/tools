/*
 * 按照字母出现顺序降序排列
 * 如果某个字母出现的次数大于字符串长度的一半向上取整，根据抽屉原则，则不可能出现符合要求的结果。
 * 排序之后，将字符列表对半分割成两个列表，每次从两个列表中各取一个字符，可以保证相邻的字符不相同。
 */
class Solution {
public:
    string reorganizeString(string S) {
        // 记录出现次数=>字母列表的映射
        map<int, set<char>, greater<int>> counts;
        // 记录每个字母出现的次数
        vector<int> chars(26, 0);
        // 每个字母出现的次数不能大于字符串长度加1的一半
        int limit = (S.size()+1)>>1;
        for(char c: S) {
            counts[chars[c-'a']].erase(c);
            counts[++chars[c-'a']].insert(c);
            if(chars[c-'a']>limit) return "";
        }
        // 按字母出现次数从大到小排序
        vector<char> ans;
        for(auto& it: counts) {
            for(auto& c: it.second) {
                for(int i=0;i<it.first;i++)
                    ans.push_back(c);
            }
        }
        string res;
        // 每次从前一半和后一半各取一个字符
        for(int i=0;i<limit;i++) {
            res += ans[i];
            if(i+limit<ans.size()) res += ans[i+limit];
        }
        return res; 
    }
};