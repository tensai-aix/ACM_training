#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    n=n-4;
    int num[25]={0};
    int zhi[25][1000][10]={0};
    int canshu[11]={0,2,5,5,4,5,6,3,7,6,6};
    num[0]=1;
    fun(num,zhi,n,canshu);
    printf("@%d\n",num[n]);
    for(int i=1;i<=num[n];i++){
        for(int j=0;j<=9;j++){
            if(zhi[n][i][j]==0){
                break;
            }
            else{
                printf("%d ",zhi[n][i][j]);
            }
        }
        printf("\n");
    }
}
void fun(int num[],int zhi[25][1000][10],int n,int canshu[]){
    for(int use=0;use<=n-2;use++){
        printf("%d\n",use);
        for(int i=1;i<=10;i++){
            if(use+canshu[i]>n){
                continue;
            }
            for(int k=1;k<=num[use];k++){
                for(int j=0;j<=9;j++){
                    if(zhi[use][k][j]==0){
                        zhi[use+canshu[i]][num[use+canshu[i]]+k][j]=i;
                        break;
                    }
                    zhi[use+canshu[i]][num[use+canshu[i]]+k][j]=zhi[use][k][j];
                }
            }
            num[use+canshu[i]]=num[use]+num[use+canshu[i]];
        }
    }
}
