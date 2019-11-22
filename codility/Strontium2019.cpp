// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <map>
#include <set>
int find(int i, map<int, set<int>, greater<int>>& m) {
    for(auto& it: m) {
        if(it.second.size()>it.second.count(i))
            return it.first;
    }
    return 0;
}
int solution(vector<string> &words) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> ans(26, 0);
    vector<int> mid(26, 0);
    vector<map<int, set<int>, greater<int>>> pre(26), suf(26);
    for(int i=0;i<words.size();i++) {
        string w = words[i];
        char c=w[0];
        int cnt=1;
        for(int i=1;i<w.size();i++) {
            if(w[i]==c) {cnt++; continue;}
            ans[c-'a'] = max(ans[c-'a'], cnt);
            c = w[i], cnt = 1;
        }
        if(cnt>0) ans[c-'a'] = max(ans[c-'a'], cnt);
        if(cnt==w.size()){mid[c-'a']+=cnt; continue;}
        cnt = 0;
        for(char c: w) {
            if(c!=w[0]) break;
            cnt++;
        }
        pre[w[0]-'a'][cnt].insert(i);
        cnt = 0;
        for(int i=w.size()-1;i>=0;i--) {
            if(w[i]!=w.back()) break;
            cnt++;
        }
        suf[w.back()-'a'][cnt].insert(i);
    }
    int res = 0;
    for(int i=0;i<26;i++) {
        res = max(res, ans[i]);
        for(auto& it: pre[i]) {
            res = max(res, it.first+mid[i]);
            for(int j: it.second) {
                res = max(res, it.first+mid[i]+find(j, suf[i]));
            }
        }
        for(auto& it: suf[i]) {
            res = max(res, it.first+mid[i]);
            for(int j: it.second) {
                res = max(res, it.first+mid[i]+find(j, pre[i]));
            }
        }
        res = max(res, mid[i]);
        res = max(res, ans[i]);
    }
    return res;
}