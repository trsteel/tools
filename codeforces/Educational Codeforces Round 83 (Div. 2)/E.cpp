#include <iostream>
#include <list>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
    };
};

int len(ListNode* head) {
    int res = 0;
    while(head->next) {
        res++; head = head->next;
    }
    return res;
}

int dfs(ListNode* head) {
    if(!head->next) return 0;
    if(!head->next->next) return 1;
    ListNode* ppre = head;
    ListNode* pre = head->next;
    ListNode* cur = pre->next;
    int res = len(head);
    while(cur) {
        if(pre->val == cur->val) {
            pre->val++; pre->next = cur->next;
            res = min(res, dfs(head));
            pre->val--; pre->next = cur;
            cur->val++; ppre->next = cur;
            res = min(res, dfs(head));
            cur->val--; ppre->next = pre;
        }
        ppre = ppre->next;
        pre = pre->next;
        cur = cur->next;
    }
    return res;
}

int main(){
    int n, num; cin>>n;
    ListNode* head = new ListNode(-1);
    ListNode* cur = head;
    while(n--) {
        cin>>num;
        cur->next = new ListNode(num);
        cur = cur->next;
    }
    cout<<dfs(head)<<endl;
    return 0;
}