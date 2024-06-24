#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[10],yu[42]={0},ans;
    for(int i=0;i<=9;i++){
        scanf("%d",&num[i]);
        yu[num[i]%42]++;
    }
    ans=0;
    for(int i=0;i<=41;i++){
        if(yu[i]!=0){
            ans++;
        }
    }
    printf("%d",ans);
}
