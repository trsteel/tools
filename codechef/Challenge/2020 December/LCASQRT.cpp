#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <unordered_set>

using namespace std;
const long long maxn = 500001, mod = 998244353;
long long t, n, P, p[maxn], c[maxn], w;

struct TreeNode {
    long long idx, val, sum;
    vector<TreeNode *> children;

    explicit TreeNode(long long i) {
        idx = i, val = 0, sum = 0;
        children.clear();
    }
};

TreeNode *nodes[maxn];

struct num {  //建立一个复数域
    long long x, y;
};

num mul(num a, num b, long long p) {  //复数乘法
    num ans = {0, 0};
    ans.x = ((a.x * b.x % p + a.y * b.y % p * w % p) % p + p) % p;
    ans.y = ((a.x * b.y % p + a.y * b.x % p) % p + p) % p;
    return ans;
}

long long binpow_real(long long a, long long b, long long p) {  //实部快速幂
    long long ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans % p;
}

long long binpow_imag(num a, long long b, long long p) {  //虚部快速幂
    num ans = {1, 0};
    while (b) {
        if (b & 1) ans = mul(ans, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return ans.x % p;
}

long long cipolla(long long n, long long p) {
    n %= p;
    if (n == 0) return 0;
    if (p == 2) return n;
    if (binpow_real(n, (p - 1) / 2, p) == p - 1) return -1;
    long long a;
    while (1) {  //生成随机数再检验找到满足非二次剩余的a
        a = rand() % p;
        w = ((a * a % p - n) % p + p) % p;
        if (binpow_real(w, (p - 1) / 2, p) == p - 1) break;
    }
    num x = {a, 1};
    return binpow_imag(x, (p + 1) / 2, p);
}

void find(unordered_set<long long> &us, long long ans, long long sum) {
    long long x = cipolla(ans, P);
    if (x == -1) return;
    long long y = (P - x) % P;
    while (x < sum + P) {
        if (x >= sum && (x * x - ans) % P == 0) {
            us.insert(x - sum);
        }
        x += P;
    }
    while (y < sum + P) {
        if (y >= sum && (y * y - ans) % P == 0) {
            us.insert(y - sum);
        }
        y += P;
    }
}

long long dfs(vector<long> &idx, long long i) {
    if (i == idx.size()) return 1;
    auto node = nodes[idx[i]];
    long long ans = c[node->idx], sum = 0;
    for (auto &child: node->children) {
        ans = (ans + child->sum * child->sum) % P;
        sum = (sum + child->sum) % P;
    }
    unordered_set<long long> us;
    find(us, ans, sum);
    if (us.empty()) return 0;
    node->val = *us.begin();
    node->sum = sum + node->val;
    return us.size() * dfs(idx, i + 1) % mod;
}

void solve() {
    cin >> n >> P;
    for (long i = 2; i <= n; i++) cin >> p[i];
    for (long i = 1; i <= n; i++) cin >> c[i];
    // 构造层级树结构
    for (long i = 1; i <= n; i++) nodes[i] = new TreeNode(i);
    for (long i = 2; i <= n; i++) {
        nodes[p[i]]->children.push_back(nodes[i]);
    }
    vector<long> idx;
    idx.push_back(1);
    long cur = 0;
    while (cur < idx.size()) {
        long i = idx[cur++];
        for (auto child: nodes[i]->children) {
            idx.push_back(child->idx);
        }
    }
    reverse(idx.begin(), idx.end());
    long long res = dfs(idx, 0);
    cout << res << endl;
    if (res == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i++) cout << nodes[i]->val << " ";
        cout << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
