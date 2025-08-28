#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 10

typedef struct TrieNode{
    struct TrieNode*children[ALPHABET];
    int isEnd;
}TrieNode;

TrieNode* createNode(){
    TrieNode*node=(TrieNode*)malloc(sizeof(TrieNode));
    node->isEnd=0;
    for(int i=0;i<ALPHABET;i++)node->children[i]=NULL;
    return node;
}
int insert(TrieNode*root,char*word){
    TrieNode*node=root;
    int len=strlen(word);
    int flag=0;

    for(int i=0;i<len;i++){
        int idx=word[i]-'a';
        if(!node->children[idx])node->children[idx]=createNode();
        node=node->children[idx];
        if(node->isEnd)flag=1;
    }
    for(int i=0;i<ALPHABET;i++)
        if(node->children[i])flag=1;
    node->isEnd=1;
    return flag;
}
int main(){
    int n;
    scanf("%d",&n);
    TrieNode*root=createNode();
    char word[1001];
    for(int i=0;i<n;i++){
        scanf("%s",word);
        if(insert(root,word)){
            printf("BAD SET\n%s\n",word);
            return 0;
        }
    }
    printf("GOOD SET\n");
    return 0;
}
