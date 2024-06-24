#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char num[20][10]={0};
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++){
        scanf("%s",num[i]);
    }
    print(num,n);
}
void print(char num[20][10],int n){
    while(n>0){
        picknum(num,n);
        n--;
    }
}
void picknum(char num[20][10],int n){
    char tmp[20][10];
    for(int i=0;i<=n-1;i++){
        strcpy(tmp[i],num[i]);
    }
    int t=n;
    char max[10]={0};
    for(int i=0;i<=9;i++){
        int count=0;
        for(int k=0;k<t;k++){
            if(tmp[k][i]>max[i]){
                max[i]=tmp[k][i];
            }
        }
        int j;
        for(j=0;j<t;j++){
            if(tmp[j][i]==max[i]){
                strcpy(tmp[count],tmp[j]);
                count++;
            }
        }
        if (count==1){
            reverse(num,n,tmp[0]);
            printf("%s",tmp[0]);
            return;
        }
        else{
            t=count+1;
        }

    }
}
void reverse(char num[20][10],int n,char q[10]){
    int j=0;
    for(int i=0;i<n;i++){
        if(strcmp(num[i],q)==0){
            j=i;
            break;
        }
    }
    for(int i=j;i<n-1;i++){
        strcpy(num[i],num[i+1]);
    }
}
