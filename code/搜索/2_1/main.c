#include <stdio.h>
#include <stdlib.h>
void update(int achu[],int chu[],int num[],int max,int i){
    int ka=-1;;
    for(int j=0;j<=max-1;j++){
        achu[j]=chu[j];
        if(chu[j]==0&&ka<0){
            ka=j;
        }
    }
    achu[ka]=num[i];
    return;
}
void reverse(int arr[],int num[],int n,int i){

    for(int j=0;j<=n-1;j++){
        if(j<i){
            arr[j]=num[j];
        }
        else if(j>i){
            arr[j-1]=num[j];
        }
    }
}
void print(int num[],int chu[],int n,int max){
    if(n==1){
        for(int i=0;i<=max-2;i++){
            printf("    %d",chu[i]);
        }
        printf("    %d\n",num[0]);
        return;
    }
    else{
        for(int i=0;i<=n-1;i++){
            int* arr=(int*)malloc(sizeof(int)*(n-1));
            reverse(arr,num,n,i);
            int* achu=(int*)malloc(sizeof(int)*max);
            update(achu,chu,num,max,i);
            print(arr,achu,n-1,max);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int* num=(int*)malloc(sizeof(int)*n);
    int* chu=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<=n-1;i++){
        num[i]=i+1;
        chu[i]=0;
    }
    print(num,chu,n,n);
}
