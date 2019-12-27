#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
    string word;
    vector<TrieNode*> children;
    TrieNode(){
        word = "";
        children = vector<TrieNode*>(26);
    };
};

void add(TrieNode* root, string& s) {
    for(char c: s) {
        if(root->children[c-'a']==NULL) {
            root->children[c-'a'] = new TrieNode();
        }
        root = root->children[c-'a'];
    }
    root->word = s;
}

void dfs(TrieNode* root, vector<string>& res) {
    if(root==NULL) return;
    if(!root->word.empty()) res.push_back(root->word);
    for(auto child: root->children) {
        if(child != NULL) dfs(child, res);
    }
}

vector<string> cal(vector<string>& vec) {
    TrieNode* root = new TrieNode();
    for(string& s: vec) {
        string ans = "";
        for(char c: s) {
            if(c>='a' && c<='z') ans += c;
            else if(c>='A' && c<='Z') ans += c-'A'+'a';
            else if(!ans.empty()) {
                add(root, ans); ans.clear();
            }
        }
        if(!ans.empty()) add(root, ans);
    }
    vector<string> res;
    dfs(root, res);
    return res;
}

int main(){
    int n; cin>>n;
    cin.ignore();
    vector<string> vec;
    string ans;
    while(n--) {
        getline(cin,ans);
        vec.push_back(ans);
    }
    auto res = cal(vec);
    cout<<res.size()<<endl;
    for(string& s: res) cout<<s<<endl;
    return 0;
}