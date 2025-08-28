#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

typedef struct Node{
    int val;
    struct Node*next;
}Node;

Node*adj[MAX_N];
int visited[MAX_N];
void addEdge(int u,int v){
    Node*node=(Node*)malloc(sizeof(Node));
    node->val=v;
    node->next=adj[u];
    adj[u]=node;
}
int dfs(int u){
    visited[u]=1;
    int count=1;
    Node* temp=adj[u];
    while(temp){
        if(!visited[temp->val])count+=dfs(temp->val);
        temp=temp->next;
    }
    return count;
}
long long roadsAndLibraries(int n,int c_lib,int c_road,int m,int cities[][2]){
    for(int i=1;i<=n;i++){
        visited[i]=0;
        adj[i]=NULL;
    }
    for(int i=0;i<m;i++){
        int u=cities[i][0];
        int v=cities[i][1];
        addEdge(u, v);
        addEdge(v, u);
    }
    long long totalCost=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int size=dfs(i);
            if(c_road>=c_lib)totalCost+=(long long)size*c_lib;
            else totalCost+=(long long)c_lib+(long long)(size-1)*c_road;
        }
    }
    return totalCost;
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,m,c_lib,c_road;
        scanf("%d %d %d %d",&n,&m,&c_lib,&c_road);
        int cities[m][2];
        for(int i=0;i<m;i++)scanf("%d %d",&cities[i][0],&cities[i][1]);
        long long result=roadsAndLibraries(n,c_lib,c_road,m,cities);
        printf("%lld\n",result);
        for(int i=1;i<=n;i++) {
            Node*temp=adj[i];
            while(temp){
                Node*next=temp->next;
                free(temp);
                temp=next;
            }
        }
    }
    return 0;
}
