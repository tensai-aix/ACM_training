#include <stdio.h>
#include <stdlib.h>
typedef struct CHU{
    int x1;
    int y1;
    int x2;
    int y2;
}Chu;
int main()
{
    int n,m;
    char c[1000][1000];
    Chu chu[1000];
    scanf("%d %d",&n,&m);
    for(int i=0;i<=n-1;i++){
        scanf("%s",c[i]);
    }
    int count=0;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            if(c[i][j]=='h'&&j<=m-4&&c[i][j+1]=='e'&&c[i][j+2]=='h'&&c[i][j+3]=='e'){
                count++;
                chu[count].x1=i;
                chu[count].y1=j;
                chu[count].x2=i;
                chu[count].y2=j+2;
            }
            if(c[i][j]=='h'&&j>=3&&c[i][j-1]=='e'&&c[i][j-2]=='h'&&c[i][j-3]=='e'){
                count++;
                chu[count].x1=i;
                chu[count].y1=j;
                chu[count].x2=i;
                chu[count].y2=j-2;
            }
            if(c[i][j]=='h'&i<=n-4&&c[i+1][j]=='e'&&c[i+2][j]=='h'&&c[i+3][j]=='e'){
                count++;
                chu[count].x1=i;
                chu[count].y1=j;
                chu[count].x2=i+2;
                chu[count].y2=j;
            }
            if(c[i][j]=='h'&i>=3&&c[i-1][j]=='e'&&c[i-2][j]=='h'&&c[i-3][j]=='e'){
                count++;
                chu[count].x1=i;
                chu[count].y1=j;
                chu[count].x2=i-2;
                chu[count].y2=j;
            }
        }
    }
    int ans=count;
    for(int i=1;i<=count;i++){
        for(int j=i+1;j<=count;j++){
            if((chu[i].x1==chu[j].x2)&&(chu[i].x2==chu[j].x1)&&(chu[i].y1==chu[j].y2)&&(chu[i].y2==chu[j].y1)){
                ans--;
            }
        }
    }
    printf("%d",count);
}
