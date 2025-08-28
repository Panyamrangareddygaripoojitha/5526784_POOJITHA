#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x,y,moves;
} Node;
int minimumMoves(char **grid,int n,int startX,int startY,int goalX,int goalY){
    int directions[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int **visited=(int **)malloc(n * sizeof(int *));
    for(int i=0;i<n;i++){
        visited[i]=(int*)calloc(n,sizeof(int));
    }
    Node*queue = (Node*)malloc(n*n*sizeof(Node));
    int front=0,rear=0;
    queue[rear++]=(Node){startX,startY,0};
    visited[startX][startY]=1;

    while(front<rear){
        Node cur=queue[front++];
        if(cur.x==goalX&&cur.y==goalY)return cur.moves;

        for(int d=0;d<4;d++){
            int nx=cur.x,ny=cur.y;
            while(1){
                nx+=directions[d][0];
                ny+=directions[d][1];
                if(nx<0||ny<0||nx>=n||ny>=n||grid[nx][ny]=='X')break;
                if(!visited[nx][ny]){
                    visited[nx][ny]=1;
                    queue[rear++]=(Node){nx,ny,cur.moves+1};
                }
            }
        }
    }

    return -1; 
}
int main(){
    int n;
    scanf("%d",&n);
    char **grid=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        grid[i]=(char*)malloc((n+1)*sizeof(char));
        scanf("%s",grid[i]);
    }
    int startX,startY,goalX,goalY;
    scanf("%d %d %d %d",&startX,&startY,&goalX,&goalY);

    int result=minimumMoves(grid,n,startX,startY,goalX,goalY);
    printf("%d\n",result);

    for(int i=0;i<n;i++)free(grid[i]);
    free(grid);
    return 0;
}
