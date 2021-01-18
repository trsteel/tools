#include <iostream>

using namespace std;
long long n, k, a;

struct Node {
    long long cnt, val, dep;
    Node* next[2];
    Node(int v, int d) {
        cnt = 1, val = v, dep = d;
        next[0] = next[1] = nullptr;
    }
};

Node* root;

int add(Node* node, long long x) {
    if(node->dep==0) return 0;
    long long v = x&(1LL<<(node->dep-1));
    int res = 0;
    if(!node->next[v]) {
        node->next[v] = new Node(v, node->dep-1);
        res++;
    }
    res += add(node->next[v], x);
    node->cnt += res;
    return res;
}

long long dfs(Node* node) {
    if(!node) return 0;
    // 最后一层，直接计数
    if(node->dep==0) {
        return (k&1)<node->val?node->cnt:0;
    }
    // k的这一位为1
    if(k&(1LL<<(node->dep-1))) {
        if(!node->next[1]) return 0;
        
    }
    // k的这一位为0
    long long res = dfs(node->next[0]) + dfs(node->next[1]);
    if(node->next[0]&&node->next[1]) {
        res += node->next[0]->cnt*node->next[1]->cnt;
    }
    return res;
}

int main(){
    root = new Node(0, 62);
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>a; add(root, a);
    }
    cout<<dfs(root)<<endl;
    return 0;
}