//  Accepted
//  Created by 墨川 on 2017/3/10.
//  Copyright © 2017年 墨川. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CHILD 26

typedef struct TreeNode{
    int count;
    struct TreeNode* child[MAX_CHILD];
}Node;
class TrieTree{
private:
    Node *root;
public:
    TrieTree(){
        root = create();
    }
    ~TrieTree(){
        if(root!=NULL) del(root);
    }
    Node* create(){
        Node* node = (Node*)malloc(sizeof(Node));
        memset(node, 0, sizeof(Node));
        return node;
    }
    void del(Node* node){
        for(int i=0;i<MAX_CHILD;i++){
            if(node->child[i]!=NULL)
                del(root->child[i]);
        }
        free(node);
    }
    bool insert(char* str){
        if(root==NULL || *str=='\0')
            return false;
        Node* t = root;
        char *p = str;
        while(*p!='\0'){
            if(t->child[*p-'a']==NULL){
                Node* tmp = create();
                t->child[*p-'a']=tmp;
            }
            t->count++;
            t = t->child[*p-'a'];
            p++;
        }
        t->count++;
        return true;
    }
    int search(char* str){
        if(root==NULL || *str=='\0')
            return 0;
        char* p = str;
        Node *t = root;
        while(*p!='\0'){
            if(t->child[*p-'a']!=NULL){
                t = t->child[*p-'a'];
                p++;
            }
            else break;
        }
        if(*p=='\0') return t->count;
        else return 0;
    }
};

int main(){
    TrieTree* trieTree = new TrieTree();
    int n,m;
    char* str = new char[11];
    cin>>n;
    while(n-->0){
        cin>>str;
        trieTree->insert(str);
    }
    cin>>m;
    while(m-->0){
        cin>>str;
        cout<<trieTree->search(str)<<endl;
    }
    delete [] str;
    return 0;
}
