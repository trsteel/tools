/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> st;
        for(int g: G) st.insert(g);
        bool cur_exists = st.count(head->val);
        while(head->next){
            bool next_exsits = st.count(head->next->val);
            if(cur_exists && next_exsits) st.erase(head->val);
            cur_exists = next_exsits;
            head = head->next;
        }
        return st.size();
    }
};