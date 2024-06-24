#include <stdio.h>
#include <stdlib.h>
void print(int num[],int len){
    for(int i=0;i<=(len-1)/2;i++){
        int mid=num[i];
        num[i]=num[len-i-1];
        num[len-i-1]=mid;
    }
    int i=0;
    while(num[i]==0){
        i++;
    }
    for(int j=i;j<=len-1;j++){
        printf("%d",num[j]);
    }
}
int main()
{
    char number[50];
    int num[50],i,len;
    gets(number);
    len=strlen(number);
    if(number[0]=='0'){
        printf("0");
    }
    else if(number[0]=='-'){
        for(i=1;i<=len-1;i++){
            num[i-1]=number[i]-'0';
        }
        len--;
        printf("-");
        print(num,len);
    }
    else{
        for(i=0;i<=len-1;i++){
            num[i]=number[i]-'0';
        }
        print(num,len);
    }
}
