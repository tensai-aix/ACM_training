#include <stdio.h>
#include <stdlib.h>
typedef struct NUMBER{
    int zhi;
    int isborder;
    int ischecked;
}Number;
typedef struct NUMBERS{
    Number number[32][32];
}Numbers;
void check(Numbers* numbers,int i,int j){
    numbers->number[i][j].isborder=1;
    numbers->number[i][j].ischecked=1;
    for(int m=-1;m<=1;m++){
        for(int n=-1;n<=1;n++){
            if(m*n==0){
                if(numbers->number[i+m][j+n].zhi==0 && numbers->number[i+m][j+n].ischecked==0){
                    check(numbers,i+m,j+n);
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    Numbers numbers;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            numbers.number[i][j].zhi=1;
            numbers.number[i][j].isborder=0;
            numbers.number[i][j].ischecked=0;
        }
    }
    int c;
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            scanf("%d",&c);
            numbers.number[i+1][j+1].zhi=c;
            if(i==0 || i==n-1 || j==0 || j==n-1){
                numbers.number[i+1][j+1].isborder=1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(numbers.number[i][j].isborder==1 && numbers.number[i][j].zhi==0 && numbers.number[i][j].ischecked==0){
                check(&numbers,i,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(numbers.number[i][j].isborder==0 && numbers.number[i][j].zhi==0){
                numbers.number[i][j].zhi=2;
            }
            printf("%d ",numbers.number[i][j].zhi);
        }
        printf("\n");
    }
}
