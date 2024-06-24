#include <stdio.h>
#include <stdlib.h>
typedef struct WATER{
    int iswater;
    int watergroup;
}Water;
typedef struct WATERS{
    Water water[102][102];
    int waternumber;
}Waters;
void spread(Waters* waters,int i,int j){
    waters->water[i][j].iswater=0;
    waters->water[i][j].watergroup=waters->waternumber;
        for(int m=-1;m<=1;m++){
            for(int n=-1;n<=1;n++){
                if(waters->water[i+m][j+n].iswater==1 && waters->water[i+m][j+n].watergroup==0){
                    spread(waters,i+m,j+n);
                }
            }
        }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char c[100];
    Waters waters;
    waters.waternumber=0;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            waters.water[i][j].iswater=0;
            waters.water[i][j].watergroup=0;
        }
    }
    for(int i=0;i<=n-1;i++){
        scanf("%s",c);
        for(int j=0;j<=m-1;j++){
            if(c[j]=='W'){
                waters.water[i+1][j+1].iswater=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(waters.water[i][j].iswater==1){
                waters.waternumber++;
                spread(&waters,i,j);
            }
        }
    }
    printf("%d",waters.waternumber);
}
