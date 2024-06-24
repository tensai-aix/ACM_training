#include <stdio.h>
#include <stdlib.h>
int** build(int n,int m){
    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        arr[i] = (int *)malloc(m * sizeof(int));
    }
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=m-1;j++){
            arr[i][j]=0;
        }
    }
    return arr;
}
void search(int** num,int n,int m,int* sign,int n_max,int m_max){
    if(*sign==1){
        return;
    }
    if((n==2&&m==1)||(n==1&&m==2)){
        (*sign)=1;
        return;
    }
    else if(num[n-1][m]==0&&num[n+1][m]==0&&num[n][m-1]==0&&num[n][m+1]==0){
        return;
    }
    else{
        num[n][m]=0;
        if(num[n-1][m]!=0){
            search(num,n-1,m,sign,n_max,m_max);
        }
        if(num[n+1][m]!=0){
            search(num,n+1,m,sign,n_max,m_max);
        }
        if(num[n][m-1]!=0){
            search(num,n,m-1,sign,n_max,m_max);
        }
        if(num[n][m+1]!=0){
            search(num,n,m+1,sign,n_max,m_max);
        }
    }

}
int main()
{
    int n,m,sign;
    scanf("%d %d",&n,&m);
    char c[100];
    int** num=build(n+2,m+2);
    for(int i=0;i<=n-1;i++){
        scanf("%s",c);
        for(int j=0;j<=m-1;j++){
            if(c[j]=='.'){
                num[i+1][j+1]=1;
            }
        }
    }
    if(num[n][m]==0 || num[1][1]==0){
        printf("no");
    }
    else{
        sign=0;
        search(num,n,m,&sign,n+2,m+2);
    }
    if(sign==1){
        printf("Yes");
    }
    else{
        printf("No");
    }
}
