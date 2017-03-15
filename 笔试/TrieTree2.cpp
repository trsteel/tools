//
//  Xcode2
//  阿里在线笔试，for lulu
//  Created by 墨川 on 2017/3/15.
//  Copyright © 2017年 墨川. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_CHILD 62
#define STR_LEN 65

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
    bool insert(string str){
        if(root==NULL || str.size()==0)
            return false;
        Node* t = root;
        for(unsigned int i=0;i<str.size();i++){
            int index = (str[i]>='0'&&str[i]<='9')?(str[i]-'0'):((str[i]>='A'&&str[i]<='Z')?(str[i]-'A'+10):(str[i]-'a'+36));
            if(t->child[index]==NULL){
                Node* tmp = create();
                t->child[index]=tmp;
            }
            t = t->child[index];
        }
        t->count=1;
        return true;
    }
    bool search(string str){
        if(root==NULL || str.size()==0)
            return true;
        Node *t = root;
        int cnt = 0;
        for(unsigned int i=0;i<str.size();i++){
            int index = (str[i]>='0'&&str[i]<='9')?(str[i]-'0'):((str[i]>='A'&&str[i]<='Z')?(str[i]-'A'+10):(str[i]-'a'+36));
            if(t->child[index]!=NULL){
                t = t->child[index];
                if(t->count==1&&search(str.substr(i+1, str.size()))){
                    cnt++;
                }
            }
            else break;
        }
        if(cnt>1)cout<<str<<endl;
        return cnt>0;
    }
};

int main(){
    TrieTree* trieTree = new TrieTree();
    int n=0;
    vector<string> vec;
    string str;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str;
        vec.push_back(str);
        trieTree->insert(str);
    }
    for(int i=0;i<n;i++){
        trieTree->search(vec[i]);
    }
//    trieTree->search("123456abced");
    return 0;
}
