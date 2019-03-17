/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: the head of linked list.
     * @return: a middle node of the linked list
     */
    ListNode * middleNode(ListNode * head) {
        // write your code here
        ListNode* p=head;
        ListNode* q=head;
        while(q&&q->next&&q->next->next) {
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};