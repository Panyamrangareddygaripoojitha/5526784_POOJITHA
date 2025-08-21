#include <stdio.h>
#define MAXR 200
#define MAXC 201
int R,C,N;
char grid[MAXR][MAXC];
char temp[MAXR][MAXC];
void printfGrid(char g[MAXR][MAXC]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            putchar(g[i][j]);
        }
        putchar('\n');
    }
}
void fillWithBombs(char g[MAXR][MAXC]){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
        g[i][j]='O';
    }
    g[i][C]='\0';
}
}
void explode(char input[MAXR][MAXC],char nextGrid[MAXR][MAXC]){
    fillWithBombs(nextGrid);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(input[i][j]=='O'){
                nextGrid[i][j]='.';
                if(i>0) nextGrid[i-1][j]='.';
                if(i<R-1)nextGrid[i+1][j]='.';
                if(j>0)nextGrid[i][j-1]='.';
                if(j<C-1)nextGrid[i][j+1]='.';
                
            }
        }
    }
    
}
int main(void){
    if(scanf("%d %d %d",&R,&C,&N)!=3)return 0;
    for(int i=0;i<R;i++){
        scanf("%200s",grid[i]);
    }
    if(N==1){
        printfGrid(grid);
        return 0;
    }
    if(N%2==0){
        fillWithBombs(temp);
        printfGrid(temp);
        return 0;
    }
    char first[MAXR][MAXC];
    char second[MAXR][MAXC];
    explode(grid,first);
    explode(first,second);
    
    if(N%4==3){
        printfGrid(first);
    }
    else{
        printfGrid(second);
    }
    return 0;
}

