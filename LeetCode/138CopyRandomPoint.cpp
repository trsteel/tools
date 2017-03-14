/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyByNext(RandomListNode *head){
        if(head==NULL) return NULL;
        RandomListNode* copyHead=new RandomListNode(head->label);
        copyHead->next = copyByNext(head->next);
        return copyHead;
    }
    bool isNodeEquals(RandomListNode* node1, RandomListNode* node2){
        RandomListNode* p=node1, *q=node2;
        while(p!=NULL && q!=NULL){
            if(p->label!=q->label) return false;
            p=p->next;q=q->next;
        }
        return p==q;
    }
    RandomListNode *findRandom(RandomListNode* head, RandomListNode* random){
        RandomListNode* p=head;
        while(p){
            if(isNodeEquals(p, random))return p;
            p=p->next;
        }
        return NULL;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* copyHead = copyByNext(head);
        RandomListNode* p=copyHead;
        while(head){
            p->random = findRandom(copyHead, head->random);
            head = head->next;
            p=p->next;
        }
        return copyHead;
    }
};
