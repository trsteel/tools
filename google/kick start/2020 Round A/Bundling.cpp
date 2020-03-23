#include <iostream>
#include <vector>
using namespace std;

struct TrieNode {
    long sum;
    vector<TrieNode*> next;
    TrieNode(){
        sum = 0;
        next = vector<TrieNode*>(26);
    };
};

void add(TrieNode* root, string& s) {
    root->sum++;
    for(char c: s) {
        if(root->next[c-'A']==NULL) {
            root->next[c-'A'] = new TrieNode();
        }
        // cout<<c<<endl;
        root->next[c-'A']->sum++;
        root = root->next[c-'A'];
    }
}

long find(TrieNode* root, long k, int dep) {
    if(!root || root->sum<k) return 0;
    long res = 0;
    for(int i=0;i<26;i++) {
        if(!root->next[i]||root->next[i]->sum<k) continue;
        root->sum -= root->next[i]->sum;
        res += find(root->next[i], k, dep+1);
        root->sum += root->next[i]->sum;
    }
    res += root->sum/k * dep;
    root->sum %= k;
    return res;
}

int main(){
    long T, n, k; cin>>T;
    for(int t=1;t<=T;t++) {
        cin>>n>>k;
        TrieNode* root = new TrieNode();
        string s;
        for(int i=0;i<n;i++) {
            cin>>s; add(root, s);
        }
        cout<<"Case #"<<t<<": "<<find(root, k, 0)<<endl;
    }
    return 0;
}